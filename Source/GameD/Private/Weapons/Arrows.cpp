// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Arrows.h"
#include "GameFramework/ProjectileMovementComponent.h"

AArrows::AArrows()
{
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
}
