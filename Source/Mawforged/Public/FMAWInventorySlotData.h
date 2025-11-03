// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/UserDefinedStruct.h"
#include "FMAWInventoryStack.h"
#include "FMAWInventorySlotData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventorySlotData : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FInventoryStack Stack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    bool bIsOccupied;

    FInventorySlotData()
        : ID(NAME_None)
        , bIsOccupied(false)
    {
    }
};
