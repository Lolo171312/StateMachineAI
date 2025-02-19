// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MPV_Practicas/Public/StateMachine/BaseState.h"
#include "AIBaseState.generated.h"

class UPaperSprite;
class AAICharacter;
/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UAIBaseState : public UBaseState
{
	GENERATED_BODY()

public:
	virtual void OnStateEnter(AActor* ActorPtr) override;

protected:
	UPROPERTY(EditAnywhere, Category="Golem")
	UPaperSprite* GolemStateTexture;
	
	UPROPERTY()
	AAICharacter* AiCharacterPtr;
};
