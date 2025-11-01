// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/UserDefinedStruct.h"
#include "MAWCollectableAsset.h"
#include "FMAWInventoryStack.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventoryStack : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    UMAWCollectableAsset* ItemData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    int32 Quantity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    TArray<FName> CustomData;

    FInventoryStack()
        : Quantity(0)
    {
    }
};