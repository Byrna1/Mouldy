// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <random>
#include "GameFramework/Actor.h"
#include "MouldyMushroomSpawner.generated.h"

UCLASS()
class MOULDY_API AMouldyMushroomSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMouldyMushroomSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float spawnTimer;
	float spawnRadius;
	static std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
	std::uniform_real_distribution<float> spawnX(0, 2000);
	std::uniform_real_distribution<float> spawnY(0, 2000);
};
