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

void APC_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();

}

void APC_Tank::AimTowardsPlayer()
{

	FVector HitLocation;
	if (GetSightRayLocation(HitLocation))
	{
	}

}

bool APC_Tank::GetSightRayLocation(FVector& OutHitLocation)
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	return true;
}
