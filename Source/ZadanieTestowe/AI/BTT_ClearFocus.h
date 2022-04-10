// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ClearFocus.generated.h"

/**
 * 
 */
UCLASS()
class ZADANIETESTOWE_API UBTT_ClearFocus : public UBTTaskNode
{
	GENERATED_BODY()


	UBTT_ClearFocus();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector SelfReference;
};
