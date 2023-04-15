// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BaseWeapon.h"
#include "EnemyActor_D.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/*CapsuleCollison = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = CapsuleCollison;*/

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(RootComponent);


	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseWeapon::OnOverlapBegin);
}

void ABaseWeapon::StopFire()
{
	IsAttacking = false;
}

void ABaseWeapon::StartFire()
{
	IsAttacking = true;
}

void ABaseWeapon::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AEnemyActor_D* EnemyActor = Cast<AEnemyActor_D>(OtherActor);
	if (OtherActor == EnemyActor && IsAttacking)
	{
		OtherActor->Destroy();
		IsAttacking = false;
	}
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

