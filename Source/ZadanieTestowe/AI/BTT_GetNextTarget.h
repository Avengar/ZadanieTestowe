// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_GetNextTarget.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API UBTT_GetNextTarget : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_GetNextTarget();

private:
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	/**We hold our next target in this variable*/
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector TargetEnemy;
};
