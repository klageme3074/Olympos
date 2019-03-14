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
	//void SetSlot(int32 index, )
protected:
	virtual void NativeConstruct() override;


private:
	UPROPERTY()
	class UImage* FirstSlot[3] = { nullptr, nullptr, nullptr };

	UPROPERTY()
	class UImage* BackGroundSlot[3] = { nullptr, nullptr, nullptr };


};
