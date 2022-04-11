// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "ZadanieTestowe/System/GameStateInterface.h"

AEnemyCharacter::AEnemyCharacter()
{
	//Set defaults
	MaximumHealth = 100;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* pGameMode = UGameplayStatics::GetGameMode(GetWorld());
	
	if(pGameMode->Implements<UGameplaySettingsInterface>())
	{
		FGameSettings gameSettings;
		IGameplaySettingsInterface::Execute_GetGameplaySettings(pGameMode, gameSettings);
		MaximumHealth = gameSettings.EnemyHealth;
		CurrentHealthPoints = MaximumHealth;
		GetCharacterMovement()->MaxWalkSpeed = gameSettings.EnemyMovementSpeed;
	}
}

void AEnemyCharacter::DealDamage_Implementation(int32 DamageValue)
{

	if(CurrentHealthPoints <= 0)
	{
		return;
	}
	
	CurrentHealthPoints -= FMath::Abs(DamageValue);
	
	//We want to kill this enemy now, since we lost all HP
	if(CurrentHealthPoints <= 0)
	{
		Death();
	}
}

void AEnemyCharacter::Death()
{
	AGameStateBase* pGameState = GetWorld()->GetGameState();
	if(pGameState->Implements<UGameStateInterface>())
	{
		IGameStateInterface::Execute_RemoveAliveEnemy(pGameState, this);
	}
	this->Destroy();
}
