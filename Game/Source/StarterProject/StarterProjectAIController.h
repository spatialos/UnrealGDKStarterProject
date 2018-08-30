// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "StarterProjectAIController.generated.h"

/**
 * 
 */

USTRUCT()
struct FBlackboardKeyData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<uint8> ValueMemory;

	UPROPERTY()
	uint16 ValueSize;

	FBlackboardKeyData() : ValueSize(0) {}
};


USTRUCT()
struct FHandoverAIData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<uint8, FBlackboardKeyData> BlackboardKeyValues;  // UHT fails on FBlackboard::FKey: does not support namespaces in UStruct (http://api.unrealengine.com/INT/Programming/Development/CodingStandard/index.html#namespaces)
};


UCLASS(SpatialType=ServerOnly)
class STARTERPROJECT_API AStarterProjectAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(Handover)
	FHandoverAIData AIControllerHandover;

	virtual void Destroyed() override;

	EBlackboardNotificationResult OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID);
	void UpdateAIHandover(const UBlackboardComponent& Blackboard, FBlackboard::FKey KeyID);

	void OnSpatialAuthorityChange(int AuthChangeOp) override;

protected:
	virtual bool InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset) override;

};
