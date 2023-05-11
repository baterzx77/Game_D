// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BowWeapon.h"
#include "Weapons/Arrows.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void ABowWeapon::StartFire()
{
	if (!GetBaseWorld()) return;
	Arrows = GetBaseWorld()->SpawnActor<AArrows>(Arrow);

	//if (IsEmpty()) return;

	ACharacter* Character = Cast<ACharacter>(GetBaseCharacter());
	if (!Character) return;

	if (Arrows)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		Arrows->AttachToComponent(SkeletalMesh, AttachmentRules, "ArrowSocket");
	}
	//Створити функцію натяжіння 
	// GetArrowAndPull
	//Задати таймер на функцію натяжіння
}

void ABowWeapon::StopFire()
{
	//закінчити таймер, зберегти силу натяжіння (швидкість). 
	//Просчитати коли видяляти об'єкт на акторі і строрювати актора для польоту

	if (!GetBaseWorld()) return;
	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd)) return;
	SpawnArrow(TraceStart, TraceEnd);
}

void ABowWeapon::SpawnArrow(FVector TraceStart, FVector TraceEnd)
{
	FHitResult HitResult;
	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation(SkeletalMesh,"ArrowSocket"));
	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
	const FVector Direction = (EndPoint - GetMuzzleWorldLocation(SkeletalMesh, "ArrowSocket")).GetSafeNormal();

	AArrows* Projectile = GetBaseWorld()->SpawnActorDeferred<AArrows>(Arrow, SpawnTransform);

	if (Projectile)
	{
		Projectile->SetShotDirection(Direction);
		Projectile->FinishSpawning(SpawnTransform);
	}
	
}

void ABowWeapon::GetArrowAndPull()
{
}
