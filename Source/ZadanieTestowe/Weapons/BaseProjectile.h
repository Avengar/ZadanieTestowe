// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BaseProjectile.generated.h"

UCLASS()
class ZADANIETESTOWE_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void DestroyProjectile();

public:
	/**Set on spawn. How fast projectile will fly*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float ProjectileSpeed;
	
protected:
	/**Component responsible for movement of this actor*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* ProjectileMovementComponent;

	/**Mesh representing projectile in game world*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ProjectileMesh;

	/**How much damage we will deal on impact with enemy*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 ProjectileDamage;

	/**How long projectile will exist in seconds before being destroyed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ProjectileLifeSpan;

private:
	/**Timer handle used for destroying projectile after lifespan expires*/
	FTimerHandle m_lifespanTimerHandle;
};