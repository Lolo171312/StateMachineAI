// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Condition.generated.h"

/**
 * 
 */
UCLASS(Abstract, ClassGroup=(Custom), EditInlineNew )
class MPV_PRACTICAS_API UCondition : public UObject
{
	GENERATED_BODY()

public:
	virtual void OnConditionEnter(AActor* ActorPtr) PURE_VIRTUAL(UCondition::OnConditionEnter); 
	
	virtual bool Check() const PURE_VIRTUAL(UCondition::Check, return false;);

	virtual void OnConditionExit() PURE_VIRTUAL(UCondition::OnConditionExit);
};
