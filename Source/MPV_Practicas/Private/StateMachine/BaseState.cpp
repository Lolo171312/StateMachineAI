// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine/BaseState.h"

#include "StateMachine/Transition.h"

void UBaseState::OnStateEnter(AActor* ActorPtr)
{
	for (UTransition* Transition : Transitions)
	{
		Transition->OnTransitionEnter(ActorPtr);
	}
}

void UBaseState::OnStateUpdate()
{
}

void UBaseState::OnStateExit()
{
	for (UTransition* Transition : Transitions)
	{
		Transition->OnTransitionExit();
	}
}
