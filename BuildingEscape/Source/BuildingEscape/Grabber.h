// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
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
	//How far ahead the player can reach.
	UPROPERTY(EditAnywhere)
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what's in reach.
	void Grab();

	// Called when grab is released.
	void Release();

	// Find (assumed) attached input component.
	void FindPhysicsHandleComponent();

	// Setup (assumed) attached input component.
	void SetupInputComponent();

	// Return hit for first physics body in reach.
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line.
	FVector GetReachLineStart();

	// Returns current end of reach line.
	FVector GetReachLineEnd();
};
