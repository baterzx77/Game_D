// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutoPickup.generated.h"

UCLASS()
class GAMED_API AAutoPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutoPickup();

	UFUNCTION(BlueprintNativeEvent)
		void Collect(APlayerController* Controller);

	virtual void Collect_Implementation(APlayerController* Controller);

	FName GetItemID();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
