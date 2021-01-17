// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlateCylinder.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UPressurePlateCylinder::UPressurePlateCylinder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPressurePlateCylinder::BeginPlay()
{
	Super::BeginPlay();
	InitialZ = GetOwner()->GetActorLocation().Z;
	//EndingZ = InitialZ - 10.0;
	EndingLocation = InitialLocation;
	ActorThatSteps = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UPressurePlateCylinder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatSteps)) {
		SinkPressurePlate();
	}
	else {
		RisePressurePlate();
	}
	// ...
}
void UPressurePlateCylinder::SinkPressurePlate() {

	
	//EndingZ = FMath::Lerp(InitialZ, (InitialZ - 10.0), .5f);
	FVector CylinderSinking = GetOwner()->GetActorLocation();
	EndingZ = InitialZ - 10;
	CylinderSinking.Z = EndingZ;
	GetOwner()->SetActorLocation(CylinderSinking);

}
void UPressurePlateCylinder::RisePressurePlate() {

	
	EndingZ = InitialZ;
	FVector CylinderRising = GetOwner()->GetActorLocation();
	CylinderRising.Z = EndingZ;
	GetOwner()->SetActorLocation(CylinderRising);

}
