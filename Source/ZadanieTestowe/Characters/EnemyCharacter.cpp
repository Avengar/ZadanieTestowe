// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter() : Super()
{
	HealthPoints = 100;
}

void AEnemyCharacter::DealDamage_Implementation(int32 DamageValue)
{
	HealthPoints = HealthPoints - DamageValue;
	
	//We want to kill this enemy now, since we lost all HP
	if(HealthPoints <= 0)
	{
		Death();
	}
}

void AEnemyCharacter::Death()
{
	this->Destroy();
}
