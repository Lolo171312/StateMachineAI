// Fill out your copyright notice in the Description page of Project Settings.


#include "Conditions/LoseSightTargetCondition.h"

#include "MPV_Practicas/AICharacter.h"

void ULoseSightTargetCondition::OnConditionEnter(AActor* ActorPtr)
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

bool ULoseSightTargetCondition::Check() const
{
	if(OwnerActor && PlayerActor)
	{
		//Check Distance Between Owner and Player
		FVector DirectionOwnerPlayer = PlayerActor->GetActorLocation() - OwnerActor->GetActorLocation();
		
		//Get Distance from Owner to Player
		float DistOwnerPlayer = DirectionOwnerPlayer.Size();
		//Check if Player is further from Owner than SightDistance
		if(DistOwnerPlayer > SightDistance)
		{
			return true;
		}

		//Get Angle from Owner to Player
		float Dot = FVector::DotProduct(OwnerActor->GetActorForwardVector(), DirectionOwnerPlayer.GetSafeNormal());
		float Angle = FMath::RadiansToDegrees(FMath::Acos(Dot));
		//Check if angle to Player is bigger than SightAngle
		if(Angle > SightAngle)
		{
			return true;
		}
	}
	
	return false;
}

void ULoseSightTargetCondition::OnConditionExit()
{}