// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Composite/BaseReward.h"
#include "ChestReward.generated.h"

/**
 * 
 */
UCLASS()
class SRUCTURALPATTERNS_API UChestReward : public UBaseReward
{
	GENERATED_BODY()

public:

    UChestReward();

    virtual TArray<UBaseReward*>& GetReward() override;

    void SetRewards(TArray<UBaseReward*>& RewardsToAdd);
	
};
