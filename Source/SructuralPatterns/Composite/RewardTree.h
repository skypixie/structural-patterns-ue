// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RewardTree.generated.h"

class UBaseReward;

UENUM()
enum class RewardType : uint8
{
    Gold,
    Gem,
    Chest,
    None,
};

/**
 * 
 */
UCLASS()
class SRUCTURALPATTERNS_API URewardTree : public UObject
{
	GENERATED_BODY()

public:

    UBaseReward* Reward = nullptr;

    TArray<UBaseReward*> GetRewards();
	
};
