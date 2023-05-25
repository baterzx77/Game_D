// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "WeaponData.generated.h"

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	FWeaponData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PhisicalAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MagicAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PhisicalPenetration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MagicPenetration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CriticalChance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;

};
