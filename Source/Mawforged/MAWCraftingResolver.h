// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MAWInventoryComponent.h"
#include "FMAWRecipeDefinition.h"
#include "FMAWInventoryStack.h"
#include "FMAWForgableStat.h"
#include "MAWInventoryComponent.h"
#include "MAWCraftingResolver.generated.h"

UCLASS( ClassGroup=(Custom), Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent) )
class MAWFORGED_API UMAWCraftingResolver : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMAWCraftingResolver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FName StationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	APawn* InteractingPawn = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	TArray<FName> Craftables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	UDataTable* RecipeTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	TArray<FName> UnlockedCraftables;

	UFUNCTION(BlueprintCallable, Category = "General")
	void SetInteractingPawn(APawn* InteractingPlayer);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "User Interface")
	void PushCraftingMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "User Interface")
	void RemoveCraftingMenu();

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	virtual void GetAllCraftableItems();

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	virtual void FilterUnlockedItems();

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	FRecipeDefinition GetRecipeFromID(FName CraftableID);

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void GetForgableStatFromGroup(FName GroupName, TArray<FForgableStat>& PossibleStats);

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	FForgableStat HandleWeaponAlignment(FName Alignment);

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	bool CheckIfRequirementsMet(const TMap<UMAWCollectableAsset*, int32>& Ingredients, UMAWInventoryComponent* InventoryComponent);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
