// Fill out your copyright notice in the Description page of Project Settings.

#include "SlotMachineController.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "OLSlotHUDWiget.h"

// Sets default values
ASlotMachineController::ASlotMachineController()
{
	static ConstructorHelpers::FClassFinder<UOLSlotHUDWiget> UI_HUD_C(TEXT("/Game/SlotMachine/UI_SlotMachineWiget.UI_SlotMachineWiget_C"));
	if (UI_HUD_C.Succeeded()) {
		HUDWidgetClass = UI_HUD_C.Class;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> GOLD(TEXT("Texture2D'/Game/Texture/Gold.Gold'"));
	if (GOLD.Succeeded()) {
		Gold = GOLD.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> SILVER(TEXT("Texture2D'/Game/Texture/Gold.Gold'"));
	if (SILVER.Succeeded()) {
		Silver= SILVER.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> BRONDS(TEXT("Texture2D'/Game/Texture/Gold.Gold'"));
	if (BRONDS.Succeeded()) {
		Bronds = BRONDS.Object;
	}

}


// Called when the game starts or when spawned
void ASlotMachineController::BeginPlay()
{
	Super::BeginPlay();
	HUDWidget = CreateWidget<UOLSlotHUDWiget>(this, HUDWidgetClass);
	HUDWidget->AddToViewport();
	CanvasSlot = Cast<UCanvasPanelSlot>(HUDWidget->Slot);

	HUDWidget->GetSlot(1)->SetBrushFromTexture(Gold);
	HUDWidget->GetSlot(2)->SetBrushFromTexture(Silver);
	HUDWidget->GetSlot(3)->SetBrushFromTexture(Bronds);
	
}

UOLSlotHUDWiget * ASlotMachineController::GetHUDWiget() const
{
	return HUDWidget;
}

void ASlotMachineController::MoveSlot(float DeltaTime)
{
	Cast<UCanvasPanelSlot>(HUDWidget->GetSlot(1)->Slot)->SetPosition(FVector2D(0.0f, 600.0f));
	HUDWidget->GetSlot(1)->RenderTransform.Translation.Y;
	HUDWidget->GetSlot(2)->RenderTransform.Translation.Y;
	HUDWidget->GetSlot(3)->RenderTransform.Translation.Y;
}

void ASlotMachineController::MoveBackSlot()
{
	HUDWidget->GetBackgroundSlot(1)->RenderTransform.Translation.Y;
	HUDWidget->GetBackgroundSlot(2)->RenderTransform.Translation.Y;
	HUDWidget->GetBackgroundSlot(3)->RenderTransform.Translation.Y;
}

// Called every frame
void ASlotMachineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveSlot(DeltaTime);
}

