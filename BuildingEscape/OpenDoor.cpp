// Fill out your copyright notice in the Description page of Project Settings.



#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "OpenDoor.h"

#define OUT
// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYawOpen += InitialYaw;
	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s has door component, but pressurePlate is not set."), *GetOwner()->GetName());
	}
	
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		if (TotalMassOfActors() > MassNeededToOpenDoor)
		{
			OpenDoor(DeltaTime);
			TimeOpened = GetWorld()->GetTimeSeconds();
		}
		else  {
		
			if (GetWorld()->GetTimeSeconds() - TimeOpened >= .1) {
				CloseDoor(DeltaTime);
			}
		//CloseDoor(DeltaTime);
		}
	 
}
void UOpenDoor::OpenDoor(float DeltaTime) {

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYawOpen, DeltaTime * 1.f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
	
}

void UOpenDoor::OnClicked() {
	
}
void UOpenDoor::CloseDoor(float DeltaTime) {

	CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime * 1.f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

}
float UOpenDoor::TotalMassOfActors() const {

	float TotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);


	for (AActor* Actor : OverlappingActors) {

		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s is on the pressure plate."), *Actor->GetName());
	}
	return TotalMass;
}

