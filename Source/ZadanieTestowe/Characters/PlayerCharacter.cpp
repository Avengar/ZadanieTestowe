// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/GameState.h"
#include "ZadanieTestowe/System/GameStateInterface.h"

APlayerCharacter::APlayerCharacter() :Super()
{
	WeaponSocketName = "weapon_r";
}

void APlayerCharacter::BeginPlay()
{
	
	AGameStateBase* pGameState = GetWorld()->GetGameState();
	
	if(IsValid(pGameState) && pGameState->Implements<UGameStateInterface>())
	{
		FGameSettings gameSettings;
		IGameStateInterface::Execute_GetCurrentGameSettings(pGameState, gameSettings);
		GetCharacterMovement()->MaxWalkSpeed = gameSettings.PlayerMovementSpeed;
	}
	
	if(IsValid(WeaponClass) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon class not set in PLayerCharacter"));
		return;
	}
	
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	AttachedWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass, this->GetActorLocation(), this->GetActorRotation(), spawnParameters);
	
	if(IsValid(AttachedWeapon) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon spawn failed for player character"));
	}
	
	AttachedWeapon->AttachToComponent(this->GetMesh(),FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocketName);

	Super::BeginPlay();
}

void APlayerCharacter::FireWeapon()
{
	if(IsValid(AttachedWeapon) == false)
	{
		return;
	}

	AttachedWeapon->FireWeapon();
}
