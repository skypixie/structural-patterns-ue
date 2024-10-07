// Copyright Epic Games, Inc. All Rights Reserved.

#include "SructuralPatternsGameMode.h"
#include "SructuralPatternsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASructuralPatternsGameMode::ASructuralPatternsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
