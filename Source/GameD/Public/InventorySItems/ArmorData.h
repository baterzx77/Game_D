// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ArmorData.generated.h"

USTRUCT(BlueprintType)
struct FArmorData : public FTableRowBase
{
	GENERATED_BODY()
	
public:	

	FArmorData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ArmorID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PhisicalDefence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MagicDefence;
};
