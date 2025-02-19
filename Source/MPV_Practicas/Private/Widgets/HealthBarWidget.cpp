// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HealthBarWidget.h"

#include "Components/ProgressBar.h"

void UHealthBarWidget::SetHealthBarPercent(float NewValue) const
{
	HealthBar->SetPercent(NewValue);
}
