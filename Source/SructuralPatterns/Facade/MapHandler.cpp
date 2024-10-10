// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/MapHandler.h"
#include "Facade/Door.h"

// Sets default values
AMapHandler::AMapHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapHandler::OpenDoors()
{
	for (auto Door : Doors)
	{
		if (IsValid(Door))
		{
			Door->Open();
		}
	}
}

