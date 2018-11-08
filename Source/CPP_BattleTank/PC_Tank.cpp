// Fill out your copyright notice in the Description page of Project Settings.

#include "PC_Tank.h"




AP_Tank* APC_Tank::GetControlledTank() const
{
	return Cast<AP_Tank>(GetPawn());
}
