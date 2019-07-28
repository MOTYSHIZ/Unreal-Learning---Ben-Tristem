// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

//Creating the event class FOnOpenRequest so that we can have an event
//Exposed to Blueprint
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//This UPROPERTY Macro exposes this FOnOpenRequest to Blueprint
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	//This UPROPERTY Macro exposes this FOnCloseRequest to Blueprint
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	AActor* Owner = nullptr;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;
};
