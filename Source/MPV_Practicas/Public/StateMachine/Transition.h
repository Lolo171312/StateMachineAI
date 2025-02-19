// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

class UCondition;
class UBaseState;
/**
 * 
 */
UCLASS( ClassGroup=(Custom), EditInlineNew )
class MPV_PRACTICAS_API UTransition : public UObject
{
	GENERATED_BODY()

public:
	void OnTransitionEnter(AActor* ActorPtr);
	bool CanTrigger() const;
	void OnTransitionExit();
	
	UPROPERTY(EditAnywhere, Instanced, Category="Info")
	UCondition* Condition;
	UPROPERTY(EditAnywhere, Category="Info")
	FGameplayTag TargetState;
};
