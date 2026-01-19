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
	UPROPERTY(EditDefaultsOnly, Category = "Mushrooms")
	TSubclassOf<AActor>Mushroom1;
	UPROPERTY(EditDefaultsOnly, Category = "Mushrooms")
	TSubclassOf<AActor>Mushroom2;
	UPROPERTY(EditDefaultsOnly, Category = "Mushrooms")
	TSubclassOf<AActor>Mushroom3;
	UPROPERTY(EditDefaultsOnly, Category = "Mushrooms")
	TSubclassOf<AActor>Mushroom4;
	UPROPERTY(EditDefaultsOnly, Category = "Mushrooms")
	TSubclassOf<AActor>Mushroom5;
	UPROPERTY(EditDefaultsOnly, Category = "Mushrooms")
	TSubclassOf<AActor>Mushroom6;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float spawnTimer;
	int xPos;
	int yPos;
	int maxSpawn = 5;
	int mushSpawned = 0;
	float spawnerX;
	float spawnerY;
};
