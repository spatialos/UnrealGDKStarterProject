// Fill out your copyright notice in the Description page of Project Settings.

#include "StarterProjectAIController.h"
#include "EntityId.h"
#include "SpatialNetDriver.h"
#include "EntityRegistry.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BTAuxiliaryNode.h"

void AStarterProjectAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Ideally this would be moved to before authorityloss so it only happens once before handover
	// need soft authority loss time > 0
	if (BrainComponent->IsRunning())
	{
		UpdateBehaviorTreeHandover();
	}
}

bool AStarterProjectAIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bSuccess = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);

	// We might want to initialize handover data here, but it seems there are race conditions where we don't receive updated handover data from spatial yet
	// Maybe we should pause blackboard logic until we receive handover data below
	return bSuccess;
}

void AStarterProjectAIController::OnSpatialAuthorityChange(int AuthChangeOp)
{
	if (AuthChangeOp == 2)
	{
		//BrainComponent->PauseLogic(TEXT("About to lose spatial authority"));
		UE_LOG(LogTemp, Log, TEXT("exe step before authority loss: %d"), HandoverBTInstanceData(0).CurrentExeIndex);
	}
	else if (AuthChangeOp == 1)
	{
		if (Blackboard != nullptr)
		{
			UBlackboardData* BlackboardAsset = Blackboard->GetBlackboardAsset();
			const int32 NumKeys = BlackboardAsset->GetNumKeys();

			for (UBlackboardData* It = BlackboardAsset; It; It = It->Parent)
			{
				for (int32 KeyIndex = 0; KeyIndex < It->Keys.Num(); KeyIndex++)
				{
					FBlackboardEntry Key = It->Keys[KeyIndex];
					FName KeyName = Key.EntryName;
					FBlackboard::FKey KeyID = Blackboard->GetKeyID(KeyName);
					UE_LOG(LogTemp, Log, TEXT("KeyName: %s, ID: %d"), *KeyName.ToString(), KeyID);

					FBlackboardKeyData DataRef = AIControllerHandover.BlackboardKeyValues.FindRef(KeyID);
					if (DataRef.ValueSize > 0)  // Handover data present
					{
						// Modified from UBlackboardComponent::PopularizeSynchronizedKeys
						// TODO: make a flag inside FBlackboardEntry, similar to bIsInstanceSynced, that dictates whether we should hand it over

						const uint16 DataOffset = Key.KeyType->IsInstanced() ? sizeof(FBlackboardInstancedKeyMemory) : 0;
						uint8* RawData = Blackboard->GetKeyRawData(KeyID) + DataOffset;

						// Native unreal only have setter functions for typed keys SetValueAs[Object/Class/Bool/etc.], so we would need a switch statement which is ugly
						// Memcpy is cleaner, so long as we get the correct key memory location. This essentially implements SetValueAs
						FMemory::Memcpy(RawData, DataRef.ValueMemory.GetData(), Key.KeyType->GetValueSize());
					}

					Blackboard->RegisterObserver(KeyID, this, FOnBlackboardChangeNotification::CreateUObject(this, &AStarterProjectAIController::OnBlackboardKeyValueChange));
					UpdateBlackboardHandover(*Blackboard, KeyID);  // Trigger handover data update manually
				}
			}
		}

		if (UBehaviorTreeComponent* BT = Cast<UBehaviorTreeComponent>(BrainComponent))
		{
			BT->ClearBeforeHandover();
			for (int i=0; i < AIControllerHandover.BehaviorTreeInfo.InstanceStack.Num(); i++)
			{
				for (auto AuxNodeIdx : HandoverBTInstanceData(i).AuxiliaryNodeInds)
				{
					UBTAuxiliaryNode* AuxNode = Cast<UBTAuxiliaryNode>(BT->GetInstance(i)->GetNodeByExecutionIndex(AuxNodeIdx));
					if (AuxNode)
					{
						UE_LOG(LogTemp, Log, TEXT("Syncing aux node: %s"), *AuxNode->NodeName);
						BT->GetInstance(i)->ActiveAuxNodes.Add(AuxNode);
						uint8* NodeMemory = (uint8*)AuxNode->GetNodeMemory<uint8>(i);
						AuxNode->WrappedOnBecomeRelevant(*BT, NodeMemory);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Aux node (idx: %d) not found in instance %d"), AuxNodeIdx, i);
					}
				}

				UE_LOG(LogTemp, Log, TEXT("Resuming BT instance %d at execution step %d"), i, HandoverBTInstanceData(i).CurrentExeIndex);
				SwitchExecution(HandoverBTInstanceData(i).CurrentExeIndex, i);
			}
		}
	}

	Super::OnSpatialAuthorityChange(AuthChangeOp);
}

void AStarterProjectAIController::UpdateBlackboardHandover(const UBlackboardComponent& Blackboard, FBlackboard::FKey KeyID)
{
	FBlackboardKeyData& DataRef = AIControllerHandover.BlackboardKeyValues.FindOrAdd(KeyID);
	const uint8* DataRaw = Blackboard.GetKeyRawData(KeyID);
	uint16 DataSize = Blackboard.GetBlackboardAsset()->GetKey(KeyID)->KeyType->GetValueSize();

	DataRef.ValueSize = DataSize;
	DataRef.ValueMemory = TArray<uint8>(DataRaw, DataSize);
}

FBehaviorTreeInstanceData& AStarterProjectAIController::HandoverBTInstanceData(int Idx)
{
	return AIControllerHandover.BehaviorTreeInfo.InstanceStack[Idx];
}


void AStarterProjectAIController::UpdateBehaviorTreeHandover()
{
	if (UBehaviorTreeComponent* BT = Cast<UBehaviorTreeComponent>(BrainComponent))
	{
		AIControllerHandover.BehaviorTreeInfo.InstanceStack.SetNum(BT->GetInstanceNum());
		for (int i=0; i<BT->GetInstanceNum(); i++)
		{
			FBehaviorTreeInstance* Instance = BT->GetInstance(i);
			if (const UBTNode* ActiveNode = Instance->ActiveNode)
			{
				//UE_LOG(LogTemp, Log, TEXT("active node: %s"), *ActiveNode->NodeName);
				HandoverBTInstanceData(i).CurrentExeIndex = ActiveNode->GetExecutionIndex();
			}

			for (auto AuxNode : Instance->ActiveAuxNodes)
			{
				//UE_LOG(LogTemp, Log, TEXT("aux node: %s"), *AuxNode->NodeName);
				HandoverBTInstanceData(i).AuxiliaryNodeInds.Add(AuxNode->GetExecutionIndex());
			}
		}
	}
}

EBlackboardNotificationResult AStarterProjectAIController::OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID)
{
	UE_LOG(LogTemp, Log, TEXT("Custom AIController Handover Data observer: keyID %d changed: %s"), ChangedKeyID, *Blackboard.DescribeKeyValue(ChangedKeyID, EBlackboardDescription::Type::Full));
	UBehaviorTreeComponent* BehaviorComp = (UBehaviorTreeComponent*)Blackboard.GetBrainComponent();
	if (BehaviorComp == nullptr)
	{
		return EBlackboardNotificationResult::RemoveObserver;
	}

	UpdateBlackboardHandover(Blackboard, ChangedKeyID);

	return EBlackboardNotificationResult::ContinueObserving;
}


bool AStarterProjectAIController::RunBehaviorTree(UBehaviorTree* BTAsset)
{
	bool res = Super::RunBehaviorTree(BTAsset);

	// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	// Wait to execute behavior tree until we receive handover data
	UWorld* World = GetWorld();
	check(World);
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	if (NetDriver)
	{
		const FEntityId EntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(this);
		UE_LOG(LogTemp, Log, TEXT("AIPawn:SpawnDefaultController called with entity id %d"), EntityId.ToSpatialEntityId());
		if (EntityId != 0)
		{
			// EntityId is not 0, which means that this AI controller has already been initialized.
			// Pause so that we still initialize our tree but don't run any actions
			//BrainComponent->PauseLogic(TEXT("Waiting for spatial authority"));
			
		}
	}

	return res;
}


void AStarterProjectAIController::SwitchExecution(int32 IndexToExecute, int32 InstanceIdx)
{
	if (UBehaviorTreeComponent* BT = Cast<UBehaviorTreeComponent>(BrainComponent))
	{
		UBTNode* TargetNode = BT->GetInstance(InstanceIdx)->GetNodeByExecutionIndex(IndexToExecute);
		if (!TargetNode)
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to find node %d in instance %d"), IndexToExecute, InstanceIdx);
			return;
		}
		UBTCompositeNode* ContainingNode = Cast<UBTCompositeNode>(TargetNode);
		if (ContainingNode == nullptr)
		{
			ContainingNode = TargetNode->GetParentNode();
		}


		if (TargetNode->GetExecutionIndex() == IndexToExecute)
		{
			UE_LOG(LogTemp, Warning, TEXT("Switching execution to: %s"), *TargetNode->NodeName);
			
			BT->RequestExecution(ContainingNode, InstanceIdx, TargetNode, ContainingNode->GetChildIndex(*TargetNode), EBTNodeResult::Aborted);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("IndexToExecute %d not found; last found node: %s with index %d"), IndexToExecute, *ContainingNode->GetName(), ContainingNode->GetExecutionIndex());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BehaviorTree not found on SwitchExecution call"));
	}
}

void AStarterProjectAIController::Destroyed()
{
	UE_LOG(LogTemp, Log, TEXT("%s being destroyed"), *this->GetName());
	Super::Destroyed();
}
