// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MeleeWeapon.h"
#include "SwordWeapon.h"
#include "EnemyActor_D.generated.h"

UCLASS()
class GAMED_API AEnemyActor_D : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor_D();

	UPROPERTY()
		UDamageType* DamageType;

	UPROPERTY()
		float PhisicalResist;

	UPROPERTY()
		float FireMagicResist;

	UPROPERTY()
		float IceMagicResist;

	UPROPERTY()
	float Health = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void LogPrint(char st[]);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ASwordWeapon* MeleeWeaponComponent;
	

	UFUNCTION()
		void RespondMeleeDamageTaken(AActor* HitActor, UPrimitiveComponent* HitComponent, const FVector& ImpactPoint, const FVector& ImpactNormal, FName HitBoneName, const FHitResult& HitResult);

};
