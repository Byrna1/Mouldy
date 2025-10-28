// Fill out your copyright notice in the Description page of Project Settings.


#include "MouldyMushroomSpawner.h"

// Sets default values
AMouldyMushroomSpawner::AMouldyMushroomSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMouldyMushroomSpawner::BeginPlay()
{
	Super::BeginPlay();
	spawnTimer = 0;
}

// Called every frame
void AMouldyMushroomSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	spawnTimer += DeltaTime;
	if (spawnTimer > 3)
	{

	}
}

