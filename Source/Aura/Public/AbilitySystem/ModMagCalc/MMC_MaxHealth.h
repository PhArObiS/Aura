// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * UMMC_MaxHealth class calculates the maximum health based on the player's Vigor attribute and level.
 */
UCLASS()
class AURA_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	// Constructor
	UMMC_MaxHealth();

	// Override of the base class method to calculate the base magnitude of the gameplay effect
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	// Definition of the Vigor attribute to be captured
	FGameplayEffectAttributeCaptureDefinition VigorDef;
};
