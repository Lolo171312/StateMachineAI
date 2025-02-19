// Fill out your copyright notice in the Description page of Project Settings.


#include "MPV_Practicas/Public/States/AIBaseState.h"

#include "MPV_Practicas/AICharacter.h"

void UAIBaseState::OnStateEnter(AActor* ActorPtr)
{
	Super::OnStateEnter(ActorPtr);

	if(AiCharacterPtr == nullptr)
	{
		AiCharacterPtr = Cast<AAICharacter>(ActorPtr);
	}

	if(AiCharacterPtr)
	{
		if(GolemStateTexture)
		{
			AiCharacterPtr->SetGolemSpriteTexture(GolemStateTexture);
		}
	}
}
