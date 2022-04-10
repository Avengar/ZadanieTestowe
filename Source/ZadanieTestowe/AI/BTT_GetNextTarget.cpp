// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GetNextTarget.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ZadanieTestowe/System/BaseGameState.h"

UBTT_GetNextTarget::UBTT_GetNextTarget()
{
	//Set node name and filter key to get only actors
	NodeName = "GetNextTarget";
	TargetEnemy.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_GetNextTarget, TargetEnemy),AEnemyCharacter::StaticClass());
}

EBTNodeResult::Type UBTT_GetNextTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboardComponent = OwnerComp.GetBlackboardComponent();

	if(IsValid(pBlackboardComponent) == false)
	{
		return EBTNodeResult::Failed;
	}
	
	TArray<ABaseCharacter*> AliveEnemies;
	AGameStateBase* pGameState = GetWorld()->GetGameState();
	if(IsValid(pGameState) == false || pGameState->Implements<UGameStateInterface>() == false)
	{
		return EBTNodeResult::Failed;
	}
	
	IGameStateInterface::Execute_GetAliveEnemies(pGameState, AliveEnemies);
	
	if(AliveEnemies.IsValidIndex(0))
	{
		int32 enemyIndex = FMath::RandRange(0,AliveEnemies.Num()-1);
		pBlackboardComponent->SetValueAsObject(TargetEnemy.SelectedKeyName, AliveEnemies[enemyIndex]);
	
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
}
