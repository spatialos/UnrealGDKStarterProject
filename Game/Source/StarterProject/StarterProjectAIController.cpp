// Fill out your copyright notice in the Description page of Project Settings.

#include "StarterProjectAIController.h"


bool AStarterProjectAIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bSuccess = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);

	// We might want to initialize handover data here, but it seems there are race conditions where we don't receive updated handover data from spatial yet
	return bSuccess;
}

void AStarterProjectAIController::OnSpatialAuthorityChange(int AuthChangeOp)
{
	if (AuthChangeOp == 1 && Blackboard != nullptr)
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
					UE_LOG(LogTemp, Log, TEXT("Handing over blackboard keys."));
					// Modified from UBlackboardComponent::PopularizeSynchronizedKeys
					// TODO: make a flag inside FBlackboardEntry, similar to bIsInstanceSynced, that dictates whether we should hand it over

					const uint16 DataOffset = Key.KeyType->IsInstanced() ? sizeof(FBlackboardInstancedKeyMemory) : 0;
					uint8* RawData = Blackboard->GetKeyRawData(KeyID) + DataOffset;

					// Native unreal only have setter functions for typed keys SetValueAs[Object/Class/Bool/etc.], so we would need a switch statement which is ugly
					// Memcpy is cleaner, so long as we get the correct key memory location. This essentially implements SetValueAs
					FMemory::Memcpy(RawData, DataRef.ValueMemory.GetData(), Key.KeyType->GetValueSize());
				}

				Blackboard->RegisterObserver(KeyID, this, FOnBlackboardChangeNotification::CreateUObject(this, &AStarterProjectAIController::OnBlackboardKeyValueChange));
				UpdateAIHandover(*Blackboard, KeyID);  // Trigger handover data update manually
			}
		}
	}
}

void AStarterProjectAIController::UpdateAIHandover(const UBlackboardComponent& Blackboard, FBlackboard::FKey KeyID)
{
	FBlackboardKeyData& DataRef = AIControllerHandover.BlackboardKeyValues.FindOrAdd(KeyID);
	const uint8* DataRaw = Blackboard.GetKeyRawData(KeyID);
	uint16 DataSize = Blackboard.GetBlackboardAsset()->GetKey(KeyID)->KeyType->GetValueSize();

	DataRef.ValueSize = DataSize;
	DataRef.ValueMemory = TArray<uint8>(DataRaw, DataSize);
}

EBlackboardNotificationResult AStarterProjectAIController::OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID)
{
	UE_LOG(LogTemp, Log, TEXT("Custom AIController Handover Data observer: keyID %d changed: %s"), ChangedKeyID, *Blackboard.DescribeKeyValue(ChangedKeyID, EBlackboardDescription::Type::Full));
	UBehaviorTreeComponent* BehaviorComp = (UBehaviorTreeComponent*)Blackboard.GetBrainComponent();
	if (BehaviorComp == nullptr)
	{
		return EBlackboardNotificationResult::RemoveObserver;
	}

	UpdateAIHandover(Blackboard, ChangedKeyID);

	return EBlackboardNotificationResult::ContinueObserving;
}

void AStarterProjectAIController::Destroyed()
{
	UE_LOG(LogTemp, Log, TEXT("%s being destroyed"), *this->GetName());
	Super::Destroyed();
}
