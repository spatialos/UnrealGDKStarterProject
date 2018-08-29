// Fill out your copyright notice in the Description page of Project Settings.

#include "StarterProjectAIController.h"


bool AStarterProjectAIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bSuccess = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);
	
	if (bSuccess) {
		const int32 NumKeys = BlackboardAsset.GetNumKeys();

		for (UBlackboardData* It = &BlackboardAsset; It; It = It->Parent)
		{
			for (int32 KeyIndex = 0; KeyIndex < It->Keys.Num(); KeyIndex++)
			{
				FName KeyName = It->Keys[KeyIndex].EntryName;
				FBlackboard::FKey KeyID = Blackboard->GetKeyID(KeyName);
				UE_LOG(LogTemp, Log, TEXT("KeyName: %s, ID: %d"), *KeyName.ToString(), KeyID);
				
				//FBlackboardKeyData& DataRef = AIControllerHandover.BlackboardKeyValues.FindByKey(KeyID);

				Blackboard->RegisterObserver(KeyID, this, FOnBlackboardChangeNotification::CreateUObject(this, &AStarterProjectAIController::OnBlackboardKeyValueChange));
			}
		}
	}

	return bSuccess;
}

EBlackboardNotificationResult AStarterProjectAIController::OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID)
{
	UE_LOG(LogTemp, Log, TEXT("custom observer: keyID %d changed: %s"), ChangedKeyID, *Blackboard.DescribeKeyValue(ChangedKeyID, EBlackboardDescription::Type::Full));
	UBehaviorTreeComponent* BehaviorComp = (UBehaviorTreeComponent*)Blackboard.GetBrainComponent();
	if (BehaviorComp == nullptr)
	{
		return EBlackboardNotificationResult::RemoveObserver;
	}

	FBlackboardKeyData& DataRef = AIControllerHandover.BlackboardKeyValues.FindOrAdd(ChangedKeyID);
	const uint8* DataRaw = Blackboard.GetKeyRawData(ChangedKeyID);
	uint16 DataSize = Blackboard.GetBlackboardAsset()->GetKey(ChangedKeyID)->KeyType->GetValueSize();

	DataRef.ValueSize = DataSize;
	DataRef.ValueMemory = TArray<uint8>(DataRaw, DataSize);

	return EBlackboardNotificationResult::ContinueObserving;
}

void AStarterProjectAIController::Destroyed()
{
	UE_LOG(LogTemp, Log, TEXT("%s being destroyed"), *this->GetName());
	Super::Destroyed();
}
