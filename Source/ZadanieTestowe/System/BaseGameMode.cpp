// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"

ABaseGameMode::ABaseGameMode()
{
	//Set our GameState class as default
	GameStateClass = ABaseGameState::StaticClass();

	//Set defaults
	GameSettings.EnemyHealth = 100;
	GameSettings.ProjectileDamage = 50;
	GameSettings.EnemyMovementSpeed = 600.f;
	GameSettings.NumberOfEnemies = 5;
	GameSettings.PlayerAttackRange = 500.f;
	GameSettings.PlayerMovementSpeed = 700.f;
}

void ABaseGameMode::GetGameplaySettings_Implementation(FGameSettings& OutGameSettings) 
{
	OutGameSettings = GameSettings;
}

void ABaseGameMode::SetGameplaySettings_Implementation(FGameSettings NewSettings)
{
	GameSettings = NewSettings;
}
