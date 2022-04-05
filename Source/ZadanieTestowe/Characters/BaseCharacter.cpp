// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Set default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
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

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

