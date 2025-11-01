// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/UserDefinedStruct.h"
#include "Engine/DataTable.h"
#include "MAWCollectableAsset.h"
#include "FMAWRecipeDefinition.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRecipeDefinition : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName RecipeID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    TSoftObjectPtr<UTexture2D> RecipeIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName CraftableStation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    FName Category;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    bool bIsFixed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    TMap<TSoftObjectPtr<UMAWCollectableAsset>, int32> RequiredIngrediants;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    TSoftObjectPtr<UMAWCollectableAsset> Outcome;

    FRecipeDefinition()
        : RecipeID(NAME_None)
        , CraftableStation(NAME_None)
        , Category(NAME_None)
        , bIsFixed(false)
    {
    }
};
