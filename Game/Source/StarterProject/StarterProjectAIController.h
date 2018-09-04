// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
struct FBehaviorTreeInstanceData
{
	GENERATED_USTRUCT_BODY()

	//UPROPERTY()
	//TArray<uint8> InstanceMemory;

	UPROPERTY()
	TSet<uint16> AuxiliaryNodeInds;

	UPROPERTY()
	int32 CurrentExeIndex;
	/*
	active aux nodes

	parralleltasks

	activenode

	activenodetype
	*/
};

USTRUCT()
struct FBehaviorTreeInstanceIdData
{
	GENERATED_USTRUCT_BODY()
};

USTRUCT()
struct FUBTNodeData
{
	GENERATED_USTRUCT_BODY()

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

	/*
	UPROPERTY()
	TArray<FBehaviorTreeInstanceIdData> KnownInstances;

	UPROPERTY()
	TArray<FUBTNodeData> NodeInstances;
	*/
	UPROPERTY()
	uint16 ActiveInstanceIdx;

	UPROPERTY()
	uint8 bDeferredStopTree : 1;
	UPROPERTY()
	uint8 bWaitingForAbortingTasks : 1;
	UPROPERTY()
	uint8 bRequestedFlowUpdate : 1;
	UPROPERTY()
	uint8 bIsRunning : 1;
	UPROPERTY()
	uint8 bIsPaused : 1;
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

	FBehaviorTreeInstanceData& HandoverBTInstanceData(int Idx);

	virtual void Destroyed() override;
	virtual void Tick(float DeltaTime) override;

	EBlackboardNotificationResult OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID);
	void UpdateBlackboardHandover(const UBlackboardComponent& Blackboard, FBlackboard::FKey KeyID);
	void UpdateBehaviorTreeHandover();

	void OnSpatialAuthorityChange(int AuthChangeOp) override;

	virtual bool RunBehaviorTree(UBehaviorTree* BTAsset) override;

	UFUNCTION(BlueprintCallable)
	void SwitchExecution(int32 ChildIndex, int32 InstanceIdx=0);

protected:
	virtual bool InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset) override;

};
