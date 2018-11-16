// Fill out your copyright notice in the Description page of Project Settings.

#include "P_Tank.h"


// Sets default values
AP_Tank::AP_Tank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AP_Tank::BeginPlay()
{
	Super::BeginPlay();
	
}

void AP_Tank::AimAt(FVector HitLocation)
{
	auto OurTankName = GetName();
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString::Printf(TEXT("%s is aiming at %s"),*OurTankName, *HitLocation.ToString()));
}

// Called every frame
void AP_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP_Tank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

