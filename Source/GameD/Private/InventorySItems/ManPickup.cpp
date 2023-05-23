// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySItems/ManPickup.h"
#include "MyPlayerController.h"
#include "InventorySItems/InventoryItem.h"
#include "InventorySItems/Interactable.h"

AManPickup::AManPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");

	Super::Name = "Item";
	Super::Action = "pickup";
}

void AManPickup::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);

	AMyPlayerController* ICOntroller = Cast<AMyPlayerController>(Controller);

	if (ICOntroller->AddItemToInventoryByID(ItemID))
	Destroy();
}
