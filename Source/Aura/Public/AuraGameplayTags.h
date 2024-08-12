// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * FAuraGameplayTags
 *
 * Singleton containing native Gameplay Tags.
 * This struct is used to manage and access gameplay tags throughout the game.
 */

struct FAuraGameplayTags
{
public:
    // Returns the singleton instance of FAuraGameplayTags.
    static const FAuraGameplayTags& Get() { return GameplayTags; }

    // Initializes native gameplay tags.
    static void InitializeNativeGameplayTags();

    // Primary Attributes
    FGameplayTag Attributes_Primary_Strength;
    FGameplayTag Attributes_Primary_Intelligence;
    FGameplayTag Attributes_Primary_Resilience;
    FGameplayTag Attributes_Primary_Vigor;

    // Secondary Attributes
    FGameplayTag Attributes_Secondary_Armor;
    FGameplayTag Attributes_Secondary_ArmorPenetration;
    FGameplayTag Attributes_Secondary_BlockChance;
    FGameplayTag Attributes_Secondary_CriticalHitChance;
    FGameplayTag Attributes_Secondary_CriticalHitDamage;
    FGameplayTag Attributes_Secondary_CriticalHitResistance;
    FGameplayTag Attributes_Secondary_HealthRegeneration;
    FGameplayTag Attributes_Secondary_ManaRegeneration;
    FGameplayTag Attributes_Secondary_MaxHealth;
    FGameplayTag Attributes_Secondary_MaxMana;

    // Meta Attributes
    FGameplayTag Attributes_Meta_IncomingXP;

    // Input Tags
    FGameplayTag InputTag_LMB;
    FGameplayTag InputTag_RMB;
    FGameplayTag InputTag_1;
    FGameplayTag InputTag_2;
    FGameplayTag InputTag_3;
    FGameplayTag InputTag_4;
    FGameplayTag InputTag_Passive_1;
    FGameplayTag InputTag_Passive_2;  // Added correct input tag

    // Damage Tags
    FGameplayTag Damage;
    FGameplayTag Damage_Fire;
    FGameplayTag Damage_Lightning;
    FGameplayTag Damage_Arcane;
    FGameplayTag Damage_Physical;

    // Debuff Tags
    FGameplayTag Debuff_Burn;
    FGameplayTag Debuff_Stun;
    FGameplayTag Debuff_Arcane;
    FGameplayTag Debuff_Physical; // Corrected typo

    FGameplayTag Debuff_Chance;
    FGameplayTag Debuff_Damage;
    FGameplayTag Debuff_Duration;
    FGameplayTag Debuff_Frequency;

    // Resistance Attributes
    FGameplayTag Attributes_Resistance_Fire;
    FGameplayTag Attributes_Resistance_Lightning;
    FGameplayTag Attributes_Resistance_Arcane;
    FGameplayTag Attributes_Resistance_Physical;

    // Ability Tags
    FGameplayTag Abilities_None;
    FGameplayTag Abilities_Attack;
    FGameplayTag Abilities_Summon;
    FGameplayTag Abilities_HitReact;

    // Ability Status Tags
    FGameplayTag Abilities_Status_Locked;
    FGameplayTag Abilities_Status_Eligible;
    FGameplayTag Abilities_Status_Unlocked;
    FGameplayTag Abilities_Status_Equipped;

    // Ability Type Tags
    FGameplayTag Abilities_Type_Offensive;
    FGameplayTag Abilities_Type_Passive;
    FGameplayTag Abilities_Type_None;

    // Specific Abilities
    FGameplayTag Abilities_Fire_FireBolt;
    FGameplayTag Abilities_Lightning_Electrocute;
    FGameplayTag Abilities_Passive_HaloOfProtection;
    FGameplayTag Abilities_Passive_LifeSiphon;
    FGameplayTag Abilities_Passive_ManaSiphon;

    // Cooldown Tags
    FGameplayTag Cooldown_Fire_FireBolt;

    // Combat Socket Tags
    FGameplayTag CombatSocket_Weapon;
    FGameplayTag CombatSocket_RightHand;
    FGameplayTag CombatSocket_LeftHand;
    FGameplayTag CombatSocket_Tail;

    // Montage Tags
    FGameplayTag Montage_Attack1;
    FGameplayTag Montage_Attack2;
    FGameplayTag Montage_Attack3;
    FGameplayTag Montage_Attack4;

    // Effects
    FGameplayTag Effects_HitReact;

    // Player Tags
    FGameplayTag Player_Block_InputPressed;
    FGameplayTag Player_Block_InputHeld;
    FGameplayTag Player_Block_InputReleased;
    FGameplayTag Player_Block_CursorTrace;

    // Maps for Damage Types to Resistances and Debuffs
    TMap<FGameplayTag, FGameplayTag> DamageTypesToResistances;
    TMap<FGameplayTag, FGameplayTag> DamageTypesToDebuffs;

private:
    // Singleton instance of FAuraGameplayTags.
    static FAuraGameplayTags GameplayTags; 
};