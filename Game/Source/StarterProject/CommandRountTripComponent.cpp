// Fill out your copyright notice in the Description page of Project Settings.

#include "CommandRountTripComponent.h"

#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"


UCommandRoundTripComponent::UCommandRoundTripComponent()
	: PrintInterval(5.0f)
	, TimeSinceLastPrint(0.0f)
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}


void UCommandRoundTripComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TimeSinceLastPrint += DeltaTime;

	if (GetOwner())
	{
		if (GetNetMode() == NM_Client && GetOwner()->Role == ROLE_AutonomousProxy && TimeSinceLastPrint > PrintInterval)
		{
			FString Message = FString::Printf(TEXT("Client Tells: %6d, Server Tells %6d"), ClientTells, ServerTells);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, PrintInterval, FColor::Cyan, Message);
			}
			UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
			TimeSinceLastPrint = 0;
		}

		if (GetNetMode() == NM_DedicatedServer && GetOwner()->Role == ROLE_Authority)
		{
			TellClientSomething();
		}
		if (GetNetMode() == NM_Client && GetOwner()->Role == ROLE_AutonomousProxy)
		{
			TellServerSomething();
		}
	}
}

void UCommandRoundTripComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCommandRoundTripComponent, ServerTells);
}

void UCommandRoundTripComponent::TellClientSomething_Implementation()
{
	++ClientTells;
}

void UCommandRoundTripComponent::TellServerSomething_Implementation()
{
	++ServerTells;
}

bool UCommandRoundTripComponent::TellServerSomething_Validate()
{
	return true;
}

