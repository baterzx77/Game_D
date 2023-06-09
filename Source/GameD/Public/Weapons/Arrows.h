// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "RangedWeapon.h"
#include "Arrows.generated.h"

class UProjectileMovementComponent;

/**
 * 
 */
UCLASS()
class GAMED_API AArrows : public ARangedWeapon
{
	GENERATED_BODY()
	
public:
	AArrows();
	void SetShotDirection(const FVector& Direction) { ShotDirection = Direction; }

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		UProjectileMovementComponent* MovementComponent;

	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;
protected:
	FVector ShotDirection;
};
