// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API UBTT_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	//Constructor
	UBTT_Shoot();

private:
	//Execute task override
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	/**Provide self actor to call shoot function*/
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector SelfActor;

	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector TargetEnemy;
};
