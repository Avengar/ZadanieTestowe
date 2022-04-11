// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSpawner.h"
#include "GameplaySettingsInterface.h"
#include "UObject/Interface.h"
#include "ZadanieTestowe/Characters/EnemyCharacter.h"
#include "GameStateInterface.generated.h"


UINTERFACE(MinimalAPI)
class UGameStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZADANIETESTOWE_API IGameStateInterface
{
	GENERATED_BODY()

public:

	/**Used to register spawners*/
	UFUNCTION(BlueprintNativeEvent, Category = "Spawner")
	void AddSpawner(ABaseSpawner* AddedSpawner);
	virtual void AddSpawner_Implementation(ABaseSpawner* AddedSpawner) {};
	
	UFUNCTION(BlueprintNativeEvent, Category = "Enemy")
	void RemoveAliveEnemy(ABaseCharacter* RemovedEnemy);
	virtual void RemoveAliveEnemy_Implementation(ABaseCharacter* RemovedEnemy) {};

	UFUNCTION(BlueprintNativeEvent, Category = "Enemy")
	void GetAliveEnemies(TArray<ABaseCharacter*>& OutAliveEnemies);
	virtual void GetAliveEnemies_Implementation(TArray<ABaseCharacter*>& OutAliveEnemies) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Game")
	void StartGame();
	virtual void StartGame_Implementation() {};
	
};
