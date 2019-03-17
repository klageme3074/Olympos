// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Olypos.h"
#include "GameFramework/PlayerController.h"
#include "SlotMachineController.generated.h"

/**
 * 
 */
UCLASS()
class OLYPOS_API ASlotMachineController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASlotMachineController();

	class UOLSlotHUDWiget* GetHUDWiget() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UOLSlotHUDWiget> HUDWidgetClass;

	void MoveSlot(float DeltaTime);
	void MoveBackSlot(float DeltaTime);

	void RandomSlotImgChange(int8 index);
	void RandomBackSlotImgChange(int8 index);

	void SetSlots();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	class UOLSlotHUDWiget* HUDWidget;

	UPROPERTY()
	class UTexture2D* Bronds;

	UPROPERTY()
	class UTexture2D* Silver;

	UPROPERTY()
	class UTexture2D* Gold;

	UPROPERTY(EditAnywhere)
	float ScrollSpeed;

	UPROPERTY(EditAnywhere)
	float BrondsProvability;

	UPROPERTY(EditAnywhere)
	float SilverProvability;

	UPROPERTY(EditAnywhere)
	float GoldProvability;

	UPROPERTY(EditAnywhere)
	float SpecialProvability;

	UPROPERTY()
	int8 TextureIndex[3];

	UPROPERTY()
	int8 SlotStopCount;

	UPROPERTY()
	int8 StopIndex;
};
