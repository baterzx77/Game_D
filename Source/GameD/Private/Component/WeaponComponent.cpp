// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/WeaponComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameD/Public/EnemyActorD/EnemyActor_D.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}

void UWeaponComponent::Attacks()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->StartFire();
	//UGameplayStatics::ApplyDamage(EnemyActor, CalculateDamage(EnemyActor),GetOwner()->GetInstigatorController(), GetOwner()->GetInstigator(), DamageType);
}

void UWeaponComponent::AttackEnd()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->StopFire();
}

bool UWeaponComponent::CheckDistance()
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

void UWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;
	CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	if (CurrentWeapon)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, "WeaponSocket");
	}
}