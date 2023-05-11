// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyGameStateBase.h"
#include "GameDCharacter.h"

AMyPlayerController::AMyPlayerController()
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

void AMyPlayerController::ReloadInventory()
{
}

int32 AMyPlayerController::GetInventoryWeight()
{
	int32 Weight = 0;
	for(auto& Item:Inventory)
	{
		Weight += Item.Weight;
	}
	return Weight;
}

bool AMyPlayerController::AddItemToInventoryByID(FName ID)
{
	AMyGameStateBase* GameState = Cast<AMyGameStateBase>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

void AMyPlayerController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &AMyPlayerController::Interact);
}
