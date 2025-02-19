// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIBaseState.h"
#include "AIPatrolState.generated.h"

/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UAIPatrolState : public UAIBaseState
{
	GENERATED_BODY()

public:
	virtual void OnStateUpdate() override;

private:
	int CurrentPatrolPointIndex = 0;
	UPROPERTY(EditDefaultsOnly, Category="Patrol")
	float ReachPointOffset = 50.f;
	UPROPERTY(EditDefaultsOnly, Category="Patrol")
	float PatrolSpeed = 150.f;
};
