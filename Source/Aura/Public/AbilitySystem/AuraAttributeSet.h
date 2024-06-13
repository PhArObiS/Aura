#pragma once

// CoreMinimal.h is a common header file that includes the most frequently used headers in Unreal Engine.
#include "CoreMinimal.h"
// Includes for the AttributeSet, AbilitySystemComponent, and GameplayEffectExtension classes.
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
// The generated.h file is required for Unreal's reflection system.
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

    // Health attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
    FGameplayAttributeData Health;
    // Generates boilerplate code for Health attribute.
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

    // MaxHealth attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

    // Mana attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

    // MaxMana attribute, replicated with a notification function.
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
    FGameplayAttributeData MaxMana;
    ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

    // Notification functions called when attributes are replicated.
    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

    UFUNCTION()
    void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

    UFUNCTION()
    void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

private:
    // Helper function to set effect properties based on the callback data.
    void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};