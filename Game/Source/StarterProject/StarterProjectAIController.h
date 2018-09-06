// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BehaviorTree.h"
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
struct FBehaviorTreeParallelTaskData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	uint16 TaskNodeIdx;

	UPROPERTY()
	TEnumAsByte<EBTTaskStatus::Type> Status;
};

USTRUCT()
struct FBehaviorTreeInstanceData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<uint8> InstanceMemory;

	UPROPERTY()
	TSet<uint16> AuxiliaryNodeIdxs;

	UPROPERTY()
	int32 CurrentExeIndex;  // Uniquely identifies ActiveNode
	
	UPROPERTY()
	TArray<FBehaviorTreeParallelTaskData> ParallelTasks;

	UPROPERTY()
	TEnumAsByte<EBTActiveNode::Type> ActiveNodeType;
};

USTRUCT()
struct FBTNodeData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	UBehaviorTree* TreeAsset;

	UPROPERTY()
	uint16 ExecutionIndex;

	UPROPERTY()
	uint16 MemoryOffset;
};

USTRUCT()
struct FBehaviorTreeData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<FBehaviorTreeInstanceData> InstanceStack;

	UPROPERTY()
	TArray<UBehaviorTree*> TreeAssets;

	UPROPERTY()
	TArray<FBTNodeData> NodeInstances;

	UPROPERTY()
	uint16 ActiveInstanceIdx;
};


USTRUCT()
struct FHandoverAIData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<uint8, FBlackboardKeyData> BlackboardKeyValues;  // UHT fails on FBlackboard::FKey: does not support namespaces in UStruct (http://api.unrealengine.com/INT/Programming/Development/CodingStandard/index.html#namespaces)

	UPROPERTY()
	FBehaviorTreeData BehaviorTreeInfo;
};


UCLASS(SpatialType=ServerOnly)
class STARTERPROJECT_API AStarterProjectAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(Handover)
	FHandoverAIData AIControllerHandover;

	bool bShouldUpdateHandover;

	FBehaviorTreeInstanceData& HandoverBTInstanceData(int Idx);

	virtual void Destroyed() override;
	virtual void Tick(float DeltaTime) override;

	EBlackboardNotificationResult OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID);
	void UpdateBlackboardHandover(const UBlackboardComponent& Blackboard, FBlackboard::FKey KeyID);
	void UpdateBehaviorTreeHandover();

	UFUNCTION(BlueprintCallable)
	void OnSpatialAuthorityChange(int AuthChangeOp) override;

	virtual bool RunBehaviorTree(UBehaviorTree* BTAsset) override;

	UFUNCTION(BlueprintCallable)
	void SwitchExecution(int32 ChildIndex, int32 InstanceIdx=0);

protected:
	virtual bool InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset) override;

};
