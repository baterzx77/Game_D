// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase()
{
	/*static ContructurHelpers::FObjectFinder<UDatatable>BP_ItemDB(TEXT("DataTable'/Game/Data/ItemDB.ItemDB'"));
	ItemDB = BP_ItemDB.Object;*/
}

UDataTable* AMyGameStateBase::GetItemDB() const
{
	return ItemDB;
}
