#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "AuraAttributeSet.generated.h"

// Macro to generate boilerplate code for getting, setting, and initializing attributes.
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

// A struct to store properties related to gameplay effects.
USTRUCT()
struct FEffectProperties
{
    GENERATED_BODY()

    FEffectProperties() {}
    
    // Context handle for the gameplay effect.
    FGameplayEffectContextHandle EffectContextHandle;

    // Source and target components and actors involved in the effect.
    UPROPERTY()
    UAbilitySystemComponent* SourceASC = nullptr;

    UPROPERTY()
    AActor* SourceAvatarActor = nullptr;

    UPROPERTY()
    AController* SourceController = nullptr;

    UPROPERTY()
    ACharacter* SourceCharacter = nullptr;

    UPROPERTY()
    UAbilitySystemComponent* TargetASC = nullptr;

    UPROPERTY()
    AActor* TargetAvatarActor = nullptr;

    UPROPERTY()
    AController* TargetController = nullptr;

    UPROPERTY()
    ACharacter* TargetCharacter = nullptr;
};

/**
 * UAuraAttributeSet class - defines attributes for the Aura game.
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
    GENERATED_BODY()
public:
    // Constructor to initialize default values for the attributes.
    UAuraAttributeSet();
    
    // Function to define which properties should be replicated.
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // Called before an attribute's value is changed.
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    
    // Called after a gameplay effect is executed.
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    /*
     * Primary Attributes
    */

    // Health attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Primary Attributes")
    FGameplayAttributeData Strength;
    // Generates boilerplate code for Health attribute.
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

    // Health attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
    FGameplayAttributeData Intelligence;
    // Generates boilerplate code for Health attribute.
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

    // Health attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
    FGameplayAttributeData Resilience;
    // Generates boilerplate code for Health attribute.
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

    // Health attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
    FGameplayAttributeData Vigor;
    // Generates boilerplate code for Health attribute.
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

    /*
     * Secondary Attributes
    */

	// Armor attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	// ArmorPenetration attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration);

	// BlockChance attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	// CriticalHitChance attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance);

	// CriticalHitDamage attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage);

	// CriticalHitResistance attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance);

	// HealthRegeneration attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration);

	// ManaRegeneration attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	// Generates boilerplate code for Health attribute.
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration);

	// MaxHealth attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	
	// MaxMana attribute, replicated with a notification function.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	/*
	 * Vital Attributes
	*/
    
    // Health attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
    FGameplayAttributeData Health;
    // Generates boilerplate code for Health attribute.
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

    // Mana attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

    // Notification functions called when attributes are replicated.
    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

    UFUNCTION()
    void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

    UFUNCTION()
    void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

    UFUNCTION()
    void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

    UFUNCTION()
    void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

    UFUNCTION()
    void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	

private:
    // Helper function to set effect properties based on the callback data.
    void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};