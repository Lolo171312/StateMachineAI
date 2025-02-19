// Fill out your copyright notice in the Description page of Project Settings.


#include "States/AIChaseState.h"

#include "MPV_Practicas/AICharacter.h"

void UAIChaseState::OnStateEnter(AActor* ActorPtr)
{
	Super::OnStateEnter(ActorPtr);

	if(AiCharacterPtr && !PlayerActorPtr)
	{
		PlayerActorPtr = AiCharacterPtr->PlayerActor;
	}
}

void UAIChaseState::OnStateUpdate()
{
	Super::OnStateUpdate();

	if(AiCharacterPtr && PlayerActorPtr)
	{
		AiCharacterPtr->MoveToPoint(PlayerActorPtr->GetActorLocation(), ChaseSpeed);
	}
}
