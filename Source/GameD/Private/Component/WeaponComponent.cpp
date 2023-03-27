// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/WeaponComponent.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::Attack(AActor* EnemyActor)
{
	//CheckDistance(EnemyActor,)
	
}

bool UWeaponComponent::CheckDistance(AActor* EnemyActor, AGameDCharacter* Character)
{
	return false;
}

void UWeaponComponent::Cooldown(float CDTime)
{
}

void UWeaponComponent::DetermineAttackType()
{
}

void UWeaponComponent::ChooseWeapon()
{
}

float UWeaponComponent::CalculateDamage(FSpecialWeaponAbility* WeaponSpecialAbility, UDamageType* DamageType, UDamageType* EnemyDamageResist, int32 CharSTR, int32 CharAGY, int32 MAG, AActor* EnemyActor)
{
	
	Damage += (WeaponSpecialAbility.STR +CharSTR) * 1;
	Damage += (WeaponSpecialAbility.STR) * 1;
	Damage += WeaponSpecialAbility.AGY * 1;
	Damage += WeaponSpecialAbility.MAG * 1;
	return Damage;
}

void UWeaponComponent::CheckAmmo()
{
}

