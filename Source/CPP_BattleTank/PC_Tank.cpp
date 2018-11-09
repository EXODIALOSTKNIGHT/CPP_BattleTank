// Fill out your copyright notice in the Description page of Project Settings.

#include "PC_Tank.h"


void APC_Tank::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("%s"),*GetControlledTank()->GetName()));
	}
	
}

AP_Tank* APC_Tank::GetControlledTank() const
{
	return Cast<AP_Tank>(GetPawn());
}
