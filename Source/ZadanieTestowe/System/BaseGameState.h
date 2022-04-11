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
	
	/**GameStateInterface*/

	/**Spawn enemies and start game loop*/
	void StartGame_Implementation() override;
	
	/**Register spawner in EnemySpawners array*/
	void AddSpawner_Implementation(ABaseSpawner* AddedSpawner) override;

	void RemoveAliveEnemy_Implementation(ABaseCharacter* RemovedEnemy) override;

	void GetAliveEnemies_Implementation(TArray<ABaseCharacter*>& OutAliveEnemies) override;

	/**~GameStateInterface*/

protected:
	/**Called when last enemy is removed from AliveEnemies array, ends current game*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndGame();
	virtual void EndGame_Implementation();
	
protected:
	/**Array holding currently alive enemies*/
	UPROPERTY()
	TArray<ABaseCharacter*> AliveEnemies;

	UPROPERTY()
	TArray<ABaseSpawner*> EnemySpawners;

	UPROPERTY()
	ABaseSpawner* PlayerSpawner;

	UPROPERTY()
	ABaseCharacter* PlayerReference;
};
