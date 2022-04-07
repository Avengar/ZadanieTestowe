// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseProjectile.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class ZADANIETESTOWE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	
	/**Function spawns projectile and starts cooldown timer*/
	void FireWeapon();
	
protected:
	/**Projectile class to spawn when shooting*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponSetup")
	TSubclassOf<ABaseProjectile> ProjectileClass;
	
	/**How much time must pass, before we can shoot another bullet*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponSetup")
	float FireWeaponCooldown;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* WeaponMesh;
	
	/**Location at which we spawn projectile*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USceneComponent* ProjectileSpawnPoint;
};
