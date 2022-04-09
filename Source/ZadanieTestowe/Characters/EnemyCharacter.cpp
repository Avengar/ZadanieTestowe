// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "GameFramework/GameStateBase.h"
#include "ZadanieTestowe/System/GameStateInterface.h"

AEnemyCharacter::AEnemyCharacter() : Super()
{
	//Set defaults
	MaximumHealth = 100;
}

void AEnemyCharacter::BeginPlay()
{
	AGameStateBase* pGameState = GetWorld()->GetGameState();
	
	if(IsValid(pGameState) && pGameState->Implements<UGameStateInterface>())
	{
		FGameSettings gameSettings;
		IGameStateInterface::Execute_GetCurrentGameSettings(pGameState, gameSettings);
		MaximumHealth = gameSettings.EnemyHealth;
		CurrentHealthPoints = MaximumHealth;
	}
	Super::BeginPlay();
}

void AEnemyCharacter::DealDamage_Implementation(int32 DamageValue)
{
	CurrentHealthPoints = CurrentHealthPoints - DamageValue;
	
	//We want to kill this enemy now, since we lost all HP
	if(CurrentHealthPoints <= 0)
	{
		Death();
	}
}

void AEnemyCharacter::Death()
{
	AGameStateBase* pGameState = GetWorld()->GetGameState();
	if(IsValid(pGameState) && pGameState->Implements<UGameStateInterface>())
	{
		IGameStateInterface::Execute_RemoveAliveEnemy(pGameState, this);
	}
	this->Destroy();
}
