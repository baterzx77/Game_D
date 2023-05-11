// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Arrows.h"
#include "GameFramework/ProjectileMovementComponent.h"

AArrows::AArrows()
{
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
}

void AArrows::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("\s is shooted by \s"), (OtherActor->GetName(), GetName()));
	Destroy();
	
}
