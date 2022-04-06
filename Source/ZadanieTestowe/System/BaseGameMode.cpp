// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"

ABaseGameMode::ABaseGameMode()
{
	//Set our GameState class as default
	GameStateClass = ABaseGameState::StaticClass();
}
