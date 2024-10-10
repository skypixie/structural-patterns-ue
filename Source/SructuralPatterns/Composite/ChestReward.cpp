// Fill out your copyright notice in the Description page of Project Settings.


#include "Composite/ChestReward.h"

UChestReward::UChestReward()
{
    Type = RewardType::Chest;
}

TArray<UBaseReward*>& UChestReward::GetReward()
{
    return Rewards;
}

void UChestReward::SetRewards(TArray<UBaseReward*>& RewardsToAdd)
{
    Rewards = RewardsToAdd;
}
