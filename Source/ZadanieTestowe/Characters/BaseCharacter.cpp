// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Set default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//CharacterMovementComponent defaults
	GetCharacterMovement()->bOrientRotationToMovement = true;

	//AI defaults
	AutoPossessAI = EAutoPossessAI::Spawned;
}

void ABaseCharacter::Restart()
{
	//Get AIController & BlackboardComponent
	AAIController* pAIController = Cast<AAIController>(GetController());
	UBlackboardComponent* pBlackboardComponent = pAIController->GetBlackboardComponent();

	//Set desired Blackboard and BehaviorTree for AI
	pAIController->UseBlackboard(BlackboardData,pBlackboardComponent);
	pAIController->RunBehaviorTree(BehaviourTree);
	Super::Restart();
}

