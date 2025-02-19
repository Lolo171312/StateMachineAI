// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MPV_Practicas/Public/StateMachine/Condition.h"
#include "DistToPlayerCondition.generated.h"

class AAICharacter;
/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UDistToPlayerCondition : public UCondition
{
	GENERATED_BODY()

public:
	virtual void OnConditionEnter(AActor* ActorPtr) override;
	virtual bool Check() const override;
	virtual void OnConditionExit() override;

	UPROPERTY(EditDefaultsOnly, meta=(ClampMin = "1"), Category="Data")
	float DetectionDistance = 1.f;

private:
	UPROPERTY()
	AAICharacter* AiCharacter;
};
