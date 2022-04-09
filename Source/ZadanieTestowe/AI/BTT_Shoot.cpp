// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Shoot.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "ZadanieTestowe/Characters/PlayerCharacter.h"

UBTT_Shoot::UBTT_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboardComponent = OwnerComp.GetBlackboardComponent();

	if(IsValid(pBlackboardComponent) == false)
	{
		return EBTNodeResult::Failed;
	}

	APlayerCharacter* pPlayerCharacter = Cast<APlayerCharacter>(pBlackboardComponent->GetValueAsObject(SelfActor.SelectedKeyName));

	if(IsValid(pPlayerCharacter))
	{
		pPlayerCharacter->FireWeapon();
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
