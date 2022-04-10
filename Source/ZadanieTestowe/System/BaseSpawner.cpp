// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSpawner.h"

#include "GameStateInterface.h"
#include "GameFramework/GameStateBase.h"


ABaseSpawner::ABaseSpawner()
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

ABaseCharacter* ABaseSpawner::SpawnCharacter()
{
	//Validate character class
	if(IsValid(CharacterClassToSpawn) == false)
	{
		const FString logErrorMessage = FString::Printf(TEXT("Character class not provided in  : %s"), *this->GetName());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *logErrorMessage);
		return nullptr;
	}
	
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ABaseCharacter* pSpawnedCharacter = GetWorld()->SpawnActor<ABaseCharacter>(CharacterClassToSpawn,this->GetActorLocation(),this->GetActorRotation(), spawnParameters);

	//Spawn was successful
	if(IsValid(pSpawnedCharacter))
	{
		return pSpawnedCharacter;
	}
	
	//Spawn failed, log spawner name with warning
	const FString logErrorMessage = FString::Printf(TEXT("Character spawn failed at : %s"), *this->GetName());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *logErrorMessage);
	return nullptr;
}

void ABaseSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	AGameStateBase* pGameState = GetWorld()->GetGameState();

	//Register spawner in game state
	if(pGameState->Implements<UGameStateInterface>())
	{
		IGameStateInterface::Execute_AddSpawner(pGameState, this);
	}
}

bool ABaseSpawner::GetIsPlayerSpawner()
{
	return bIsPlayerSpawner;
}

