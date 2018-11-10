// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	
public:

	AP_Tank* GetTankController() const;
	void BeginPlay() override;
};
