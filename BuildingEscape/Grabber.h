// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	float Reach = 200.0f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr; 
	UInputComponent* GrabInputComponent = nullptr;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void FindInputComponent();
	FHitResult GetFirstPhysicsBodyInReach() const;
	void MoveGrabbedObject();
	//return linetraceend
	FVector GetPlayersReach() const;
	FVector GetPlayersWorldPosition() const;
};
