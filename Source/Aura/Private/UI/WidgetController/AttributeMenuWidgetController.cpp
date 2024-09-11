#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "Player/AuraPlayerState.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
    // Ensure that the AttributeInfo is valid before proceeding
    check(AttributeInfo);
    
    // Loop through the map that associates Tags to Attributes
    for (auto& Pair : GetAuraAS()->TagsToAttributes)
    {
        // Bind a delegate to the attribute change event
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
        [this, Pair](const FOnAttributeChangeData& Data)
        {
            UE_LOG(LogTemp, Warning, TEXT("Attribute Changed for Tag: %s, New Value: %f"), *Pair.Key.ToString(), Data.NewValue);

            // Broadcast the attribute information
            BroadcastAttributeInfo(Pair.Key, Pair.Value());
        });
    }

    // Bind a delegate for when the attribute points change
    GetAuraPS()->OnAttributePointsChangedDelegate.AddLambda(
        [this](int32 Points)
        {
            UE_LOG(LogTemp, Warning, TEXT("Attribute Points Changed: %d"), Points);
            AttributePointsChangedDelegate.Broadcast(Points);
        }
    );
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
    // Cast to the AuraAttributeSet to ensure type safety
    UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
    
    // Ensure that the AttributeInfo is valid before broadcasting
    check(AttributeInfo);

    // Log initial values
    UE_LOG(LogTemp, Warning, TEXT("Broadcasting Initial Attribute Values..."));

    // Loop through the attributes and broadcast the initial values
    for (auto& Pair : AS->TagsToAttributes)
    {
        BroadcastAttributeInfo(Pair.Key, Pair.Value());
    }

    // Broadcast the initial attribute points
    AttributePointsChangedDelegate.Broadcast(GetAuraPS()->GetAttributePoints());
}

void UAttributeMenuWidgetController::UpgradeAttribute(const FGameplayTag& AttributeTag)
{
    // Cast the AbilitySystemComponent to ensure it's of the correct type
    UAuraAbilitySystemComponent* AuraASC = CastChecked<UAuraAbilitySystemComponent>(AbilitySystemComponent);

    // Log the attribute upgrade
    UE_LOG(LogTemp, Warning, TEXT("Upgrading Attribute for Tag: %s"), *AttributeTag.ToString());

    // Call the upgrade method in the Ability System Component
    AuraASC->UpgradeAttribute(AttributeTag);
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
    // Find the corresponding attribute info for the given tag
    FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);

    // Get the numeric value of the attribute from the AttributeSet
    Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);

    // Log the broadcast information
    UE_LOG(LogTemp, Warning, TEXT("Broadcasting Attribute Info for Tag: %s, Value: %f"), *AttributeTag.ToString(), Info.AttributeValue);

    // Broadcast the attribute information
    AttributeInfoDelegate.Broadcast(Info);
}
