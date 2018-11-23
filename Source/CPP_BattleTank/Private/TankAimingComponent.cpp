// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelComponent(UStaticMeshComponent* Barrel)
{
	BarrelToSet = Barrel;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!BarrelToSet){return;}

		FVector OutLaunchVelocity;
		FVector StartLocation = BarrelToSet->GetSocketLocation(FName("Projectile"));

		if (UGameplayStatics::SuggestProjectileVelocity
		(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0,ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString::Printf(TEXT("Aiming at %s "), *AimDirection.ToString()));
			DrawDebugLine(GetWorld(),AimDirection, OutLaunchVelocity,FColor::Yellow,false,-1.f,0,20.f);
		}
	
}

