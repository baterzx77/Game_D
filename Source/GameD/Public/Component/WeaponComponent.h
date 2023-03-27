// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameD/GameDCharacter.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMED_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//For Weapon Component

	void Attack(AActor* EnemyActor);
	
	bool CheckDistance(AActor* EnemyActor, AGameDCharacter* Character);

	//void TakeDamage();

	void Cooldown(float CDTime);

	void DetermineAttackType();

	void ChooseWeapon();

	float CalculateDamage();

	void CheckAmmo();

};