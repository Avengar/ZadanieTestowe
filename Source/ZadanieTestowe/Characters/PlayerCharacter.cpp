// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	WeaponSocketName = "weapon_r";
}

void APlayerCharacter::BeginPlay()
{
	if(IsValid(WeaponClass) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon class not set in PLayerCharacter"));
	}
	
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	AttachedWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass, this->GetActorLocation(), this->GetActorRotation(), spawnParameters);
	
	if(IsValid(AttachedWeapon) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon spawn failed for player character"));
	}
	
	AttachedWeapon->AttachToComponent(this->GetMesh(),FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocketName);
}

void APlayerCharacter::FireWeapon()
{
	if(IsValid(AttachedWeapon) == false)
	{
		return;
	}

	AttachedWeapon->FireWeapon();
}
