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
	if (GetActorLocation().X > 0) xPos = -1; //direction mods for the spawning area (protruding from a corner)
	if (GetActorLocation().X < 0) xPos = 1;
	if (GetActorLocation().Y > 0) yPos = -1;
	if (GetActorLocation().Y < 0) yPos = 1;
}

// Called every frame
void AMouldyMushroomSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	spawnTimer += DeltaTime;
	if (spawnTimer > 3 && mushSpawned < maxSpawn)
	{
		static std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
		std::uniform_real_distribution<float> spawnX(0.0f, 1750.0f);
		std::uniform_real_distribution<float> spawnY(0.0f, 1750.0f);
		std::uniform_int_distribution<std::mt19937::result_type> shrooms(1, 6);
		int randomShroom = shrooms(rng);
		FVector shroomLocation(((xPos)*(spawnX(rng))) + GetActorLocation().X, ((yPos)*(spawnY(rng))) + GetActorLocation().Y, 0.0f);
		switch (randomShroom)
		{
		case 1:
			GetWorld()->SpawnActor<AActor>(Mushroom1, shroomLocation, FRotator(0.0f, 0.0f, 0.0f));
			break;
		case 2:
			GetWorld()->SpawnActor<AActor>(Mushroom2, shroomLocation, FRotator(0.0f, 0.0f, 0.0f));
			break;
		case 3:
			GetWorld()->SpawnActor<AActor>(Mushroom3, shroomLocation, FRotator(0.0f, 0.0f, 0.0f));
			break;
		case 4:
			GetWorld()->SpawnActor<AActor>(Mushroom4, shroomLocation, FRotator(0.0f, 0.0f, 0.0f));
			break;
		case 5:
			GetWorld()->SpawnActor<AActor>(Mushroom5, shroomLocation, FRotator(0.0f, 0.0f, 0.0f));
			break;
		case 6:
			GetWorld()->SpawnActor<AActor>(Mushroom6, shroomLocation, FRotator(0.0f, 0.0f, 0.0f));
			break;
		}
		mushSpawned++;
		spawnTimer = 0;
	}
}

