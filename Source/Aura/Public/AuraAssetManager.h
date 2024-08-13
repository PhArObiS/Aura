// AuraAssetManager.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AuraAssetManager.generated.h"

/**
 * Custom Asset Manager class for the Aura game.
 * Handles the initialization of Gameplay Tags and the Ability System Globals.
 */
UCLASS()
class AURA_API UAuraAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	/** Returns the singleton instance of the AuraAssetManager */
	static UAuraAssetManager& Get();

protected:
	/** Override StartInitialLoading to initialize custom tags and systems */
	virtual void StartInitialLoading() override;
};
