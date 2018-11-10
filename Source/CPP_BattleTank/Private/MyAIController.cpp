// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"

AP_Tank* AMyAIController::GetTankController() const
{
	return Cast<AP_Tank>(GetPawn());
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("%s"),*GetTankController()->GetName()));

}
