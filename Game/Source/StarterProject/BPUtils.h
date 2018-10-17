// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPUtils.generated.h"

/**
 * 
 */
UCLASS()
class STARTERPROJECT_API UBPUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BPUtils")
	static void Sleep(float Seconds);
	
};
