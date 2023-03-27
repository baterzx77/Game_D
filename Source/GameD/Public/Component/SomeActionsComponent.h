// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SomeActionsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMED_API USomeActionsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USomeActionsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	//For Any Actions

	bool Interrupt(AActor* EnemyActor);

	void SelectStrategy(AActor* SetActorToEditStrategy);

	void CheckEnemyType(AActor* EnemyActor);

	bool Dodge(float Acrobatic);

	bool ManualDodge(float Acrobatic);

	bool Parry(AActor* EnemyActor, float ParryChance);

	bool ManualParry(AActor* EnemyActor, float OwnParryRange);

	void UseConsumable(int32 ID);

	void UpdateHUD();

	void UseSkill(int32 ID, AActor* OnUseActor);

	void UseAbility(int32 AbilityID, AActor* OnUseActor);

	void UpdateAI();
};
