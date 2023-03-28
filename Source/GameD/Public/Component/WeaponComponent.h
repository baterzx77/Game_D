// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameD/GameDCharacter.h"
#include "WeaponComponent.generated.h"

USTRUCT()
struct FSpecialWeaponAbility
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int32 ID;

	UPROPERTY(EditAnywhere)
		float STR;

	UPROPERTY(EditAnywhere)
		float AGY;

	UPROPERTY(EditAnywhere)
		float MAG;

	UPROPERTY(EditAnywhere)
		float CriticalChance;

	UPROPERTY(EditAnywhere)
		float CriticalMultiplier;

	UPROPERTY(EditAnywhere)
		float IncreaseAttackSpeed;

	UPROPERTY(EditAnywhere)
		UDamageType* DamageType;

	void SetAbilityFunc() {};

	void SetDamageType() {};
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMED_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

	UPROPERTY(EditAnywhere)
		float Damage = 1.f;

	UPROPERTY(EditAnywhere)
		bool SplashDamage = false;

	UPROPERTY(EditAnywhere)
		float AngleSplashDamage = false;

	UPROPERTY(EditAnywhere)
		float DamageAttackSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
		float Weight = 1.0f;

	UPROPERTY(EditAnywhere)
		FSpecialWeaponAbility WeaponSpecialAbility;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDamageType> DamageType;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//For Weapon Component

	void Attack(AActor* EnemyActor, AController* PlayerController);
	
	bool CheckDistance(AActor* EnemyActor, AGameDCharacter* Character);

	//void TakeDamage();

	void Cooldown(float CDTime);

	//���������� ��� �����, ������� ����� ��������������.����� ���� ������ ������������ ����� �������� ��� �������� ���, ���������� ����� ��� ������ ���� ����.
	void DetermineAttackType();

	//�������� ������ ��� �����, ������ �� ������� ��������.��������, ���� ���� ��������� ������, �� ����� ���� ������� ������ ��� �������� ���, � ���� ���� ������� ������, �� ����� ���� ������� ������ ��� �������� ���.
	void ChooseWeapon();

	float CalculateDamage(AActor* EnemyActor);

	void CheckAmmo();

};
