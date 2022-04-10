// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SetFocus.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UBTT_SetFocus::UBTT_SetFocus()
{
	NodeName = "SetFocus";
	
	TargetEnemy.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_SetFocus, TargetEnemy),AActor::StaticClass());
	SelfReference.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_SetFocus, SelfReference),AActor::StaticClass());
}

EBTNodeResult::Type UBTT_SetFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
	AActor* pFocusedActor = Cast<AActor>(pBlackboardComponent->GetValueAsObject(TargetEnemy.SelectedKeyName));
	
	if(IsValid(pFocusedActor) == false)
	{
		return EBTNodeResult::Failed;
	}

	pAIController->SetFocus(pFocusedActor,EAIFocusPriority::Gameplay);
	return EBTNodeResult::Succeeded;

}
