// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySItems/AutoPickup.h"
#include "MoneyAutoPickup.generated.h"

/**
 * 
 */
UCLASS()
class GAMED_API AMoneyAutoPickup : public AAutoPickup
{
	GENERATED_BODY()
	
public:
	AMoneyAutoPickup();

	void Collect_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;
};
