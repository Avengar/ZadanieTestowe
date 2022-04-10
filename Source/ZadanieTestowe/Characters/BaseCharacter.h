// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ZADANIETESTOWE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:

	//Restart function called when Pawn is being possesed
	virtual void Restart() override;

protected:
	
	/** Blackboard variable used by character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AISetup")
    UBlackboardData* BlackboardData;
    	
	/** Behaviour tree  used by character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AISetup")
    UBehaviorTree* BehaviourTree;
};
