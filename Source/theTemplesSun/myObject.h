// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "myObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class THETEMPLESSUN_API UmyObject : public UObject
{
		GENERATED_BODY()

		UmyObject();
public:
		UPROPERTY(BlueprintReadWrite, Category = "myVariables")
		float myFloat;

		UFUNCTION(BlueprintCallable, Category = "myFunctions")
		void myFunction();
		
	
};
