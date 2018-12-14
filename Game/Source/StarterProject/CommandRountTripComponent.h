// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CommandRountTripComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTERPROJECT_API UCommandRoundTripComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCommandRoundTripComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION(Server, Reliable, WithValidation)
	void TellServerSomething();

	UFUNCTION(Client, Reliable)
	void TellClientSomething();

	UPROPERTY(VisibleAnywhere, Category = "Spatial Testing")
	int32 ClientTells;

	UPROPERTY(VisibleAnywhere, Replicated, Category = "Spatial Testing")
	int32 ServerTells;

	UPROPERTY(EditDefaultsOnly, Category = "Spatial Testing")
	float PrintInterval;

	float TimeSinceLastPrint;
	
};
