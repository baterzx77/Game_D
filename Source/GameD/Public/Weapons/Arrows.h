// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "Arrows.generated.h"

class UProjectileMovementComponent;

/**
 * 
 */
UCLASS()
class GAMED_API AArrows : public ABaseWeapon
{
	GENERATED_BODY()
	
public:
	AArrows();
	void SetShotDirection(const FVector& Direction) { ShotDirection = Direction; }

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		UProjectileMovementComponent* MovementComponent;
protected:
	FVector ShotDirection;
};
