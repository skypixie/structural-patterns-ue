// Fill out your copyright notice in the Description page of Project Settings.


#include "Composite/RewardTree.h"
#include "Composite/BaseReward.h"

TArray<UBaseReward*> URewardTree::GetRewards()
{
    return Reward->GetReward();
}
