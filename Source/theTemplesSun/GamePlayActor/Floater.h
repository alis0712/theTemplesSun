// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class THETEMPLESSUN_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	
	//Location used by SetActorLocation() when BeginPlay() is called
	FVector initialLocation;

	// Location of the actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	FVector PlacedLocation;


	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Floater Variables")
		FVector WorldOrigin;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Floater Variables")
		FVector InitialDirection;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Floater Variables")
		bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Floater Variables")
		bool bInitializeFloaterLocations;
	
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Floater Variables")
		FVector InitialForce;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Floater Variables")
		FVector InitialTorque;

private: 
	float RunningTime;
	
	float BaseZLocation;

public:
	// Amplitude - how much we oscillate up and down
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Float Variables")
	float A;

	//Period - 2 * pi /(absolute value of B)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Float Variables")
	float B;
	
	// Phase Shift (C/B)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Float Variables")
	float C;
	
	//Vertical Shift D
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Float Variables")
	float D;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
