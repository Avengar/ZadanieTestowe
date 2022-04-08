// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameState.h"
#include "GameplaySettingsInterface.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API ABaseGameMode : public AGameModeBase, public IGameplaySettingsInterface
{
	GENERATED_BODY()

public:
	ABaseGameMode();
	
	//GameplaySettingsInterface
	
	/**Returns game settings*/
	virtual void GetGameplaySettings_Implementation(FGameSettings& OutGameSettings) override;

	/**Set new values for game settings*/
	virtual void SetGameplaySettings_Implementation(FGameSettings NewSettings) override;
	
protected:
	
	/**Variable storing all gameplay settings*/
	UPROPERTY()
	FGameSettings GameSettings;
};
