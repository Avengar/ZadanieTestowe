// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameState.h"

#include "GameplaySettingsInterface.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

void ABaseGameState::StartGame_Implementation()
{
	AGameModeBase* pGameMode = UGameplayStatics::GetGameMode(GetWorld());
	
	//get settings from game mode
	if(pGameMode->Implements<UGameplaySettingsInterface>())
	{
		IGameplaySettingsInterface::Execute_GetGameplaySettings(pGameMode,CurrentGameSettings);
	}

	//Spawn enemies
	for(int i=0; i < CurrentGameSettings.NumberOfEnemies; i++)
	{
		if(EnemySpawners.IsValidIndex(i))
		{
			AliveEnemies.AddUnique(EnemySpawners[i]->SpawnEnemy());
		}
	}
}

void ABaseGameState::GetAliveEnemies_Implementation(TArray<AEnemyCharacter*>& OutAliveEnemies)
{
	OutAliveEnemies = AliveEnemies;
}

void ABaseGameState::GetCurrentGameSettings_Implementation(FGameSettings& OutGameSettings)
{
	OutGameSettings = CurrentGameSettings;
}

void ABaseGameState::AddSpawner_Implementation(AEnemySpawner* AddedSpawner)
{
	if(IsValid(AddedSpawner) == false)
	{
		return;
	}

	EnemySpawners.AddUnique(AddedSpawner);
}

void ABaseGameState::RemoveAliveEnemy_Implementation(AEnemyCharacter* RemovedEnemy)
{
	if(IsValid(RemovedEnemy) == false)
	{
		return;
	}

	if(AliveEnemies.Find(RemovedEnemy) == INDEX_NONE)
	{
		return;
	}

	AliveEnemies.RemoveSingle(RemovedEnemy);
}
