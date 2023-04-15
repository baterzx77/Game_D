// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "BowWeapon.generated.h"

class AArrows;

/**
 * 
 */
UCLASS()
class GAMED_API ABowWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
public:

	virtual void StopFire() override;

	virtual void StartFire() override;

	void SpawnArrow(FVector TraceStart, FVector TraceEnd);

	void GetArrowAndPull();

	UPROPERTY(EditAnywhere)
		AArrows* Arrows;

	UPROPERTY(EditAnywhere)
		 TSubclassOf<AArrows> Arrow;

	FVector GetMuzzleWorldLocation() const;
	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
};
