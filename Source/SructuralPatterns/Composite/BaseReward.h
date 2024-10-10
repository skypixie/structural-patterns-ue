// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Composite/RewardTree.h"

#include "BaseReward.generated.h"


/**
 * 
 */
UCLASS()
class SRUCTURALPATTERNS_API UBaseReward : public UObject
{
	GENERATED_BODY()

public:

    UFUNCTION()
    virtual TArray<UBaseReward*>& GetReward();

    RewardType Type = RewardType::None;

    TArray<UBaseReward*> Rewards;
	
};
