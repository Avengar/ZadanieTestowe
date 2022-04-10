// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_IsEnemyInAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API UBTS_IsEnemyInAttackRange : public UBTService
{
	GENERATED_BODY()
	
	UBTS_IsEnemyInAttackRange();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector TargetEnemy;

	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector SelfReference;

	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector bCanShoot;
};
