// Fill out your copyright notice in the Description page of Project Settings.


#include "Conditions/SeeTargetCondition.h"

#include "MPV_Practicas/AICharacter.h"

void USeeTargetCondition::OnConditionEnter(AActor* ActorPtr)
{
	//Get OwnerActor Ptr
	if(!OwnerActor)
	{
		OwnerActor = Cast<AAICharacter>(ActorPtr);
		//Get PlayerActor Ptr
		if(OwnerActor && !PlayerActor)
		{
			PlayerActor = OwnerActor->PlayerActor;
		}
	}
}

bool USeeTargetCondition::Check() const
{
	if(OwnerActor && PlayerActor)
	{
		//Check Distance Between Owner and Player
		FVector DirectionOwnerPlayer = PlayerActor->GetActorLocation() - OwnerActor->GetActorLocation();
		if(DirectionOwnerPlayer.Size() < SightDistance)
		{
			//Check if Player is inside the Sight Angle
			float Dot = FVector::DotProduct(OwnerActor->GetActorForwardVector(), DirectionOwnerPlayer.GetSafeNormal());
			float Angle = FMath::RadiansToDegrees(FMath::Acos(Dot));
			if(Angle < SightAngle)
			{
				return true;
			}
		}
	}
	
	return false;
}

void USeeTargetCondition::OnConditionExit()
{}