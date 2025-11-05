// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/UserDefinedStruct.h"
#include "FMAWInventorySize.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventorySize
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    int32 Rows;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    int32 Columns;

    FInventorySize()
        : Rows(0)
        , Columns(0)
    {
    }
};