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
#include "BehaviorTree/BTNode.h"

void AStarterProjectAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Ideally this would be removed and only called from AuthChangeOp == 2, but this need soft authority loss time > 0 and has chance of losing data
	// So we sync on every tick
	if (BrainComponent->IsRunning() && bShouldUpdateHandover)
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
		UpdateBehaviorTreeHandover();
		bShouldUpdateHandover = false;
	}
	else if (AuthChangeOp == 1)
	{
		bShouldUpdateHandover = true;
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
			if (!BT->bStartRootNode)  // Don't run handover logic on initial spawn
			{
				int InstanceNums = AIControllerHandover.BehaviorTreeInfo.InstanceStack.Num();
				if (InstanceNums > 0)
				{
					BT->ResetTreeForHandover(AIControllerHandover.BehaviorTreeInfo.TreeAssets);  // Reset and sync BT instances


					// TODO:
					/* 
					test test test -- how do I validate dynamic behavior tree handover?
					make AI chase player past boundary?
					
					
					*/



					for (int InstanceNum = 0; InstanceNum < InstanceNums; InstanceNum++)
					{
						FBehaviorTreeInstance* CurrInstance = BT->GetInstance(InstanceNum);
						if (!CurrInstance) break;

						CurrInstance->InstanceMemory = HandoverBTInstanceData(InstanceNum).InstanceMemory;

						// Set active node of all trees.
						CurrInstance->ActiveNode = CurrInstance->GetNodeByExecutionIndex(HandoverBTInstanceData(InstanceNum).CurrentExeIndex);
						CurrInstance->ActiveNodeType = HandoverBTInstanceData(InstanceNum).ActiveNodeType;
						
						for (auto AuxNodeIdx : HandoverBTInstanceData(InstanceNum).AuxiliaryNodeIdxs)
						{
							UBTAuxiliaryNode* AuxNode = Cast<UBTAuxiliaryNode>(CurrInstance->GetNodeByExecutionIndex(AuxNodeIdx));
							if (AuxNode)
							{
								//UE_LOG(LogTemp, Log, TEXT("Syncing aux node: %s"), *AuxNode->NodeName);
								CurrInstance->ActiveAuxNodes.Add(AuxNode);
								uint8* NodeMemory = (uint8*)AuxNode->GetNodeMemory<uint8>(*CurrInstance);
								AuxNode->WrappedOnBecomeRelevant(*BT, NodeMemory);
							}
							else
							{
								UE_LOG(LogTemp, Warning, TEXT("Aux node (execution index: %d) not found in instance %d"), AuxNodeIdx, InstanceNum);
							}
						}

						for (auto ParallelTaskData : HandoverBTInstanceData(InstanceNum).ParallelTasks)
						{

							// Copied from RegisterParallelTasks
							// Modified as we may need to add tasks to background BT instances
							const UBTTaskNode* TaskNode = Cast<UBTTaskNode>(CurrInstance->GetNodeByExecutionIndex(ParallelTaskData.TaskNodeIdx));
							if (TaskNode)
							{
								CurrInstance->ParallelTasks.Add(FBehaviorTreeParallelTask(TaskNode, ParallelTaskData.Status));

								UE_LOG(LogBehaviorTree, Verbose, TEXT("Parallel task: %s restored after handover to instance %d"),
									*UBehaviorTreeTypes::DescribeNodeHelper(TaskNode), InstanceNum);

								if (CurrInstance->ActiveNode == TaskNode)
								{
									// switch to inactive state, so it could start background tree
									CurrInstance->ActiveNodeType = EBTActiveNode::InactiveTask;
								}
							}
							else
							{
								UE_LOG(LogBehaviorTree, Warning, TEXT("Parallel Task node (execution index: %d) not found in instance %d"), ParallelTaskData.TaskNodeIdx, InstanceNum);
							}
						}
					}

					// Brute force comparison to match instance nodes
					for (auto InstancedNode : BT->GetNodeInstances())
					{
						for (auto SavedInstancedNode : AIControllerHandover.BehaviorTreeInfo.NodeInstances)
						{
							if (InstancedNode->GetTreeAsset() == SavedInstancedNode.TreeAsset
								&& InstancedNode->GetExecutionIndex() == SavedInstancedNode.ExecutionIndex)
							{
								// If match found, update the Memory Offset to match data before handover
								// This, along with copying over the BTInstance memory block, ensures that the new tree memory lines up with the old one
								InstancedNode->InitializeNode(InstancedNode->GetParentNode(), InstancedNode->GetExecutionIndex(), SavedInstancedNode.MemoryOffset, InstancedNode->GetTreeDepth());
							}
						}
					}

					// Start execution of current tree; trigger search for child task node if ActiveNode is composite node
					SwitchExecution(HandoverBTInstanceData(InstanceNums-1).CurrentExeIndex, InstanceNums - 1);
					UE_LOG(LogTemp, Log, TEXT("Resuming BT instance %d at execution step %d"), InstanceNums - 1, HandoverBTInstanceData(InstanceNums-1).CurrentExeIndex);
				}
				
				BT->bStartRootNode = true;  // Re-enable spawning subtrees
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
		AIControllerHandover.BehaviorTreeInfo.TreeAssets.SetNum(BT->GetInstanceNum());
		for (int InstanceNum=0; InstanceNum<BT->GetInstanceNum(); InstanceNum++)
		{
			FBehaviorTreeInstance* Instance = BT->GetInstance(InstanceNum);
			HandoverBTInstanceData(InstanceNum).InstanceMemory = Instance->InstanceMemory;

			if (const UBTNode* ActiveNode = Instance->ActiveNode)
			{
				HandoverBTInstanceData(InstanceNum).CurrentExeIndex = ActiveNode->GetExecutionIndex();
				HandoverBTInstanceData(InstanceNum).ActiveNodeType = Instance->ActiveNodeType;
			}

			for (auto AuxNode : Instance->ActiveAuxNodes)
			{
				// Since it's a set, we can just Add without duplicates
				HandoverBTInstanceData(InstanceNum).AuxiliaryNodeIdxs.Add(AuxNode->GetExecutionIndex());
			}

			// For custom structs, however, TSet doesn't work
			HandoverBTInstanceData(InstanceNum).ParallelTasks.Reset();
			for (auto ParallelTask : Instance->ParallelTasks)
			{
				FBehaviorTreeParallelTaskData TaskData = {ParallelTask.TaskNode->GetExecutionIndex(), ParallelTask.Status};
				HandoverBTInstanceData(InstanceNum).ParallelTasks.Add(TaskData);
			}

			AIControllerHandover.BehaviorTreeInfo.TreeAssets[InstanceNum] = BT->GetKnownInstance(InstanceNum).TreeAsset;
		}

		AIControllerHandover.BehaviorTreeInfo.NodeInstances.Reset();
		for (auto InstancedNode : BT->GetNodeInstances())
		{
			FBTNodeData NodeData = {InstancedNode->GetTreeAsset(), InstancedNode->GetExecutionIndex(), InstancedNode->GetMemoryOffset()};
			AIControllerHandover.BehaviorTreeInfo.NodeInstances.Add(NodeData);
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
	bool bStartRootNode = true;
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
			// Initialize tree as normal, but don't start execution at root (instead wait for handover)
			bStartRootNode = false;
		}
	}

	// Copied from AIController::RunBehaviorTree
	if (BTAsset == NULL)
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("RunBehaviorTree: Unable to run NULL behavior tree"));
		return false;
	}

	bool bSuccess = true;
	bool bShouldInitializeBlackboard = false;

	// see if need a blackboard component at all
	UBlackboardComponent* BlackboardComp = Blackboard;
	if (BTAsset->BlackboardAsset && (Blackboard == nullptr || Blackboard->IsCompatibleWith(BTAsset->BlackboardAsset) == false))
	{
		bSuccess = UseBlackboard(BTAsset->BlackboardAsset, BlackboardComp);
	}

	if (bSuccess)
	{
		UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(BrainComponent);
		if (BTComp == NULL)
		{
			UE_LOG(LogBehaviorTree, Log, TEXT("RunBehaviorTree: spawning BehaviorTreeComponent.."));

			BTComp = NewObject<UBehaviorTreeComponent>(this, TEXT("BTComponent"));
			BTComp->RegisterComponent();
		}

		// make sure BrainComponent points at the newly created BT component
		BrainComponent = BTComp;

		check(BTComp != NULL);
		BTComp->bStartRootNode = bStartRootNode; /* IMPROBABLE-CHANGE */
		BTComp->StartTree(*BTAsset, EBTExecutionMode::Looped);
	}

	return bSuccess;
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
