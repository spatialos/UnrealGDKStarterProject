// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActorWithChildren.h"

#include "Components/ChildActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ATestActorWithChildren::ATestActorWithChildren()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetReplicates(true);

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneComponent);

	StaticMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh1"));
	StaticMesh1->SetupAttachment(SceneComponent);

	StaticMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh2"));
	StaticMesh2->SetupAttachment(SceneComponent);

	ChildActor1 = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActor1"));
	ChildActor1->SetupAttachment(SceneComponent);

	ChildActor2 = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActor2"));
	ChildActor2->SetupAttachment(SceneComponent);
}


