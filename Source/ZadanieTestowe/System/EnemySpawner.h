// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZadanieTestowe/Characters/BaseCharacter.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "ZadanieTestowe/Characters/EnemyCharacter.h"
#include "EnemySpawner.generated.h"

UCLASS()
class ZADANIETESTOWE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	/**Spawns enemy of given class. Return nullptr if spawning was not successful*/
	UFUNCTION(BlueprintCallable)
	AEnemyCharacter* SpawnEnemy();
protected:
	
	void BeginPlay() override;
	
protected:
	/**Arrow used for clarity on level, to determine spawn direction*/
	UPROPERTY()
	UArrowComponent* SpawnDirectionArrow;

	/**Billboard component for easier spawner identification on levels*/
	UPROPERTY(EditAnywhere)
	UBillboardComponent* SpawnerIcon;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemyCharacter> EnemyClassToSpawn;
};
