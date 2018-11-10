// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "P_Tank.h"
#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	AP_Tank* GetTankController() const;
	AP_Tank* GetPlayerTank();
	void BeginPlay() override;
};
