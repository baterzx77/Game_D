// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/WeaponComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameD/Public/EnemyActorD/EnemyActor_D.h"

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

void UWeaponComponent::Attack(AActor* EnemyActor,AController* PlayerController)
{
	UGameplayStatics::ApplyDamage(EnemyActor, CalculateDamage(EnemyActor),GetOwner()->GetInstigatorController(), GetOwner()->GetInstigator(), DamageType);
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

float UWeaponComponent::CalculateDamage(AActor* EnemyActor)
{
	AEnemyActor_D* EActor = Cast<AEnemyActor_D>(EnemyActor);
	EActor->PhisicalResist > Damage ? Damage = 0.f:Damage = Damage - EActor->PhisicalResist;
	EActor->FireMagicResist > Damage ? Damage = 0.f : Damage += Damage - EActor->FireMagicResist;
	EActor->IceMagicResist > Damage ? Damage = 0.f : Damage += Damage - EActor->IceMagicResist;
	return Damage;
}

void UWeaponComponent::CheckAmmo()
{
}

