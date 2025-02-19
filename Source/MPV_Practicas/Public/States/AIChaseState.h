// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/AIBaseState.h"
#include "AIChaseState.generated.h"

/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UAIChaseState : public UAIBaseState
{
	GENERATED_BODY()

public:
	virtual void OnStateEnter(AActor* ActorPtr) override;
	virtual void OnStateUpdate() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Chase")
	float ChaseSpeed = 250.f;

	UPROPERTY()
	AActor* PlayerActorPtr;
};
