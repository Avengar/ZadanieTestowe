// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

#include "ZadanieTestowe/System/DamageInterface.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
	//Projectile setup
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 1500.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	//Mesh component setup
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	SetRootComponent(ProjectileMesh);
	ProjectileMesh->SetEnableGravity(false);
	
	//Collision response channels
	FCollisionResponseContainer collisionResponseContainer;
	collisionResponseContainer.SetAllChannels(ECR_Ignore);
	collisionResponseContainer.SetResponse(ECC_Pawn,ECR_Block);
	collisionResponseContainer.SetResponse(ECC_WorldStatic,ECR_Block);
	ProjectileMesh->SetCollisionResponseToChannels(collisionResponseContainer);
	
	//Bind hit event from Mesh, to handle ProjectileHitting
	ProjectileMesh->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnProjectileHit);
	
	//Base projectile damage
	ProjectileDamage = 50;
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Check if hit actor is valid
	if(IsValid(OtherActor) == false)
	{
		return;
	}

	//If hit actor implements damage interface, we want to deal damage to him
	if(OtherActor->GetClass()->ImplementsInterface(UDamageInterface::StaticClass()))
	{
		IDamageInterface::Execute_DealDamage(OtherActor, ProjectileDamage);
	}

	//Destroy bullet on hit even if no damage was dealt
	this->Destroy();
}

