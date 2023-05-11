// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "RangedWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GAMED_API ARangedWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
public:

	FVector GetMuzzleWorldLocation(USkeletalMeshComponent* SkeletalMeshComp, FName Socket) const;

	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
};
