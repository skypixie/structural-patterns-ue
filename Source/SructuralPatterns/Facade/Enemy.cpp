// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/Enemy.h"
#include "Facade/EnemySpawner.h"
#include "SructuralPatternsProjectile.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
    SMComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SMComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SMComp->SetupAttachment(GetRootComponent());
    SMComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    ASructuralPatternsProjectile* Projectile = Cast<ASructuralPatternsProjectile>(OtherActor);
    if (IsValid(Projectile))
    {
        if (IsValid(ParentSpawner))
        {
            ParentSpawner->EnemyDestroyed();
        }
        Destroy();
    }
}

