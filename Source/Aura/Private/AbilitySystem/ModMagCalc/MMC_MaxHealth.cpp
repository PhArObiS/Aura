// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

// Constructor implementation
UMMC_MaxHealth::UMMC_MaxHealth()
{
	// Define which attribute to capture (Vigor)
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	// Define that the attribute source is the target of the gameplay effect
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	// Do not use snapshotting; capture the attribute value dynamically
	VigorDef.bSnapshot = false;

	// Add the Vigor attribute to the list of attributes to capture
	RelevantAttributesToCapture.Add(VigorDef);
}

// CalculateBaseMagnitude_Implementation calculates the base value for the gameplay effect
float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from the source and target of the effect
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// Set up parameters for evaluating the attribute
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	// Initialize Vigor to 0
	float Vigor = 0.f;
	// Get the captured magnitude of the Vigor attribute
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvaluationParameters, Vigor);
	// Ensure Vigor is non-negative
	Vigor = FMath::Max<float>(Vigor, 0.f);

	// Get the combat interface from the source object to access player level
	int32 PlayerLevel = 1;
	if (Spec.GetContext().GetSourceObject()->Implements<UCombatInterface>())
	{
		PlayerLevel = ICombatInterface::Execute_GetPlayerLevel(Spec.GetContext().GetSourceObject());
	}

	// Calculate the base magnitude using the formula: 80 + 2.5 * Vigor + PlayerLevel
	return 80.f + 2.5f * Vigor + 10.f * PlayerLevel;
}
