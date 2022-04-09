// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplaySettingsInterface.h"
#include "GameStateInterface.h"
#include "GameFramework/GameStateBase.h"
#include "ZadanieTestowe/Characters/EnemyCharacter.h"
#include "BaseGameState.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API ABaseGameState : public AGameStateBase, public IGameStateInterface
{
	GENERATED_BODY()

public:
	/**Spawn enemies and start game loop*/
	UFUNCTION(BlueprintCallable)
	void StartGame();
	
	/**GameStateInterface*/
	
	/**Register spawner in EnemySpawners array*/
	void AddSpawner_Implementation(AEnemySpawner* AddedSpawner) override;

	void RemoveAliveEnemy_Implementation(AEnemyCharacter* RemovedEnemy) override;

	void GetAliveEnemies_Implementation(TArray<AEnemyCharacter*>& OutAliveEnemies) override;

	/**~GameStateInterface*/

protected:
	/**Array holding currently alive enemies*/
	UPROPERTY()
	TArray<AEnemyCharacter*> AliveEnemies;

	UPROPERTY()
	TArray<AEnemySpawner*> EnemySpawners;

	UPROPERTY()
	FGameSettings CurrentGameSettings;
};
