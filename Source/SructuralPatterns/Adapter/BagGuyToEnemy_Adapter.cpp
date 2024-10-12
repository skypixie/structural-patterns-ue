// Fill out your copyright notice in the Description page of Project Settings.


#include "Adapter/BagGuyToEnemy_Adapter.h"
#include "Adapter/BadGuy.h"
#include "Adapter/BaseEnemy.h"

/*
* На моем примере использовать данный паттерн
* было бы показательней, если бы изначально был код
* для BadGuy и BaseEnemy, которые не имеют одного родительского класса.
* Тогда нам понадобился бы адаптер, который вызывал бы нужные методы
* и, например, делал бы какие-то вычисления или проверки, если надо,
* но суть ясна.
*/

/*
* Паттерн адаптер можно использовать в похожих ситациях,
* когда класс несовместим с клиентским кодом.
* Например, есть пушка, которая стреляет по акторам,
* и мы хотим, чтобы существующий игрок мог ее использовать как обычное оружие.
* Тогда нам поможет класс адаптер, который мы отнаследуем от оружия.
* Он будет хранить ссылку на пушку и вызывать нужные пушечные методы,
* а клиентский код будет обращаться к нему как к оружию.
*/

// Sets default values
ABagGuyToEnemy_Adapter::ABagGuyToEnemy_Adapter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABagGuyToEnemy_Adapter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABagGuyToEnemy_Adapter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABagGuyToEnemy_Adapter::SetBadGuy(ABadGuy* BadGuy_)
{
    BadGuy = BadGuy_;
}

void ABagGuyToEnemy_Adapter::Attack()
{
    if (IsValid(BadGuy))
    {
        BadGuy->ShootHero();
    }
}

