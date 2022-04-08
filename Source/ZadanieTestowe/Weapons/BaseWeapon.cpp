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
}
//TODO:Set cooldown timer
void ABaseWeapon::FireWeapon()
{
	//Check if we have valid projectile class
	if(IsValid(ProjectileClass) == false)
	{
		const FString logErrorMessage = FString::Printf(TEXT("Projectile class not provided in  : %s"), *this->GetName());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *logErrorMessage);
	}
	
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation(), spawnParameters);
}

