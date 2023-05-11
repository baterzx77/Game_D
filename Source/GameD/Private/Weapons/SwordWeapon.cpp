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
	IsAttacking = true;
	
	

	UE_LOG(LogTemp, Warning, TEXT("Activate Overlaped Component"));

	//SkeletalMesh->OnComponentBeginOverlap.Clear()
	/*AGameDCharacter* Character = Cast<AGameDCharacter>(GetOwner());
	if (!Character)
	{
		UE_LOG(LogTemp, Warning,TEXT("None Character awayable"));
		IsAttacking = false;
		return;
	}

	Character->PlayAnimMontage(AnimMontage);*/

}

void ASwordWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEnemyActor_D* EnemyActor = Cast<AEnemyActor_D>(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("Base Overlaped Component"));
	if (OtherActor == EnemyActor && IsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Do Damage Overlaped Component"));
		/*OtherActor->Destroy();
		IsAttacking = false;
		SkeletalMesh->OnComponentBeginOverlap.Clear();*/
		MeleeWeapon_OnHit.Broadcast(SweepResult.GetActor(), SweepResult.GetComponent(), SweepResult.ImpactPoint, SweepResult.ImpactNormal, SweepResult.BoneName, SweepResult);

	}
	
	
}
