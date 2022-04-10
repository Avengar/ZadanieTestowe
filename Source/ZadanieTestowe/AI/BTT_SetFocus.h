// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_SetFocus.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API UBTT_SetFocus : public UBTTaskNode
{
	GENERATED_BODY()

	UBTT_SetFocus();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	
	/**Enemy to set focus at*/
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector TargetEnemy;
	
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector SelfReference;
};
