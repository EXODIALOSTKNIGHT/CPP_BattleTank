// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "P_Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Tank.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BATTLETANK_API APC_Tank : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	AP_Tank* GetControlledTank() const;
	void BeginPlay() override;
	AP_Tank* GetPlayerTank();
	FVector StartLineTrace;
	FVector EndLineTrace;
	FCollisionObjectQueryParams CollisionObjectParam;


	void Tick(float DeltaTime) override;
	void AimTowardsPlayer();
	bool GetSightRayLocation(FVector& OutHitLocation);
	bool GetLookDirection(FVector2D ScreenLocation, FVector WorldDirection);

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33;
};
