// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	// Define which attribute to capture (IntDef)
	IntDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	// Define that the attribute source is the target of the gameplay effect
	IntDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	// Do not use snapshotting; capture the attribute value dynamically
	IntDef.bSnapshot = false;

	// Add the IntDef attribute to the list of attributes to capture
	RelevantAttributesToCapture.Add(IntDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from the source and target of the effect
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// Set up parameters for evaluating the attribute
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	// Initialize Intelligence to 0
	float Int = 0.f;
	// Get the captured magnitude of the Intelligence attribute
	GetCapturedAttributeMagnitude(IntDef, Spec, EvaluationParameters, Int);
	// Ensure Vigor is non-negative
	Int = FMath::Max<float>(Int, 0.f);

	// Get the combat interface from the source object to access player level
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	// Calculate the base magnitude using the formula: 80 + 2.5 * Intelligence + PlayerLevel
	return 80.f + 2.5f * Int + 15.f * PlayerLevel;
}
