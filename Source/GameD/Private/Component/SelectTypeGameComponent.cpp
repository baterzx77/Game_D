// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SelectTypeGameComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameD/GameDCharacter.h"

// Sets default values for this component's properties
USelectTypeGameComponent::USelectTypeGameComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USelectTypeGameComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USelectTypeGameComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USelectTypeGameComponent::GetAllActorInArea(TArray<AActor*>& EnemyActorInRange)
{
	//if ( SelectTypeGame )
	EnemyActorInRange.Empty();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "NearPlayer", EnemyActorInRange);
	for (AActor* EnemyActor:EnemyActorInRange)
	{
		if (EnemyActor != nullptr) {
			AActor* EA = Cast<AActor>(EnemyActor);
			if (CheckLineOfSingt(EnemyActor))
			{

			}
			
		}

	}
}

//FVector USelectTypeGameComponent::SwitchTarget(TArray<AActor*>& EnemyActorInRange)
//{
//	//if (EnemyActorInRange.Num() == 0) return;
//		for (int32 i = CurrentTarget; i < EnemyActorInRange.Num(); i++)
//		{
//			if (CurrentTarget == EnemyActorInRange.Num() - 1 && AliveEnemyInRange != 1)
//			{
//				i = 0;
//			}
//			else if (AliveEnemyInRange == 1)
//			{
//				CurrentTarget = i;
//			}
//			else
//			{
//				AActor* EA = Cast<AActor>(EnemyActorInRange[i]);
//				//if (EnemyActorInRange[i]->IsDead() == true) continue;
//				CurrentTarget = i;
//				return EA->GetActorLocation();
//			}
//		}
//}

bool USelectTypeGameComponent::CheckIfTargetIsDead(AActor* EnemyActor)
{
	return false;
}

bool USelectTypeGameComponent::CheckLineOfSingt(AActor* EnemyActor)
{
	FHitResult Hit;
	FVector vec;
	FCollisionQueryParams CollisionParams;
	EnemyActor->ActorLineTraceSingle(Hit, vec, EnemyActor->GetActorLocation() * 100, ECC_Visibility, CollisionParams);
	if (Hit.bBlockingHit)
	{
		return false;;
	}
	else
	{
		return true;
	}
}

