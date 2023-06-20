// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "MeleeWeapon.h"
#include "SwordWeapon.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FMeleeHitSignature, class AActor*, HitActor,
	class UPrimitiveComponent*, HitComponent, const FVector&, ImpactPoint, const FVector&, ImpactNormal, FName, HitBoneName, const struct FHitResult&, HitResult);
/**
 * 
 */
UCLASS()
class GAMED_API ASwordWeapon : public AMeleeWeapon
{
	GENERATED_BODY()
	
public:

	ASwordWeapon();

	virtual void StartFire() override;

	virtual void StopFire() override;

	FMeleeHitSignature MeleeWeapon_OnHit;

protected:

		virtual void OnOverlapBegin(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult) override;
};
