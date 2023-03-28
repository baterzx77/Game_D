// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActorD/EnemyActor_D.h"

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
	
}

// Called every frame
void AEnemyActor_D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

