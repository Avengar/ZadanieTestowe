// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemySpawner.h"
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
	void AddSpawner(AEnemySpawner* AddedSpawner);
	virtual void AddSpawner_Implementation(AEnemySpawner* AddedSpawner) {};
	
	UFUNCTION(BlueprintNativeEvent, Category = "Enemy")
	void RemoveAliveEnemy(AEnemyCharacter* RemovedEnemy);
	virtual void RemoveAliveEnemy_Implementation(AEnemyCharacter* RemovedEnemy) {};

	UFUNCTION(BlueprintNativeEvent, Category = "Enemy")
	void GetAliveEnemies(TArray<AEnemyCharacter*>& OutAliveEnemies);
	virtual void GetAliveEnemies_Implementation(TArray<AEnemyCharacter*>& OutAliveEnemies) {};
	
};
