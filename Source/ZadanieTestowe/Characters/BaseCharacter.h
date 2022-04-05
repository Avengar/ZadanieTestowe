// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"
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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Restart function called when Pawn is being possesed
	virtual void Restart() override;

protected:
	
	/** Blackboard variable used by character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AISetup")
    UBlackboardData* BlackboardData;
    	
	/** Behaviour tree  used by character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AISetup")
    UBehaviorTree* BehaviourTree;
	
	/**Movement speed used by CharacterMovement.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AISetup")
	float MovementSpeed;
	
	/**EQS reference used for searching desired movement location*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AISetup")
	UEnvQuery* MovementEnvironmentalQuery;
};
