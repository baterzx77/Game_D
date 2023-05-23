// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySItems/InventoryItem.h"

FInventoryItem::FInventoryItem()
{
	this->Name = FText::FromString("No name");
	this->Weight = 1;
	this->Value = 1;
	this->Description = FText::FromString("No Decription");
}
