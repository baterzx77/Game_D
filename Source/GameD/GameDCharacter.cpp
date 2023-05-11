// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameDCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Component/WeaponComponent.h"
#include "Public/InventorySItems/Interactable.h"
#include "Public/InventorySItems/AutoPickup.h"
#include "Public/InventorySItems/InventoryItem.h"
#include "Public/MyPlayerController.h"



//////////////////////////////////////////////////////////////////////////
// AGameDCharacter

AGameDCharacter::AGameDCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	WComp = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");
	
	//init collectable sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);


}

//////////////////////////////////////////////////////////////////////////
// Input

void AGameDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CollectAutoPickups();
	CheckForInteractables();

}

void AGameDCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	check(WComp);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGameDCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameDCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGameDCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGameDCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AGameDCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AGameDCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AGameDCharacter::OnResetVR);

	PlayerInputComponent->BindAction("jj", IE_Pressed, WComp, &UWeaponComponent::Attacks);
}

void AGameDCharacter::CollectAutoPickups()
{
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	AMyPlayerController* IController = Cast<AMyPlayerController>(GetController());

	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected)
	{
		AAutoPickup* const TestPickup = Cast<AAutoPickup>(CollectedActors[iCollected]);
		if (TestPickup && !TestPickup->IsPendingKill())
		{
			TestPickup->Collect(IController);
		}
	}
}

void AGameDCharacter::CheckForInteractables()
{
	FHitResult HitResult;

	int32 Range = 500;

	FVector StartTrace = FollowCamera->GetComponentLocation();
	FVector EndTrace = (FollowCamera->GetForwardVector() * Range) + StartTrace;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	AMyPlayerController* IController = Cast<AMyPlayerController>(GetController());

	if (IController)
	{
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			AInteractable* Interactable = Cast<AInteractable>(HitResult.GetActor());

			if (Interactable)
			{
				IController->CurrentInteractable = Interactable;
				return;
			}
		}

		IController->CurrentInteractable = nullptr;
	}
}

void AGameDCharacter::CollectByAttraction()
{
	//UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Collactable", EnemyActorArrayToSelect);

	//for (size_t i = 0; i < EnemyActorArrayToSelect.Num(); i++)
	//{
	//	if (GetDistanceTo(EnemyActorArrayToSelect[i])<Radius)
	//	{
	//		//AItem* Item = Cast<CollactableItem>(EnemyActorArrayToSelect[i]);
	//		//Item->Attract();
	//	}
	//}

	//or by delegate

	/*if (AttractableItem->GetDistanceTo(this) < Radius) {
		AttractableItem.Attract(this);
	}*/
}

void AGameDCharacter::OnResetVR()
{
	// If GameD is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in GameD.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AGameDCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AGameDCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AGameDCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGameDCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AGameDCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AGameDCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
