// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/UserDefinedStruct.h"
#include "FMAWForgableStat.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FForgableStat : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName StatName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName GroupName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    float MinValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    float MaxValue;

    FForgableStat()
        : StatName(NAME_None)
        , GroupName(NAME_None)
        , MinValue(0)
        , MaxValue(0)
    {
    }
};