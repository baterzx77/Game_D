// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActorD/EnemyActor_D.h"
#include "SwordWeapon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyActor_D::AEnemyActor_D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyActor_D::BeginPlay()
{
	Super::BeginPlay();
	
	MeleeWeaponComponent->MeleeWeapon_OnHit.AddDynamic(this, &AEnemyActor_D::RespondMeleeDamageTaken);
}

float AEnemyActor_D::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return 0;
}

void AEnemyActor_D::LogPrint(char st[])
{
	//UE_LOG(LogTemp, Warning, TEXT(char[]));
}

// Called every frame
void AEnemyActor_D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyActor_D::RespondMeleeDamageTaken(AActor* HitActor, UPrimitiveComponent* HitComponent, const FVector& ImpactPoint, const FVector& ImpactNormal, FName HitBoneName, const FHitResult& HitResult)
{

}

