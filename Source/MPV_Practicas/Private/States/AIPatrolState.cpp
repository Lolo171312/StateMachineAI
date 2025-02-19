// Fill out your copyright notice in the Description page of Project Settings.


#include "States/AIPatrolState.h"

#include "Engine/TargetPoint.h"
#include "MPV_Practicas/AICharacter.h"

void UAIPatrolState::OnStateUpdate()
{
	Super::OnStateUpdate();

	if(AiCharacterPtr && !AiCharacterPtr->PatrolPoints.IsEmpty())
	{
		if(const ATargetPoint* CurrentPatrolPoint = AiCharacterPtr->PatrolPoints[CurrentPatrolPointIndex])
		{
			if(AiCharacterPtr->MoveToPoint(CurrentPatrolPoint->GetActorLocation(), PatrolSpeed, ReachPointOffset))
			{
				CurrentPatrolPointIndex++;
				if(CurrentPatrolPointIndex >= AiCharacterPtr->PatrolPoints.Num())
				{
					CurrentPatrolPointIndex = 0;
				}
			}	
		}
	}
}
