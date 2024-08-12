// Fill out your copyright notice in the Description page of Project Settings.

#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
    /*
     * Primary Attributes
     */
    GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Primary.Strength"),
        FString("Increases physical damage")
    );

    GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Primary.Intelligence"),
        FString("Increases magical damage")
    );

    GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Primary.Resilience"),
        FString("Increases Armor and Armor Penetration")
    );

    GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Primary.Vigor"),
        FString("Increases Health")
    );

    /*
     * Secondary Attributes
     */
    GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.Armor"),
        FString("Reduces damage taken, improves Block Chance")
    );

    GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.ArmorPenetration"),
        FString("Ignores Percentage of an enemy Armor, increases Critical Hit Chance")
    );

    GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.BlockChance"),
        FString("Chance to cut incoming damage in half")
    );

    GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.CriticalHitChance"),
        FString("Chance to double damage plus critical hit bonus")
    );

    GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.CriticalHitDamage"),
        FString("Amount of extra damage dealt on a critical hit")
    );

    GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.CriticalHitResistance"),
        FString("Reduces Critical Hit Chance of attacking enemies")
    );

    GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.HealthRegeneration"),
        FString("Amount of Health regenerated every 1 second")
    );

    GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.ManaRegeneration"),
        FString("Amount of Mana regenerated every 1 second")
    );

    GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.MaxHealth"),
        FString("Maximum amount of Health obtainable")
    );

    GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Secondary.MaxMana"),
        FString("Maximum amount of Mana obtainable")
    );

    /*
     * Meta Attributes
     */
    GameplayTags.Attributes_Meta_IncomingXP = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Meta.IncomingXP"),
        FString("IncomingXP Meta Attribute")
    );

    /*
     * Input Tags
     */
    GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.LMB"),
        FString("Input Tag for Left Mouse Button")
    );

    GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.RMB"),
        FString("Input Tag for Right Mouse Button")
    );

    GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.1"),
        FString("Input Tag for 1 Key")
    );

    GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.2"),
        FString("Input Tag for 2 Key")
    );

    GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.3"),
        FString("Input Tag for 3 Key")
    );

    GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.4"),
        FString("Input Tag for 4 Key")
    );

    GameplayTags.InputTag_Passive_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.Passive.1"),
        FString("Input Tag for Passive Ability Slot 1")
    );

    GameplayTags.InputTag_Passive_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("InputTag.Passive.2"),
        FString("Input Tag for Passive Ability Slot 2")
    );

    /*
     * Damage Tags
     */
    GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Damage"),
        FString("Base damage tag")
    );

    GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Damage.Fire"),
        FString("Fire damage type")
    );

    GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Damage.Lightning"),
        FString("Lightning damage type")
    );

    GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Damage.Arcane"),
        FString("Arcane damage type")
    );

    GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Damage.Physical"),
        FString("Physical damage type")
    );

    /*
     * Debuff Tags
     */
    GameplayTags.Debuff_Burn = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Burn"),
        FString("Burn debuff applied by Fire damage")
    );

    GameplayTags.Debuff_Stun = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Stun"),
        FString("Stun debuff")
    );

    GameplayTags.Debuff_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Arcane"),
        FString("Debuff applied by Arcane damage")
    );

    GameplayTags.Debuff_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Physical"),
        FString("Debuff applied by Physical damage")
    );

    GameplayTags.Debuff_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Chance"),
        FString("Chance to apply a debuff")
    );

    GameplayTags.Debuff_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Damage"),
        FString("Damage over time debuff")
    );

    GameplayTags.Debuff_Duration = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Duration"),
        FString("Duration of the debuff")
    );

    GameplayTags.Debuff_Frequency = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Debuff.Frequency"),
        FString("Frequency at which the debuff triggers")
    );

    /*
     * Resistance Attributes
     */
    GameplayTags.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Resistance.Fire"),
        FString("Resistance to Fire damage")
    );

    GameplayTags.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Resistance.Lightning"),
        FString("Resistance to Lightning damage")
    );

    GameplayTags.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Resistance.Arcane"),
        FString("Resistance to Arcane damage")
    );

    GameplayTags.Attributes_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Attributes.Resistance.Physical"),
        FString("Resistance to Physical damage")
    );

    /*
     * Ability Tags
     */
    GameplayTags.Abilities_None = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.None"),
        FString("Default Ability tag")
    );

    GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Attack"),
        FString("Attack Ability tag")
    );

    GameplayTags.Abilities_Summon = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Summon"),
        FString("Summon Ability tag")
    );

    GameplayTags.Abilities_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.HitReact"),
        FString("HitReact Ability tag")
    );

    /*
     * Ability Status Tags
     */
    GameplayTags.Abilities_Status_Locked = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Status.Locked"),
        FString("Ability is locked and unavailable")
    );

    GameplayTags.Abilities_Status_Eligible = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Status.Eligible"),
        FString("Ability is available to be unlocked")
    );

    GameplayTags.Abilities_Status_Unlocked = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Status.Unlocked"),
        FString("Ability is unlocked and usable")
    );

    GameplayTags.Abilities_Status_Equipped = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Status.Equipped"),
        FString("Ability is currently equipped by the player")
    );

    /*
     * Ability Type Tags
     */
    GameplayTags.Abilities_Type_Offensive = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Type.Offensive"),
        FString("Offensive ability type")
    );

    GameplayTags.Abilities_Type_Passive = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Type.Passive"),
        FString("Passive ability type")
    );

    GameplayTags.Abilities_Type_None = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Type.None"),
        FString("No specific ability type")
    );

    /*
     * Specific Abilities
     */
    GameplayTags.Abilities_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Fire.FireBolt"),
        FString("Fire Bolt Ability")
    );

    GameplayTags.Abilities_Lightning_Electrocute = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Lightning.Electrocute"),
        FString("Electrocute Ability")
    );

    GameplayTags.Abilities_Passive_HaloOfProtection = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Passive.HaloOfProtection"),
        FString("Halo of Protection Passive Ability")
    );

    GameplayTags.Abilities_Passive_LifeSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Passive.LifeSiphon"),
        FString("Life Siphon Passive Ability")
    );

    GameplayTags.Abilities_Passive_ManaSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Abilities.Passive.ManaSiphon"),
        FString("Mana Siphon Passive Ability")
    );

    /*
     * Cooldown Tags
     */
    GameplayTags.Cooldown_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Cooldown.Fire.FireBolt"),
        FString("Cooldown for Fire Bolt Ability")
    );

    /*
     * Combat Socket Tags
     */
    GameplayTags.CombatSocket_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("CombatSocket.Weapon"),
        FString("Socket for the weapon")
    );

    GameplayTags.CombatSocket_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("CombatSocket.RightHand"),
        FString("Socket for the right hand")
    );

    GameplayTags.CombatSocket_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("CombatSocket.LeftHand"),
        FString("Socket for the left hand")
    );

    GameplayTags.CombatSocket_Tail = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("CombatSocket.Tail"),
        FString("Socket for the tail")
    );

    /*
     * Montage Tags
     */
    GameplayTags.Montage_Attack1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Montage.Attack1"),
        FString("Montage for Attack 1")
    );

    GameplayTags.Montage_Attack2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Montage.Attack2"),
        FString("Montage for Attack 2")
    );

    GameplayTags.Montage_Attack3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Montage.Attack3"),
        FString("Montage for Attack 3")
    );

    GameplayTags.Montage_Attack4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Montage.Attack4"),
        FString("Montage for Attack 4")
    );

    /*
     * Effects
     */
    GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Effects.HitReact"),
        FString("Effect for hit reaction")
    );

    /*
     * Player Tags
     */
    GameplayTags.Player_Block_InputPressed = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Player.Block.InputPressed"),
        FString("Input pressed for block")
    );

    GameplayTags.Player_Block_InputHeld = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Player.Block.InputHeld"),
        FString("Input held for block")
    );

    GameplayTags.Player_Block_InputReleased = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Player.Block.InputReleased"),
        FString("Input released for block")
    );

    GameplayTags.Player_Block_CursorTrace = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Player.Block.CursorTrace"),
        FString("Cursor trace for block")
    );

    /*
     * Maps for Damage Types to Resistances and Debuffs
     */
    GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistance_Fire);
    GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistance_Lightning);
    GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistance_Arcane);
    GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistance_Physical);

    GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Fire, GameplayTags.Debuff_Burn);
    GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Lightning, GameplayTags.Debuff_Stun);
    GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Arcane, GameplayTags.Debuff_Arcane);
    GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Physical, GameplayTags.Debuff_Physical);
}