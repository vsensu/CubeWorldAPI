// Fill out your copyright notice in the Description page of Project Settings.


#include "CppCubeWorldAPIModActor.h"

#include "CubeWorldAPIFunctionLibrary.h"

// Sets default values
ACppCubeWorldAPIModActor::ACppCubeWorldAPIModActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppCubeWorldAPIModActor::BeginPlay()
{
	Super::BeginPlay();
	
	UCubeWorldAPIFunctionLibrary::GlobalDataActor = this;
}

// Called every frame
void ACppCubeWorldAPIModActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

