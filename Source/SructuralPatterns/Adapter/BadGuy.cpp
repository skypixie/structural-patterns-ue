// Fill out your copyright notice in the Description page of Project Settings.


#include "Adapter/BadGuy.h"

// Sets default values
ABadGuy::ABadGuy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABadGuy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABadGuy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABadGuy::ShootHero()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("ABadGuy::ShootHero"));
}

