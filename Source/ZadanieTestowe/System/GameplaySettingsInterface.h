// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplaySettingsInterface.generated.h"

/**Struct used to store game settings*/
USTRUCT(BlueprintType)
struct FGameSettings
{
	GENERATED_BODY()

	/**How far enemy can be from player character to be able to be shot */
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	float PlayerAttackRange;
	
	/**Player character movement speed.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	float PlayerMovementSpeed;

	/**Enemy character movement speed.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	float EnemyMovementSpeed;
	
	/**Number of spawned enemies at the beginning of the round.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	int32 NumberOfEnemies;
	
	/**Amount of damage dealt by one projectile*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	int32 ProjectileDamage;

	/**Amount of health that each enemy spawns with*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	int32 EnemyHealth;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameplaySettingsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZADANIETESTOWE_API IGameplaySettingsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void GetGameplaySettings(FGameSettings& OutGameSettings);
	virtual void GetGameplaySettings_Implementation(FGameSettings& OutGameSettings);

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void SetGameplaySettings(FGameSettings NewSettings);
	virtual void SetGameplaySettings_Implementation(FGameSettings NewSettings) {};
	
};
