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

	static ConstructorHelpers::FObjectFinder<UTexture2D> SILVER(TEXT("Texture2D'/Game/Texture/Silver.Silver'"));
	if (SILVER.Succeeded()) {
		Silver = SILVER.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> BRONDS(TEXT("Texture2D'/Game/Texture/Bronds.Bronds'"));
	if (BRONDS.Succeeded()) {
		Bronds = BRONDS.Object;
	}

	ScrollSpeed = 2000.0f;
	SlotStopCount = 0;
	StopIndex = 1;
}


// Called when the game starts or when spawned
void ASlotMachineController::BeginPlay()
{
	Super::BeginPlay();
	HUDWidget = CreateWidget<UOLSlotHUDWiget>(this, HUDWidgetClass);
	HUDWidget->AddToViewport();
	GetHUDWiget()->SetSlotTexture(1, Gold);
	GetHUDWiget()->SetSlotTexture(2, Bronds);
	GetHUDWiget()->SetSlotTexture(3, Silver);
}

UOLSlotHUDWiget * ASlotMachineController::GetHUDWiget() const
{
	return HUDWidget;
}

void ASlotMachineController::MoveSlot(float DeltaTime)
{
	for (int i = StopIndex; i <= 3; i++) {
		float tmpY = GetHUDWiget()->GetSlotPosY(i);

		if (tmpY >= 600.0f) {
			GetHUDWiget()->SetSlotPosY(i, GetHUDWiget()->GetBackSlotPosY(i) - 300.0f);
			RandomSlotImgChange(i);
		}
		
		tmpY = FMath::FInterpConstantTo(GetHUDWiget()->GetSlotPosY(i), 600.0f, DeltaTime, ScrollSpeed);
		GetHUDWiget()->SetSlotPosY(i, tmpY);
	}
}

void ASlotMachineController::MoveBackSlot(float DeltaTime)
{
	for (int i = StopIndex; i <= 3; i++) {
		float tmpY = GetHUDWiget()->GetBackSlotPosY(i);

		if (tmpY >= 600.0f) {
			if (i == 3) {
				SlotStopCount++;
				if (SlotStopCount % 10 == 0) {
					if (StopIndex == 1)
						GetHUDWiget()->SetSlotPosY(1, 300.0f);
					else if (StopIndex == 2)
						GetHUDWiget()->SetSlotPosY(2, 300.0f);
					else if (StopIndex == 3)
						GetHUDWiget()->SetSlotPosY(3, 300.0f);
					StopIndex++;
				}
			}
			RandomBackSlotImgChange(i);
			GetHUDWiget()->SetBackSlotPosY(i, GetHUDWiget()->GetSlotPosY(i) - 300.0f);
		}

		tmpY = FMath::FInterpConstantTo(GetHUDWiget()->GetBackSlotPosY(i), 600.0f, DeltaTime, ScrollSpeed);
		GetHUDWiget()->SetBackSlotPosY(i, tmpY);

	}
}

void ASlotMachineController::RandomSlotImgChange(int8 index)
{
	int32 tmp = FMath::RandRange(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("%d"), tmp);
	if (tmp == 1) {
		GetHUDWiget()->SetSlotTexture(index, Bronds);
	}
	else if (tmp == 2) {
		GetHUDWiget()->SetSlotTexture(index, Silver);
	}
	else if (tmp == 3) {
		GetHUDWiget()->SetSlotTexture(index, Gold);
	}
}

void ASlotMachineController::RandomBackSlotImgChange(int8 index)
{
	for (int i = 0; i < 3; i++) {
		int32 tmp = FMath::RandRange(0, 2);
		if (tmp == 0) {
			GetHUDWiget()->SetBackSlotTexture(index, Bronds);
		}
		else if (tmp == 1) {
			GetHUDWiget()->SetBackSlotTexture(index, Silver);
		}
		else if (tmp == 2) {
			GetHUDWiget()->SetBackSlotTexture(index, Gold);
		}
	}
}

void ASlotMachineController::SetSlots()
{
	float provability = FMath::RandRange(0.0f, 100.0f);
	int8 rand = FMath::RandRange(0, 2);

	if (provability < SpecialProvability) {//½ºÆä¼È È®·ü
		for (int i = 0; i < 3; i++) {
			TextureIndex[i] = rand;
		}
	}
	else if (provability < GoldProvability) {//°ñµå È®·ü
		for (int i = 0; i < 3; i++) {
			TextureIndex[i] = (int)Grade::Gold;
		}
		if (rand == 1)
			TextureIndex[2] = (int)Grade::Silver;
		else
			TextureIndex[2] = (int)Grade::Bronds;

		Swap(TextureIndex[rand], TextureIndex[2]);
	}
	else if (provability < SilverProvability) {//½Ç¹ö È®·ü
		for (int i = 0; i < 3; i++) {
			TextureIndex[i] = (int)Grade::Silver;
		}

		if (rand == 1)
			TextureIndex[2] = (int)Grade::Bronds;
		else
			TextureIndex[2] = (int)Grade::Gold;

		Swap(TextureIndex[rand], TextureIndex[2]);
	}
	else{//ºê·ÐÁî
		for (int i = 0; i < 3; i++) {
			TextureIndex[i] = i + 1;
		}
		if (rand == 1)
			TextureIndex[2] = (int)Grade::Bronds;
	}
	
}

// Called every frame
void ASlotMachineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveBackSlot(DeltaTime);
	MoveSlot(DeltaTime);
}

