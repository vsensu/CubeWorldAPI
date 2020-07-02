// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <unordered_map>
#include <string>
#include "BlockInfo.h"

#include "CppCubeWorldAPIModActor.generated.h"

UCLASS()
class CUBEWORLDAPIPLUGIN_API ACppCubeWorldAPIModActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppCubeWorldAPIModActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	std::unordered_map<std::string, int> img_index_map;
	std::unordered_map<std::string, BlockInfo> block_type_manager;
};
