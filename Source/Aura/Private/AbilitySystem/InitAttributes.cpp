// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/InitAttributes.h"
#include "AbilitySystem/AuraAttributeSet.h"

UInitAttributes::UInitAttributes()
{
	// Duration policy 
	DurationPolicy = EGameplayEffectDurationType::Instant;

	// Attribute modifiers
	FGameplayModifierInfo HealthModifier;
	HealthModifier.Attribute = UAuraAttributeSet::GetHealthAttribute();
	HealthModifier.ModifierOp = EGameplayModOp::Override;
	HealthModifier.ModifierMagnitude = FScalableFloat(100.f);

	FGameplayModifierInfo MaxHealthModifier;
	MaxHealthModifier.Attribute = UAuraAttributeSet::GetMaxHealthAttribute();
	MaxHealthModifier.ModifierOp = EGameplayModOp::Override;
	MaxHealthModifier.ModifierMagnitude = FScalableFloat(100.f);

	Modifiers.Add(HealthModifier);
	Modifiers.Add(MaxHealthModifier);
}
