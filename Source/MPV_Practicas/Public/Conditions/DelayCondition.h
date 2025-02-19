// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MPV_Practicas/Public/StateMachine/Condition.h"
#include "DelayCondition.generated.h"

/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UDelayCondition : public UCondition
{
	GENERATED_BODY()

public:
	virtual void OnConditionEnter(AActor* ActorPtr) override;
	virtual bool Check() const override;
	virtual void OnConditionExit() override;

	UFUNCTION()
	void DelayDone();
	
	UPROPERTY(EditAnywhere, meta=(ClampMin="0.1"), Category="Data")
	float SecondsToDelay = 2.f;

	bool DelayCompleted = false;
	FTimerHandle DelayHandle;
};
