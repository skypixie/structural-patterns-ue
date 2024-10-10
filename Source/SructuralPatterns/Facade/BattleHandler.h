// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleHandler.generated.h"

class AMapHandler;
class AEnemySpawner;


UCLASS()
class SRUCTURALPATTERNS_API ABattleHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleHandler();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* SMComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMapHandler* MapHandler = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AEnemySpawner* EnemySpawner = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnemiesAreDead = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void StartBattle();

	UFUNCTION()
	void EndBattle();

};
