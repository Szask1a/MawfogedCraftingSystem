// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EMAWItemRarity.h"
#include "MAWCollectableAsset.generated.h"

/**
 * 
 */
UCLASS()
class MAWFORGED_API UMAWCollectableAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	FText UsageDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	FText LoreDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	UMAWItemRarity ItemRarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FName ItemGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	FName SubGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	bool bIsBound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stack")
	bool bIsStackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stack")
	int MaxStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	TSoftObjectPtr<UTexture2D> SmallThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	TSoftObjectPtr<UTexture2D> BigThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	bool bIsEquipable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Placement")
	TSoftObjectPtr<UStaticMesh> PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Feedback")
	USoundBase* PickupCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Feedback")
	USoundBase* DroppingCue;
};
