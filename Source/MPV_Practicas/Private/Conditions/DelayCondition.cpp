// Fill out your copyright notice in the Description page of Project Settings.


#include "Conditions/DelayCondition.h"

void UDelayCondition::OnConditionEnter(AActor* ActorPtr)
{
	//Set DelayCompleted
	DelayCompleted = false;

	//Start TimerEvent to Set DelayCompleted after X seconds
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, this, &UDelayCondition::DelayDone, SecondsToDelay);
}

bool UDelayCondition::Check() const
{
	return DelayCompleted;
}

void UDelayCondition::OnConditionExit()
{
	//If Timer is active then Clear it
	if(DelayHandle.IsValid() && GetWorld()->GetTimerManager().IsTimerActive(DelayHandle))
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);
		UE_LOG(LogTemp, Warning, TEXT("DelayHandle was Cleared"));
	}

	//Set DelayCompleted
	DelayCompleted = false;
}

void UDelayCondition::DelayDone()
{
	DelayCompleted = true;
	UE_LOG(LogTemp, Warning, TEXT("DelayHandle was Completed"));
}
