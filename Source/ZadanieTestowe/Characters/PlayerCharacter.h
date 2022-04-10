// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ZadanieTestowe/Weapons/BaseWeapon.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	
	APlayerCharacter();
	
	/**Fire currently attached weapon*/
	void FireWeapon();
	
protected:

	virtual void BeginPlay() override;

	void Destroyed() override;
	
protected:
	/**Weapon class to spawn at the start of the game*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TSubclassOf<ABaseWeapon> WeaponClass;

	/**Weapon reference*/
	UPROPERTY(VisibleAnywhere)
	ABaseWeapon* AttachedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FName WeaponSocketName;
};
