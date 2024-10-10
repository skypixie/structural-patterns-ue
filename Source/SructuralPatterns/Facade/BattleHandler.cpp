// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/BattleHandler.h"
#include "Facade/MapHandler.h"
#include "Facade/EnemySpawner.h"


/*
* Данный паттерн может использоваться для чего-то,
* что требует много действий с разными объектами.
* Например, когда персонаж использует определенную способность,
* надо сказать фасаду, чтобы он выполнил соответствующую ф-ю,
* которая должна выполнить много действий.
* Например, разбросать обломков рядом с игроком,
* заставить нпс разбегаться от ужаса,
* поджечь врагов,
* поменять постобработку,
* включить какие-то страшные звуки, музыку и тп.
*/

/*
* В моем случае, я использую фасад BattleHandler,
* чтобы создавать врагов и управлять дверьми на карте,
* но при желании можно легко добавить новые функции.
*/

// Sets default values
ABattleHandler::ABattleHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SMComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SMComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SMComp->SetupAttachment(GetRootComponent());
	SMComp->OnComponentBeginOverlap.AddDynamic(this, &ABattleHandler::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ABattleHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleHandler::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	StartBattle();
    if (IsValid(SMComp))
    {
        SMComp->DestroyComponent();
    }
}

void ABattleHandler::StartBattle()
{
    if (IsValid(EnemySpawner))
    {
        EnemySpawner->SpawnEnemies();
    }
}

void ABattleHandler::EndBattle()
{
	if (IsValid(MapHandler) && bEnemiesAreDead)
	{
		MapHandler->OpenDoors();
	}
}
