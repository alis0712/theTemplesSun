// Fill out your copyright notice in the Description page of Project Settings.


#include "myObject.h"

UmyObject::UmyObject()
{
	myFloat = 0;

}

void UmyObject::myFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("This is our warning text! "));
}