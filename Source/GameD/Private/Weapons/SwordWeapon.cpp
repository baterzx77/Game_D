// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/SwordWeapon.h"
#include "GameD/GameDCharacter.h"
#include "EnemyActor_D.h"



ASwordWeapon::ASwordWeapon()
{
	SkeletalMesh->OnComponentBeginOverlap.AddDynamic(this, &ASwordWeapon::OnOverlapBegin);
}

void ASwordWeapon::StartFire()
{
	if (!IsAttacking) 
	{
		IsAttacking = true;
		UE_LOG(LogTemp, Warning, TEXT("Activate Overlaped Component & set timer duration 1 sec"));

		GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &ASwordWeapon::StopFire, 2.0f);

	}
}

void ASwordWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	AEnemyActor_D* EnemyActor = Cast<AEnemyActor_D>(OtherActor);

	if (OtherActor == EnemyActor && IsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Do Damage Overlaped Component"));
		TSubclassOf<UDamageType> DM;
		UGameplayStatics::ApplyDamage(OtherActor, 1.0f, GetOwner()->GetInstigatorController(), this, DM);
	}
	else if (OtherActor == EnemyActor && !IsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Base Overlaped Component without attack"));
	}
	
}

void ASwordWeapon::StopFire()
{
	IsAttacking = false;
	UE_LOG(LogTemp, Warning, TEXT("Attacking false"));
}