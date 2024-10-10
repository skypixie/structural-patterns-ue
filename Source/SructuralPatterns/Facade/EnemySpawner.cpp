// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/EnemySpawner.h"
#include "Facade/Enemy.h"
#include "Facade/BattleHandler.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Box"));
    SpawnBox->SetupAttachment(GetRootComponent());
    SpawnBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SpawnBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

    CurNumEnemies = EnemiesToSpawnNum;
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::SpawnEnemies()
{
    for (int i = 0; i < EnemiesToSpawnNum; ++i)
    {
        FVector SpawnLocation = FMath::RandPointInBox(SpawnBox->GetNavigationBounds());
        FTransform SpawnTransform(SpawnLocation);
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AEnemy* newEnemy = Cast<AEnemy>(GetWorld()->SpawnActor(EnemyClass, &SpawnTransform, SpawnParams));
        if (newEnemy)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Screen Message"));
            newEnemy->ParentSpawner = this;
        }
    }
}

void AEnemySpawner::EnemyDestroyed()
{
    CurNumEnemies -= 1;
    if (CurNumEnemies <= 0)
    {
        if (IsValid(ParentBattleHandler))
        {
            ParentBattleHandler->bEnemiesAreDead = true;
            ParentBattleHandler->EndBattle();
        }
    }
}

