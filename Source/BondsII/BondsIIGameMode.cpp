// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BondsII.h"
#include "BondsIIGameMode.h"
#include "BondsIIHUD.h"
#include "BondsIICharacter.h"

ABondsIIGameMode::ABondsIIGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABondsIIHUD::StaticClass();
}
