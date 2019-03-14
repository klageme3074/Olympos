// Fill out your copyright notice in the Description page of Project Settings.

#include "OLSlotHUDWiget.h"
#include "Components/Image.h"


UImage * UOLSlotHUDWiget::GetSlot(int32 index) 
{
	return FirstSlot[index - 1];
}

UImage * UOLSlotHUDWiget::GetBackgroundSlot(int32 index)
{
	return BackGroundSlot[index - 1];
}

void UOLSlotHUDWiget::NativeConstruct() {
	Super::NativeConstruct();
	FirstSlot[0] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_1")));
	BackGroundSlot[0] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_1B")));
	FirstSlot[1] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_2")));
	BackGroundSlot[1] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_2B")));
	FirstSlot[2] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_3")));
	BackGroundSlot[2] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_3B")));

	FirstSlot[0]->RenderTransform.Translation = FVector2D(0.0f, 300.0f);
}
