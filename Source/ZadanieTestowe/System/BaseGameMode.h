// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameState.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABaseGameMode();
public:
	//Game modifiers //

	/**How far enemy can be from player character to be able to be shot */
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	float PlayerAttackRange;
	
	/**Player character movement speed.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	float PlayerMovementSpeed;

	/**Enemy character movement speed.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	float EnemyMovementSpeed;
	
	/**Number of spawned enemies at the beggining of the round.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	int32 NumberOfEnemies;
	
	/**Amount of damage dealt by one projectile*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	int32 ProjectileDamage;

	/**Amount of health that each enemy spawns with*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameSetup")
	int32 EnemyHealth;
};
