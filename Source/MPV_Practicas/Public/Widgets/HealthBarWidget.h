// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class MPV_PRACTICAS_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetHealthBarPercent(float NewValue) const;
	
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UProgressBar* HealthBar;
};
