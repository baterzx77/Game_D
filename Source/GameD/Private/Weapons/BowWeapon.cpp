// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BowWeapon.h"
#include "Weapons/Arrows.h"
#include "GameFramework/Character.h"

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
	SpawnArrow(gg, gg);
}

void ABowWeapon::SpawnArrow(FVector TraceStart, FVector TraceEnd)
{
}
