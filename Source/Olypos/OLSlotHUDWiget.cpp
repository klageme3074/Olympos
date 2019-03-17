// Fill out your copyright notice in the Description page of Project Settings.

#include "OLSlotHUDWiget.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"

UImage * UOLSlotHUDWiget::GetSlot(int32 index) 
{
	return FrontSlot[index - 1];
}

UImage * UOLSlotHUDWiget::GetBackgroundSlot(int32 index)
{
	return BackSlot[index - 1];
}

void UOLSlotHUDWiget::SetSlotPosY(int32 index, float y)
{
	float x = Cast<UCanvasPanelSlot>(FrontSlot[index - 1]->Slot)->GetPosition().X;
	Cast<UCanvasPanelSlot>(FrontSlot[index - 1]->Slot)->SetPosition(FVector2D(x, y));
}

void UOLSlotHUDWiget::SetBackSlotPosY(int32 index, float y)
{
	float x = Cast<UCanvasPanelSlot>(BackSlot[index - 1]->Slot)->GetPosition().X;
	Cast<UCanvasPanelSlot>(BackSlot[index - 1]->Slot)->SetPosition(FVector2D(x, y));
}

float UOLSlotHUDWiget::GetSlotPosY(int32 index)
{
	return Cast<UCanvasPanelSlot>(FrontSlot[index - 1]->Slot)->GetPosition().Y;
}

float UOLSlotHUDWiget::GetBackSlotPosY(int32 index)
{
	return Cast<UCanvasPanelSlot>(BackSlot[index - 1]->Slot)->GetPosition().Y;
}

void UOLSlotHUDWiget::SetSlotTexture(int32 index, UTexture2D * texture)
{
	FrontSlot[index - 1]->SetBrushFromTexture(texture);
}

void UOLSlotHUDWiget::SetBackSlotTexture(int32 index, UTexture2D * texture)
{
	BackSlot[index - 1]->SetBrushFromTexture(texture);
}

void UOLSlotHUDWiget::NativeConstruct() {
	Super::NativeConstruct();
	FrontSlot[0] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_1")));
	BackSlot[0] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_1B")));
	FrontSlot[1] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_2")));
	BackSlot[1] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_2B")));
	FrontSlot[2] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_3")));
	BackSlot[2] = Cast<UImage>(GetWidgetFromName(TEXT("Slot_3B")));


}
