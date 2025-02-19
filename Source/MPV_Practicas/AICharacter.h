// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Pawn.h"
#include "params/params.h"
#include "GameFramework/PlayerController.h"


#include "AICharacter.generated.h"

class ATargetPoint;
class UPaperSprite;
class UWidgetComponent;
class UHealthBarWidget;
class UStateMachineComponent;

UCLASS()
class MPV_PRACTICAS_API AAICharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAICharacter();

	/**  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AIChar)
	uint32 bDoMovement : 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	Params m_params;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(int Damage);
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetHealthBar(float NewPercent);
	UFUNCTION(BlueprintImplementableEvent)
	void SetGolemSpriteTexture(UPaperSprite* NewGolemTexture);

	bool MoveToPoint(const FVector& MovementDestination, const float MovementSpeed, const float ReachPointOffset = 0);

	UFUNCTION(BlueprintCallable, Category = "AIFunctions")
	void OnClickedLeft(const FVector& mousePosition);
	UFUNCTION(BlueprintCallable, Category = "AIFunctions")
	void OnClickedRight(const FVector& mousePosition);
	
	const Params& GetParams() const { return m_params; }

	void DrawDebug();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStateMachineComponent* StateMachineComponent;

	UPROPERTY(EditAnywhere, Category="Data")
	FGameplayTag DeadStateTag;
	UPROPERTY(EditAnywhere, Category="Data")
	AActor* PlayerActor;
	UPROPERTY(EditAnywhere, meta=(ClampMin="1"), Category="Data")
	int InitialHealth = 100;

	int Health;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<ATargetPoint*> PatrolPoints;
};
