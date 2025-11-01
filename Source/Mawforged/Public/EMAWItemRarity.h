// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EMAWItemRarity.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class UMAWItemRarity : uint8
{
    Common      UMETA(DisplayName = "Common"),
    Uncommon    UMETA(DisplayName = "Uncommon"),
    Rare        UMETA(DisplayName = "Rare"),
    Legendary   UMETA(DisplayName = "Legendary")
};