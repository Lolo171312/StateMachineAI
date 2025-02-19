// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "StateMachineComponent.generated.h"

class UBaseState;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MPV_PRACTICAS_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateMachineComponent();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void InitializeStates();
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SwitchState(FGameplayTag NewStateTag);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="State Machine")
	FGameplayTag InitialState;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="State Machine")
	TMap<FGameplayTag, TSubclassOf<UBaseState>> AvailableStates;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="State Machine")
	bool ShowDebug;
	
	UPROPERTY()
	UBaseState* m_CurrentState = nullptr;
	UPROPERTY()
	TMap<FGameplayTag, UBaseState*> m_States;

	bool bDoStateTick = false;
};
