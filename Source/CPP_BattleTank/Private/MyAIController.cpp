// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"

AP_Tank* AMyAIController::GetTankController() const
{
	return Cast<AP_Tank>(GetPawn());
}

AP_Tank* AMyAIController::GetPlayerTank()
{
	return Cast<AP_Tank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("%s"), *GetPlayerTank()->GetName()));

}



bool AMyAIController::GetSightRayLocation(FVector& OutHitLocation)
{
	
	return true;
}

void AMyAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	//GetTankController()->AimAt(GetPlayerTank()->GetActorLocation(),LaunchSpeed);
}
