// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameDGameMode.h"
#include "GameDCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameDGameMode::AGameDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
