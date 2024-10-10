// Fill out your copyright notice in the Description page of Project Settings.


#include "Composite/RewardClient.h"
#include "Composite/RewardTree.h"
#include "Composite/ChestReward.h"
#include "Composite/GoldReward.h"
#include "Composite/GemReward.h"


/*
* Я использовал данный паттерн для реализации системы наград
* Они хранятся в виде дерева и бываеют 3-х типов: золото, гем и сундук
* Сундук содержит в себе другие награды, например, другой сундук
*/

/*
* Также данный паттерн может использоваться для представления
* любых древовидных объектов
* Например, древо навыков, древо бафов, которое высчитывает параметры урона
* или любой другой способности.
*/

void ARewardClient::RunClientCode()
{
    URewardTree* myRewardTree = NewObject<URewardTree>();

    UBaseReward* r1 = dynamic_cast<UGoldReward*>(NewObject<UGoldReward>());
    UBaseReward* r2 = dynamic_cast<UGemReward*>(NewObject<UGemReward>());
    UChestReward* r3 = NewObject<UChestReward>();

    TArray<UBaseReward*> rArray;
    rArray.Add(r1);
    rArray.Add(r2);
    r3->SetRewards(rArray);

    myRewardTree->Reward = r3;

}
