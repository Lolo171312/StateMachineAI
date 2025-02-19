// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine/Transition.h"

#include "StateMachine/Condition.h"

void UTransition::OnTransitionEnter(AActor* ActorPtr)
{
	Condition->OnConditionEnter(ActorPtr);
}

bool UTransition::CanTrigger() const
{
	if(Condition)
	{
		return Condition->Check();
	}

	return false;
}

void UTransition::OnTransitionExit()
{
	Condition->OnConditionExit();
}
