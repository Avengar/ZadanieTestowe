// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ClearFocus.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UBTT_ClearFocus::UBTT_ClearFocus()
{
	NodeName = "ClearFocus";

	SelfReference.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_ClearFocus, SelfReference),AActor::StaticClass());
}

EBTNodeResult::Type UBTT_ClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboardComponent = OwnerComp.GetBlackboardComponent();

	if(IsValid(pBlackboardComponent) == false)
	{
		return EBTNodeResult::Failed;
	}

	ACharacter* pSelfCharacter = Cast<ACharacter>(pBlackboardComponent->GetValueAsObject(SelfReference.SelectedKeyName));

	if(IsValid(pSelfCharacter) == false)
	{
		return EBTNodeResult::Failed;
	}

	AAIController* pAIController = Cast<AAIController>(pSelfCharacter->GetController());
	pAIController->ClearFocus(EAIFocusPriority::Default);
	return EBTNodeResult::Succeeded;
}
