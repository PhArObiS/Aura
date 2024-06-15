// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
public:
	UMMC_MaxMana();
	
	// Override of the base class method to calculate the base magnitude of the gameplay effect
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	// Definition of the Vigor attribute to be captured
	FGameplayEffectAttributeCaptureDefinition IntDef;
};
