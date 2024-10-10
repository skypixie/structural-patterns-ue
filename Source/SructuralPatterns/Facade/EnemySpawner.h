// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"


class UBoxComponent;
class AEnemy;
class ABattleHandler;

UCLASS()
class SRUCTURALPATTERNS_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ABattleHandler* ParentBattleHandler = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UBoxComponent* SpawnBox = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AEnemy> EnemyClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 EnemiesToSpawnNum = 3;

    UPROPERTY()
    int32 CurNumEnemies = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    void SpawnEnemies();

    UFUNCTION(BlueprintCallable)
    void EnemyDestroyed();

};
