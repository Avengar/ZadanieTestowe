// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ZadanieTestowe/System/DamageInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API AEnemyCharacter : public ABaseCharacter, public IDamageInterface
{
	GENERATED_BODY()

public:
	//Constructor
	AEnemyCharacter();

protected:
	/**Apply damage, DamageInterfaceOverride, blueprint callable for debug purposes*/
	UFUNCTION(BlueprintCallable)
	virtual void DealDamage_Implementation(int32 DamageValue) override;
	
	/**Handle enemy death logic. Called by DealDamage when health reaches 0*/
	void Death();


protected:
	/**Standard HP value. If it reaches 0 enemy is dead*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int32 HealthPoints;
};
