// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	initialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);


	InitialDirection = FVector(0.0f, 0.0f, 0.0f);
	bInitializeFloaterLocations = false;
	bShouldFloat = false;
	
	InitialForce = FVector(200000.0f, 0.0f, 0.0f);
	InitialTorque = FVector(200000.0f, 0.0f, 0.0f);

	RunningTime = 0.f;

	A = 0.f;
	B = 0.f;
	C = 0.f;
	D = 0.f;


}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float InitialX = FMath::FRandRange(-500.f, 500.f);
	float InitialY = FMath::FRandRange(-500.f, 500.f);
	float InitialZ = FMath::FRandRange(0.f, 500.f);

	initialLocation.X = InitialX;
	initialLocation.Y = InitialY;
	initialLocation.Z = InitialZ;



	PlacedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(initialLocation);

	}

	BaseZLocation = PlacedLocation.Z;

	StaticMesh->AddForce(InitialForce);
	StaticMesh->AddTorqueInRadians(InitialTorque);
	
	
	

}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FVector NewLocation = GetActorLocation();
			/*
			FHitResult HitResult;
			AddActorLocalOffset(InitialDirection, true, &HitResult);

			FVector HitLocation = HitResult.Location;
			UE_LOG(LogTemp, Warning, TEXT("Hit Location: X = %f, Y = %f, Z = %f"), HitLocation.X, HitLocation.Y, HitLocation.Z);
			*/

		NewLocation.Z = BaseZLocation + A * FMath::Sin(B* RunningTime - C) + D; // Period = 2 * PI / ABS(B)
		
		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;

	}

	
}

