// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/GameState.h"
#include "Kismet/GameplayStatics.h"
#include "ZadanieTestowe/System/GameStateInterface.h"

APlayerCharacter::APlayerCharacter()
{
	//Set defaults
	WeaponSocketName = "weapon_r";
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* pGameMode = UGameplayStatics::GetGameMode(GetWorld());
	
	if(pGameMode->Implements<UGameplaySettingsInterface>())
	{
		FGameSettings gameSettings;
		IGameplaySettingsInterface::Execute_GetGameplaySettings(pGameMode, gameSettings);
		GetCharacterMovement()->MaxWalkSpeed = gameSettings.PlayerMovementSpeed;
	}
	
	if(IsValid(WeaponClass) == false)
	{
		UE_LOG(LogTemp, Error, TEXT("Weapon class not set in PLayerCharacter"));
		return;
	}
	
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	AttachedWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass, this->GetActorLocation(), this->GetActorRotation(), spawnParameters);
	
	if(IsValid(AttachedWeapon) == false)
	{
		UE_LOG(LogTemp, Error, TEXT("Weapon spawn failed for player character"));
		return;
	}
	
	AttachedWeapon->AttachToComponent(this->GetMesh(),FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocketName);
	AttachedWeapon->SetOwner(this);
}

void APlayerCharacter::Destroyed()
{
	Super::Destroyed();
	
	if(IsValid(AttachedWeapon))
	{
		AttachedWeapon->Destroy();
	}
}

void APlayerCharacter::FireWeapon(AActor* TargetActor)
{
	if(IsValid(AttachedWeapon) == false)
	{
		return;
	}

	AttachedWeapon->FireWeapon(TargetActor);
}
