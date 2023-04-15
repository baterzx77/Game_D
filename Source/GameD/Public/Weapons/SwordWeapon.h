// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "SwordWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GAMED_API ASwordWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
public:

	ASwordWeapon();

	virtual void StartFire() override;

protected:

};
