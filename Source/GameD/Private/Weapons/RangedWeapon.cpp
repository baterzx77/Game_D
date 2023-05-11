// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/RangedWeapon.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

FVector ARangedWeapon::GetMuzzleWorldLocation(USkeletalMeshComponent* SkeletalMeshComp, FName Socket) const
{
    return SkeletalMeshComp->GetSocketLocation(Socket);
}

bool ARangedWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewPoint;
	FRotator ViewRotation;

	const auto Player = Cast<ACharacter>(GetOwner());

	if (!Player) { UE_LOG(LogTemp, Warning, TEXT("GetTraceData No Player")); return false; }

	const auto Controller = Player->GetController<APlayerController>();
	

	if (!Controller) { UE_LOG(LogTemp, Warning, TEXT("GetTraceData No Controller")); return false; }

	Controller->GetPlayerViewPoint(ViewPoint, ViewRotation);

	TraceStart = ViewPoint;
	const FVector ShootDirection = ViewRotation.Vector();
	TraceEnd = TraceStart + ShootDirection * 4000;
	return true;
}
