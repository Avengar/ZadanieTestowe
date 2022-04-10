// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_IsEnemyInAttackRange.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/GameStateBase.h"
#include "ZadanieTestowe/System/GameStateInterface.h"

UBTS_IsEnemyInAttackRange::UBTS_IsEnemyInAttackRange()
{
	NodeName = "IsEnemyInRange";
	TargetEnemy.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTS_IsEnemyInAttackRange, TargetEnemy),AActor::StaticClass());
	SelfReference.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTS_IsEnemyInAttackRange, SelfReference),AActor::StaticClass());
	bCanShoot.AddBoolFilter(this,GET_MEMBER_NAME_CHECKED(UBTS_IsEnemyInAttackRange, bCanShoot));
}

void UBTS_IsEnemyInAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* pBlackboardComponent = OwnerComp.GetBlackboardComponent();

	if(IsValid(pBlackboardComponent) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("BlackboardComponent is invalid"));
		pBlackboardComponent->SetValueAsBool(bCanShoot.SelectedKeyName, false);
		return;
	}
	
	AActor* pSelfActor = Cast<AActor>(pBlackboardComponent->GetValueAsObject(SelfReference.SelectedKeyName));
	AActor* pEnemyActor = Cast<AActor>(pBlackboardComponent->GetValueAsObject(TargetEnemy.SelectedKeyName));
	
	if(IsValid(pSelfActor) == false || IsValid(pEnemyActor) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("One of the actors  is invalid"));
		pBlackboardComponent->SetValueAsBool(bCanShoot.SelectedKeyName, false);
		return;
	}
	float measuerdDistance = FVector::Dist(pSelfActor->GetActorLocation(), pEnemyActor->GetActorLocation());

	AGameStateBase* pGameState = GetWorld()->GetGameState();
	
	if(IsValid(pGameState) == false || pGameState->Implements<UGameStateInterface>() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameState is invalid or does not implement GameStateInterface"));
		pBlackboardComponent->SetValueAsBool(bCanShoot.SelectedKeyName, false);
		return;
	}
	
	FGameSettings gameSettings;
	IGameStateInterface::Execute_GetCurrentGameSettings(pGameState, gameSettings);
	
	if(measuerdDistance <= gameSettings.PlayerAttackRange)
	{
		pBlackboardComponent->SetValueAsBool(bCanShoot.SelectedKeyName, true);
	}
	else
	{
		pBlackboardComponent->SetValueAsBool(bCanShoot.SelectedKeyName, false);
	}
	
}
