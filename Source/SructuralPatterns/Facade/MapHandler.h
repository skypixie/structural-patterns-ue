// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapHandler.generated.h"

class ADoor;

UCLASS()
class SRUCTURALPATTERNS_API AMapHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapHandler();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ADoor*> Doors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OpenDoors();

};
