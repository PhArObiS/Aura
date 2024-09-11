#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AbilityInfo.h"
#include "AbilitySystem/Data/LevelUpInfo.h"
#include "Player/AuraPlayerState.h"

void UOverlayWidgetController::BroadcastInitialValues()
{

	OnHealthChanged.Broadcast(GetAuraAS()->GetHealth());
	OnMaxHealthChanged.Broadcast(GetAuraAS()->GetMaxHealth());
	OnManaChanged.Broadcast(GetAuraAS()->GetMana());
	OnMaxManaChanged.Broadcast(GetAuraAS()->GetMaxMana());
	
}


void UOverlayWidgetController::BindCallbacksToDependencies()
{
	// Added this to see if callbacks are happening more than once
	UE_LOG(LogTemp, Warning, TEXT("BindCallbacksToDependencies called"));
	if (bCallbacksBound)  // Add a flag to prevent duplicate bindings.
	{
		UE_LOG(LogTemp, Warning, TEXT("Callbacks already bound, skipping."));
		return;
	}
	bCallbacksBound = true;  // Set the flag to indicate that callbacks are bound.
	// Ends here
	
    if (!GetAuraPS())
    {
        UE_LOG(LogTemp, Error, TEXT("AuraPlayerState is null in BindCallbacksToDependencies."));
        return;
    }

    GetAuraPS()->OnXPChangedDelegate.AddUObject(this, &UOverlayWidgetController::OnXPChanged);
    UE_LOG(LogTemp, Warning, TEXT("BindCallbacksToDependencies: XP Changed callback bound."));

    GetAuraPS()->OnLevelChangedDelegate.AddLambda(
        [this](int32 NewLevel, bool bLevelUp)
        {
            UE_LOG(LogTemp, Warning, TEXT("Level changed to: %d, Level Up: %s"), NewLevel, bLevelUp ? TEXT("true") : TEXT("false"));
            OnPlayerLevelChangedDelegate.Broadcast(NewLevel, bLevelUp);
        }
    );

    if (!AbilitySystemComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is null in BindCallbacksToDependencies."));
        return;
    }

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GetAuraAS()->GetHealthAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            UE_LOG(LogTemp, Warning, TEXT("Health changed to: %f"), Data.NewValue);
            OnHealthChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GetAuraAS()->GetMaxHealthAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            UE_LOG(LogTemp, Warning, TEXT("Max Health changed to: %f"), Data.NewValue);
            OnMaxHealthChanged.Broadcast(Data.NewValue);
        }
    );

    // Logging for Ability Equipped
    if (GetAuraASC())
    {
        GetAuraASC()->AbilityEquipped.AddUObject(this, &UOverlayWidgetController::OnAbilityEquipped);
        UE_LOG(LogTemp, Warning, TEXT("BindCallbacksToDependencies: AbilityEquipped callback bound."));

        if (GetAuraASC()->bStartupAbilitiesGiven)
        {
            UE_LOG(LogTemp, Warning, TEXT("Startup abilities already given."));
            BroadcastAbilityInfo();
        }
        else
        {
            GetAuraASC()->AbilitiesGivenDelegate.AddUObject(this, &UOverlayWidgetController::BroadcastAbilityInfo);
            UE_LOG(LogTemp, Warning, TEXT("AbilitiesGivenDelegate bound."));
        }

        GetAuraASC()->EffectAssetTags.AddLambda(
            [this](const FGameplayTagContainer& AssetTags)
            {
                for (const FGameplayTag& Tag : AssetTags)
                {
                    UE_LOG(LogTemp, Warning, TEXT("EffectAssetTags added with Tag: %s"), *Tag.ToString());

                    FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
                    if (Tag.MatchesTag(MessageTag))
                    {
                        const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);

                        // Log when broadcasting the message widget row
                        if (Row)
                        {
                            UE_LOG(LogTemp, Warning, TEXT("Broadcasting message widget row for Tag: %s"), *Tag.ToString());
                            MessageWidgetRowDelegate.Broadcast(*Row);
                        }
                        else
                        {
                            UE_LOG(LogTemp, Error, TEXT("Failed to broadcast message widget row for Tag: %s"), *Tag.ToString());
                        }
                    }
                }
            }
        );
    }
}


void UOverlayWidgetController::OnXPChanged(int32 NewXP)
{
	const ULevelUpInfo* LevelUpInfo = GetAuraPS()->LevelUpInfo;
	checkf(LevelUpInfo, TEXT("Unabled to find LevelUpInfo. Please fill out AuraPlayerState Blueprint"));

	const int32 Level = LevelUpInfo->FindLevelForXP(NewXP);
	const int32 MaxLevel = LevelUpInfo->LevelUpInformation.Num();

	if (Level <= MaxLevel && Level > 0)
	{
		const int32 LevelUpRequirement = LevelUpInfo->LevelUpInformation[Level].LevelUpRequirement;
		const int32 PreviousLevelUpRequirement = LevelUpInfo->LevelUpInformation[Level - 1].LevelUpRequirement;

		const int32 DeltaLevelRequirement = LevelUpRequirement - PreviousLevelUpRequirement;
		const int32 XPForThisLevel = NewXP - PreviousLevelUpRequirement;

		const float XPBarPercent = static_cast<float>(XPForThisLevel) / static_cast<float>(DeltaLevelRequirement);

		OnXPPercentChangedDelegate.Broadcast(XPBarPercent);
	}
}

void UOverlayWidgetController::OnAbilityEquipped(const FGameplayTag& AbilityTag, const FGameplayTag& Status, const FGameplayTag& Slot, const FGameplayTag& PreviousSlot) const
{
	const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();
	
	FAuraAbilityInfo LastSlotInfo;
	LastSlotInfo.StatusTag = GameplayTags.Abilities_Status_Unlocked;
	LastSlotInfo.InputTag = PreviousSlot;
	LastSlotInfo.AbilityTag = GameplayTags.Abilities_None;
	// Broadcast empty info if PreviousSlot is a valid slot. Only if equipping an already-equipped spell
	AbilityInfoDelegate.Broadcast(LastSlotInfo);

	FAuraAbilityInfo Info = AbilityInfo->FindAbilityInfoForTag(AbilityTag);
	Info.StatusTag = Status;
	Info.InputTag = Slot;
	AbilityInfoDelegate.Broadcast(Info);
}
