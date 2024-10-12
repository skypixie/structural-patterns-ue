// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BagGuyToEnemy_Adapter.generated.h"


class ABadGuy;
class ABaseEnemy;


UCLASS()
class SRUCTURALPATTERNS_API ABagGuyToEnemy_Adapter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABagGuyToEnemy_Adapter();

    ABadGuy* BadGuy = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void SetBadGuy(ABadGuy* BadGuy_);

    UFUNCTION()
    void Attack();

};
