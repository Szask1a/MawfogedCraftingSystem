// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/UserDefinedStruct.h"
#include "FMAWStatModifier.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FStatModifier
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName StatID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    float Value;

    FStatModifier()
        : StatID(NAME_None)
		, Value(0)
    {
    }
};