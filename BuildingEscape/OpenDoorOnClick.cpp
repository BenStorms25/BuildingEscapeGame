// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "OpenDoorOnClick.h"

// Sets default values for this component's properties
UOpenDoorOnClick::UOpenDoorOnClick()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorOnClick::BeginPlay()
{
	Super::BeginPlay();
	InitialClosedAngle = GetOwner()->GetActorRotation().Yaw;

	// ...
	
}


// Called every frame
void UOpenDoorOnClick::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FActorOnClickedSignature* click;
	
	if (click) {


	}

	// ...
}

