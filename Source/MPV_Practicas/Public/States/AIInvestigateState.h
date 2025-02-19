// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/AIBaseState.h"
#include "AIInvestigateState.generated.h"

/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UAIInvestigateState : public UAIBaseState
{
	GENERATED_BODY()

public:
	virtual void OnStateEnter(AActor* ActorPtr) override;
	virtual void OnStateUpdate() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category="Investigate")
	float ReachPointOffset = 50.f;
	UPROPERTY(EditDefaultsOnly, Category="Investigate")
	float InvestigateSpeed = 120.f;
	UPROPERTY(EditDefaultsOnly, Category="Investigate")
	float RandomInvestigationPointRadius = 250.f;

	FVector InitialPoint;
	FVector MovementPoint;
};
