// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameDCharacter.generated.h"

class UWeaponComponent;

UCLASS(config=Game)
class AGameDCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AGameDCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

public:

	//Методы и функции для захвата цели при включенном захвате цели
	//Выбрать цель для автонаведения или фиксации на цели

	UPROPERTY(EditAnywhere)//, meta = TEXT("SelectTarget"))
		bool SetSelectTargetMode = false;

	UPROPERTY()
		TArray<AActor*> EnemyActorArrayToSelect;

	UPROPERTY()
		int32 CurrentTargetNum;

	UPROPERTY(EditAnywhere)//, meta = TEXT("SpecialAbilities"))
		float Radius = 0;

	void GetAllActorInArea(TArray<AActor*> &EnemyActorInRange);

	void SelectTarget();

	void SwitchTarget(int32 CurrentTargetNum);

	bool CheckIfTargetIsDead(AActor* EnemyActor);

	bool CheckLineOfSingt(AActor* EnemyActor);



	void Attack(AActor* EnemyActor);

	//void TakeDamage();

	void CheckHealth();

	void Death();



	void UseAbility(int32 AbilityID);

	void Cooldown(float CDTime);

	bool Interrupt();

	void SelectStrategy();

	void DetermineAttackType();

	void CheckEnemyType();

	void ChooseWeapon();

	float CalculateDamage();

	bool Dodge();

	bool Parry();

	void ApplyStatusEffect(int32 StatusID);

	void UseConsumable(int32 ID);

	void CheckAmmo();

	void UpdateHUD();

	void UseSkill(int32 ID);

	//void Retreat();

	void UpdateAI();

	void ApplyHealing(float Heal);

	void CollectByAttraction();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	UWeaponComponent* WComp;

	
};

