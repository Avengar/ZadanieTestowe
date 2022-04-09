// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

#include "GameStateInterface.h"
#include "GameFramework/GameStateBase.h"


AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	//Setup root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Create spawn direction arrow
	SpawnDirectionArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ForwardArrow"));
	SpawnDirectionArrow->SetupAttachment(RootComponent);
	
	//Make some icon for easier identification of spawners on level
	SpawnerIcon = CreateDefaultSubobject<UBillboardComponent>(TEXT("SpawnerIcon"));
	SpawnerIcon->SetupAttachment(RootComponent);
	
}

AEnemyCharacter* AEnemySpawner::SpawnEnemy()
{
	//Validate enemy class
	if(IsValid(EnemyClassToSpawn) == false)
	{
		const FString logErrorMessage = FString::Printf(TEXT("Enemy class not provided in  : %s"), *this->GetName());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *logErrorMessage);
		return nullptr;
	}

	//prepare spawn parameters 
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AEnemyCharacter* pSpawnedEnemy = GetWorld()->SpawnActor<AEnemyCharacter>(EnemyClassToSpawn,this->GetActorLocation(),this->GetActorRotation(), spawnParameters);

	//Spawn was successful
	if(IsValid(pSpawnedEnemy))
	{
		return pSpawnedEnemy;
	}
	
	//Spawn failed, log spawner name with warning
	const FString logErrorMessage = FString::Printf(TEXT("Enemy spawn failed at : %s"), *this->GetName());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *logErrorMessage);
	return nullptr;
}

void AEnemySpawner::BeginPlay()
{
	AGameStateBase* pGameState = GetWorld()->GetGameState();

	//Register spawner in game state
	if(IsValid(pGameState) && pGameState->Implements<UGameStateInterface>())
	{
		IGameStateInterface::Execute_AddSpawner(pGameState, this);
	}
	Super::BeginPlay();
}

