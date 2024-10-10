// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SMComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SMComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::Open()
{
	// replace nullptr with the structure
	AddActorWorldOffset(OpenHeight, true, nullptr, ETeleportType::TeleportPhysics);
}

