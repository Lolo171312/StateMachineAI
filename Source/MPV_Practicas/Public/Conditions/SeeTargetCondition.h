// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MPV_Practicas/Public/StateMachine/Condition.h"
#include "SeeTargetCondition.generated.h"

class AAICharacter;
/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API USeeTargetCondition : public UCondition
{
	GENERATED_BODY()

public:
	virtual void OnConditionEnter(AActor* ActorPtr) override;
	virtual bool Check() const override;
	virtual void OnConditionExit() override;

	UPROPERTY(EditDefaultsOnly, meta=(ClampMin="1"), Category="Data")
	float SightDistance = 100.f;
	UPROPERTY(EditDefaultsOnly, meta=(ClampMin="1", ClampMax="180"), Category="Data")
	float SightAngle = 45.f;
	
	UPROPERTY()
	AAICharacter* OwnerActor;
	UPROPERTY()
	AActor* PlayerActor;
};
