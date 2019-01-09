// Fill out your copyright notice in the Description page of Project Settings.

#include "Companion.h"


// Sets default values
ACompanion::ACompanion()
	: FollowDistance(50.0f)
	, FollowSpeed(1.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);
	SetReplicateMovement(true);

	MyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	SetRootComponent(MyRoot);
}

// Called when the game starts or when spawned
void ACompanion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompanion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Role == ROLE_Authority && GetOwner())
	{
		NavigateToOwner(DeltaTime);
	}
}

void ACompanion::NavigateToOwner(float DeltaTime)
{
	AActor* TargetActor = GetOwner();
	check(TargetActor);

	FVector TargetLocation = TargetActor->GetActorLocation();
	if (FollowTarget != nullptr)
	{
		TargetLocation = FollowTarget->GetComponentLocation();
	}

	FVector ToTarget = TargetLocation - GetActorLocation();
	SetActorRotation(FQuat::FindBetweenVectors(FQuat::Identity.GetForwardVector(), ToTarget));

	if (ToTarget.SizeSquared() < FollowDistance * FollowDistance)
	{
		return;
	}

	float Distance = ToTarget.Size();
	ToTarget *= (Distance - FollowDistance) / Distance;
	FVector MoveDest = GetActorLocation() + (0.5 * DeltaTime * FollowSpeed * ToTarget);

	SetActorLocation(MoveDest, true);
}

