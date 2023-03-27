// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMED_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere)
		float Health;

	UPROPERTY(EditAnywhere)
		float MaxHealth;

	UPROPERTY(EditAnywhere)
		float Mana;

	UPROPERTY(EditAnywhere)
		float MaxMana;

	UPROPERTY(EditAnywhere)
		float Stamina;

	UPROPERTY(EditAnywhere)
		float MaxStamina;

	UPROPERTY(EditAnywhere)
		bool IsDead = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//For Health Component

	float GetHealth();

	void Death();

	void ApplyRestore(float Restore);

	void ApplyStatusEffect(TArray<AActor*> &ID, int32 StatusID);
};
