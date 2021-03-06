// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameState.h"

#include "GameplaySettingsInterface.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

void ABaseGameState::StartGame_Implementation()
{
	AGameModeBase* pGameMode = UGameplayStatics::GetGameMode(GetWorld());
	FGameSettings gameSettings;
	
	//get settings from game mode
	if(pGameMode->Implements<UGameplaySettingsInterface>() == false)
	{
		UE_LOG(LogTemp, Error, TEXT("Game mode does not implement UGameplaySettingsInterface!"));
		return;
	}
	
	IGameplaySettingsInterface::Execute_GetGameplaySettings(pGameMode,gameSettings);
	
	//Spawn enemies
	for(int i=0; i < gameSettings.NumberOfEnemies; i++)
	{
		if(EnemySpawners.IsValidIndex(i))
		{
			AliveEnemies.AddUnique(EnemySpawners[i]->SpawnCharacter());
		}
	}

	if(IsValid(PlayerSpawner) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player spawner is not valid"));
		return;
	}
	
	PlayerReference = PlayerSpawner->SpawnCharacter();
}

void ABaseGameState::GetAliveEnemies_Implementation(TArray<ABaseCharacter*>& OutAliveEnemies)
{
	OutAliveEnemies = AliveEnemies;
}

void ABaseGameState::EndGame_Implementation()
{
	PlayerReference->Destroy();
}

void ABaseGameState::AddSpawner_Implementation(ABaseSpawner* AddedSpawner)
{
	if(IsValid(AddedSpawner) == false)
	{
		return;
	}

	if(AddedSpawner->GetIsPlayerSpawner() == false)
	{
		EnemySpawners.AddUnique(AddedSpawner);
	}
	else
	{
		PlayerSpawner = AddedSpawner;
	}
}

void ABaseGameState::RemoveAliveEnemy_Implementation(ABaseCharacter* RemovedEnemy)
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

	//Since there are no more enemies we want to reset the game
	if(AliveEnemies.Num() == 0)
	{
		EndGame();
	}
}
