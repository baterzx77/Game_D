// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SelectTypeGameComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMED_API USelectTypeGameComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USelectTypeGameComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int32 CurrentTarget;
	int32 AliveEnemyInRange;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//For Select type game

	void GetAllActorInArea(TArray<AActor*>& EnemyActorInRange);

	//FVector SwitchTarget(TArray<AActor*>& EnemyActorInRange);

	bool CheckIfTargetIsDead(AActor* EnemyActor);

	bool CheckLineOfSingt(AActor* EnemyActor);
		
};
