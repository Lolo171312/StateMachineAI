// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "BaseState.generated.h"

class UTransition;
/**
 * 
 */
UCLASS(Blueprintable)
class MPV_PRACTICAS_API UBaseState : public UObject
{
	GENERATED_BODY()

public:
	virtual void OnStateEnter(AActor* ActorPtr);
	virtual void OnStateUpdate();
	virtual void OnStateExit();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	bool bCanTickState = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	bool bCanRepeatState = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FGameplayTag StateTag;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category="Data")
	TArray<UTransition*> Transitions;
};
