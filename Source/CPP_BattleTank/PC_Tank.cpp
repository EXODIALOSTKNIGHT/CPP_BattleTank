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



void APC_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();

}

AP_Tank* APC_Tank::GetControlledTank() const
{

	return Cast<AP_Tank>(GetPawn());
}

void APC_Tank::AimTowardsPlayer()
{

	FVector HitLocation;
	
	if (GetSightRayLocation(HitLocation))
	{
		LaunchSpeed = GetControlledTank()->LaunchSpeed;
		GetControlledTank()->AimAt(HitLocation,LaunchSpeed);
	}

}

bool APC_Tank::GetSightRayLocation(FVector& OutHitLocation)
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector WorldDirection;
	if (GetLookDirection(ScreenLocation,WorldDirection))
	{
		GetLookVectorLocation(WorldDirection, OutHitLocation);
	}

	return true;
}

bool APC_Tank::GetLookDirection(FVector2D ScreenLocation,FVector& WorldDirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraLocation,
		WorldDirection
	);
}

bool APC_Tank::GetLookVectorLocation(FVector LookDirection,FVector& HitLocation) const
{
	FHitResult HitResult;
	
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 10);
		HitLocation = HitResult.Location;
		return true;
	}


	return false;
}

