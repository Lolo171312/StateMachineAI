// Fill out your copyright notice in the Description page of Project Settings.


#include "States/AIInvestigateState.h"

#include "Kismet/KismetMathLibrary.h"
#include "MPV_Practicas/AICharacter.h"
#include "MPV_Practicas/debug/debugdraw.h"

void UAIInvestigateState::OnStateEnter(AActor* ActorPtr)
{
	Super::OnStateEnter(ActorPtr);

	if(AiCharacterPtr)
	{
		//Get Player´s last seen Location
		MovementPoint = AiCharacterPtr->PlayerActor->GetActorLocation();
		InitialPoint = MovementPoint;

		SetCircle(AiCharacterPtr, "targetPosition", InitialPoint, RandomInvestigationPointRadius);
	}
}

void UAIInvestigateState::OnStateUpdate()
{
	Super::OnStateUpdate();

	if(AiCharacterPtr == nullptr) return;
	
	//Move to Player´s last seen Location or Random Location
	if(AiCharacterPtr->MoveToPoint(MovementPoint, InvestigateSpeed, ReachPointOffset))
	{
		//Generate a new location around InitialPoint
		FVector RandomDirection3D = UKismetMathLibrary::RandomUnitVector();
		FVector RandomDirection2D = FVector(RandomDirection3D.X, 0, RandomDirection3D.Z);
		RandomDirection2D = RandomDirection2D.GetSafeNormal();
		FVector DestinationLocation = InitialPoint + RandomDirection2D * UKismetMathLibrary::RandomFloatInRange(0.f, RandomInvestigationPointRadius);
		
		MovementPoint = DestinationLocation;
	}
}
