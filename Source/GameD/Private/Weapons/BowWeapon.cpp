// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BowWeapon.h"
#include "Weapons/Arrows.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void ABowWeapon::StartFire()
{
	if (!GetWorld()) return;
	Arrows = GetWorld()->SpawnActor<AArrows>(Arrow);

	//if (IsEmpty()) return;

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	if (Arrows)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		Arrows->AttachToComponent(SkeletalMesh, AttachmentRules, "ArrowSocket");
	}
}

void ABowWeapon::StopFire()
{
	FVector gg = { 0,0,0 };

	if (!GetWorld()) return;
	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd)) return;
	SpawnArrow(TraceStart, TraceEnd);
}

void ABowWeapon::SpawnArrow(FVector TraceStart, FVector TraceEnd)
{
	FHitResult HitResult;
	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
	const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

	AArrows* Projectile = GetWorld()->SpawnActorDeferred<AArrows>(Arrow, SpawnTransform);

	if (Projectile)
	{
		Projectile->SetShotDirection(Direction);
		Projectile->FinishSpawning(SpawnTransform);
	}
	
}

FVector ABowWeapon::GetMuzzleWorldLocation() const
{
	return SkeletalMesh->GetSocketLocation("ArrowSocket");
}

bool ABowWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewPoint;
	FRotator ViewRotation;

	const auto Player = Cast<ACharacter>(GetOwner());

	if (!Player) return false;

	const auto Controller = Player->GetController<APlayerController>();

	if (!Controller) return false;

	Controller->GetPlayerViewPoint(ViewPoint, ViewRotation);

	TraceStart = ViewPoint;
	const FVector ShootDirection = ViewRotation.Vector();
	TraceEnd = TraceStart + ShootDirection * 4000;
	return true;

}
