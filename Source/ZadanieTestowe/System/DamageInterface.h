// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *Interface responsible for dealing damage on implementing actors.
 */
class ZADANIETESTOWE_API IDamageInterface
{
	GENERATED_BODY()

public:
	/**Called when we want to deal damage to implementing actor*/
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void DealDamage(int32 DamageValue);
	virtual void DealDamage_Implementation(int32 DamageValue) {};
};
