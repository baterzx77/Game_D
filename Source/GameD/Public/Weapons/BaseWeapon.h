// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Animation/AnimMontage.h"
#include "BaseWeapon.generated.h"

UCLASS()
class GAMED_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	

	ABaseWeapon();

	virtual void StartFire();

	virtual void StopFire();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
	bool IsAttacking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component");
	USkeletalMeshComponent* SkeletalMesh;

	UWorld* GetBaseWorld() { return GetWorld(); }

	AActor* GetBaseCharacter() { return GetOwner(); }

	FTimerHandle TimerHandler;

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlapBegin(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

};
