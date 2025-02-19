// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"

#include "PaperSpriteComponent.h"
#include "StateMachine/StateMachineComponent.h"
#include "Components/WidgetComponent.h"
#include "params/params.h"
#include "debug/debugdraw.h"
#include "Kismet/KismetMathLibrary.h"
#include "Widgets/HealthBarWidget.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StateMachineComponent = CreateDefaultSubobject<UStateMachineComponent>("StateMachine");

	Health = InitialHealth;
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	ReadParams("params.xml", m_params);
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebug();
}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAICharacter::ReceiveDamage(int Damage)
{
	Health-=Damage;
	Health = FMath::Clamp(Health, 0.f, InitialHealth);

	const float NewHealthPercent = static_cast<float>(Health) / static_cast<float>(InitialHealth);
	SetHealthBar(NewHealthPercent);

	if(Health == 0)
	{
		StateMachineComponent->SwitchState(DeadStateTag);
	}
}

bool AAICharacter::MoveToPoint(const FVector& MovementDestination, const float MovementSpeed, const float ReachPointOffset)
{
	const FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), MovementDestination);
	SetActorRotation(NewRotation);

	const FVector LocationToAdd = GetActorForwardVector() * MovementSpeed * GetWorld()->GetDeltaSeconds();
	AddActorWorldOffset(LocationToAdd);

	if(FVector::Dist(GetActorLocation(), MovementDestination) < ReachPointOffset)
	{
		return true;
	}

	return false;
}

void AAICharacter::OnClickedLeft(const FVector& mousePosition)
{
	SetActorLocation(mousePosition);
}

void AAICharacter::OnClickedRight(const FVector& mousePosition)
{
	m_params.targetPosition = mousePosition;
}

void AAICharacter::DrawDebug()
{

}