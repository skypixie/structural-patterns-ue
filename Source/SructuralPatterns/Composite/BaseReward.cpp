// Fill out your copyright notice in the Description page of Project Settings.


#include "Composite/BaseReward.h"

TArray<UBaseReward*>& UBaseReward::GetReward()
{
    return Rewards;
}
