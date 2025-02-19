// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine/StateMachineComponent.h"

#include "StateMachine/BaseState.h"
#include "StateMachine/Transition.h"

// Sets default values for this component's properties
UStateMachineComponent::UStateMachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStates();
	SwitchState(InitialState);
}

void UStateMachineComponent::InitializeStates()
{
	for (const TTuple<FGameplayTag, TSubclassOf<UBaseState>>& State : AvailableStates)
	{
		if(UBaseState* InstancedState = NewObject<UBaseState>(this, State.Value))
		{
			m_States.Add(State.Key, InstancedState);	
		}
	}
}

// Called every frame
void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Do State´s Tick if it should
	if(bDoStateTick)
	{
		m_CurrentState->OnStateUpdate();
	}

	//Check if the CurrentState should Switch State
	for (const UTransition* Transition : m_CurrentState->Transitions)
	{
		if (Transition->CanTrigger())
		{
			SwitchState(Transition->TargetState);
		}
	}

	//Show Debug if it is Enabled
	if(ShowDebug && m_CurrentState && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 0.f, FColor::Green, GetOwner()->GetActorNameOrLabel() + "´s CurrentState: " + m_CurrentState->StateTag.GetTagName().ToString());
	}
}

void UStateMachineComponent::SwitchState(FGameplayTag NewStateTag)
{
	//Check if NewStateTag is a valid GameplayTag
	if(!NewStateTag.IsValid()) return;
	
	//Find State by Key
	UBaseState* NewState = m_States.FindRef(NewStateTag);
	if(NewState->IsValidLowLevel())
	{
		//If the CurrentState is null I initialize it (it will only happens the first time)
		if(m_CurrentState == nullptr)
		{
			m_CurrentState = NewState;
		}
		else
		{
			//Check if can switch from CurrentState to NewState
			if(m_CurrentState->GetClass() != NewState->GetClass() || m_CurrentState->bCanRepeatState)
			{
				bDoStateTick = false;
				
				//Call OnExit from CurrentState and Set CurrentState to be the NewState
				m_CurrentState->OnStateExit();
				m_CurrentState = NewState;
			}
			else if(ShowDebug)
			{
				UE_LOG(LogTemp, Error, TEXT("StateMachineCmp. Trying to switch to the same State (CurrentState can´t repeat itself)"));
			}
		}

		//Call OnStateEnter from the New CurrentState
		if(m_CurrentState)
		{
			m_CurrentState->OnStateEnter(GetOwner());
			bDoStateTick = m_CurrentState->bCanTickState;
		}
	}
	else if(ShowDebug)
	{
		UE_LOG(LogTemp, Error, TEXT("StateMachineCmp. SwitchState can´t find State by Tag"));
	}
}