// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	//WeaponMeshSetup
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	//ProjectileSpawnPointSetup
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(WeaponMesh);

	//Set defaults
	FireWeaponCooldown = 0.75f;
}

void ABaseWeapon::FireWeapon()
{
	//Check if we have valid projectile class
	if(IsValid(ProjectileClass) == false)
	{
		const FString logErrorMessage = FString::Printf(TEXT("Projectile class not provided in  : %s"), *this->GetName());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *logErrorMessage);
	}
	//if timer is valid then we already shot recently
	if(m_weaponCooldownTimerHandle.IsValid() == false)
	{
		GetWorld()->GetTimerManager().SetTimer(m_weaponCooldownTimerHandle, this,&ABaseWeapon::ResetWeaponCooldown, FireWeaponCooldown, false);
		
		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation(), spawnParameters);
	}
}

void ABaseWeapon::ResetWeaponCooldown()
{
	if(m_weaponCooldownTimerHandle.IsValid())
	{
		m_weaponCooldownTimerHandle.Invalidate();
	}
}

