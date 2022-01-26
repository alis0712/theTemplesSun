// Fill out your copyright notice in the Description page of Project Settings.


#include "theSun.h"

// Sets default values
AtheSun::AtheSun()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AtheSun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtheSun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AtheSun::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

