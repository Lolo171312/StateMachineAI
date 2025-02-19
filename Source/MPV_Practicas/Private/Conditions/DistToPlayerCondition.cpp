// Fill out your copyright notice in the Description page of Project Settings.


#include "Conditions/DistToPlayerCondition.h"

#include "MPV_Practicas/AICharacter.h"

void UDistToPlayerCondition::OnConditionEnter(AActor* ActorPtr)
{
	if(ActorPtr && AiCharacter == nullptr)
	{
		AiCharacter = Cast<AAICharacter>(ActorPtr);
	}
}

bool UDistToPlayerCondition::Check() const
{
	if(AiCharacter)
	{
		if(const AActor* PlayerActor = AiCharacter->PlayerActor)
		{
			const float DistToPlayer = FVector::Dist(AiCharacter->GetActorLocation(), PlayerActor->GetActorLocation());
			if(DistToPlayer < DetectionDistance)
			{
				return true;
			}
		}
	}
	
	return false;
}

void UDistToPlayerCondition::OnConditionExit()
{}