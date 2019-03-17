// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Olypos.h"
#include "Blueprint/UserWidget.h"
#include "OLSlotHUDWiget.generated.h"
/**
 * 
 */
UCLASS()
class OLYPOS_API UOLSlotHUDWiget : public UUserWidget
{
	GENERATED_BODY()
public:
	class UImage* GetSlot(int32 index);
	class UImage* GetBackgroundSlot(int32 index);

	void SetSlotPosY(int32 index, float y);
	void SetBackSlotPosY(int32 index, float y);

	float GetSlotPosY(int32 index);
	float GetBackSlotPosY(int32 index);

	void SetSlotTexture(int32 index, UTexture2D* texture);
	void SetBackSlotTexture(int32 index, UTexture2D* texture);
	
protected:
	virtual void NativeConstruct() override;


private:
	UPROPERTY()
	class UImage* FrontSlot[3] = { nullptr, nullptr, nullptr };

	UPROPERTY()
	class UImage* BackSlot[3] = { nullptr, nullptr, nullptr };



};
