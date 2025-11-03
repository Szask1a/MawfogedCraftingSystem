// Fill out your copyright notice in the Description page of Project Settings.


#include "MAWCraftingResolver.h"

// Sets default values for this component's properties
UMAWCraftingResolver::UMAWCraftingResolver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMAWCraftingResolver::BeginPlay()
{
	Super::BeginPlay();

	GetAllCraftableItems();
	
}


// Called every frame
void UMAWCraftingResolver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMAWCraftingResolver::SetInteractingPawn(APawn* InteractingPlayer)
{
	if (InteractingPlayer)
	{
		InteractingPawn = InteractingPlayer;
	}
	else
	{
		InteractingPawn = nullptr;
	}
}

void UMAWCraftingResolver::PushCraftingMenu_Implementation()
{
	// To Override Pushing Widget into the Stack
}

void UMAWCraftingResolver::RemoveCraftingMenu_Implementation()
{
	// To Override Removing Widget from the Stack
}

void UMAWCraftingResolver::GetAllCraftableItems()
{
	if (RecipeTable)
	{
		TArray<FName> RowNames = RecipeTable->GetRowNames();

		for (const FName& RowName : RowNames)
		{
			FRecipeDefinition* Row = RecipeTable->FindRow<FRecipeDefinition>(RowName, TEXT(""));

			if (!Row)
			{
				continue;
			}

			if (Row->CraftableStation == StationID)
			{
				Craftables.AddUnique(Row->RecipeID);
			}
		}
	}
}

void UMAWCraftingResolver::FilterUnlockedItems()
{
	// Add logic to filter unlocked items based on player progress
	UnlockedCraftables = Craftables;
}

FRecipeDefinition UMAWCraftingResolver::GetRecipeFromID(FName CraftableID)
{
	if (RecipeTable)
	{
		FRecipeDefinition* Row = RecipeTable->FindRow<FRecipeDefinition>(CraftableID, TEXT("GetRecipeFromID"));
		if (Row)
		{
			return *Row;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Recipe ID '%s' not found in Recipe Table."), *CraftableID.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Recipe Table is not valid."), *CraftableID.ToString());
	}
	return FRecipeDefinition();
}

void UMAWCraftingResolver::GetForgableStatFromGroup(FName GroupName, TArray<FForgableStat>& PossibleStats)
{
	PossibleStats.Empty();

	static const FString ContextString(TEXT("GetForgableStatFromGroup"));

	UDataTable* ForgableStatsTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/_Mawforged/Crafting/DT_ForgableStats.DT_ForgableStats"));
	if (!ForgableStatsTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("DT_ForgableStats not found!"));
		return;
	}

	TArray<FName> RowNames = ForgableStatsTable->GetRowNames();

	for (const FName& RowName : RowNames)
	{
		FForgableStat* Row = ForgableStatsTable->FindRow<FForgableStat>(RowName, ContextString);
		if (!Row)
			continue;

		if (Row->GroupName == GroupName)
		{
			PossibleStats.Add(*Row);
		}
	}
}

FForgableStat UMAWCraftingResolver::HandleWeaponAlignment(FName Alignment)
{
	FForgableStat Result;
	TArray<FForgableStat> PossibleStats;

	GetForgableStatFromGroup(Alignment, PossibleStats);

	if (PossibleStats.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, PossibleStats.Num() - 1);
		Result = PossibleStats[RandomIndex];
	}

	return Result;
}

bool UMAWCraftingResolver::CheckIfRequirementsMet(const TMap<UMAWCollectableAsset*, int32>& Ingredients, UMAWInventoryComponent* InventoryComponent)
{
	if (!InventoryComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("CheckIfRequirementsMet: InventoryComponent is null"));
		return false;
	}

	bool bCanCraft = true;

	for (const TPair<UMAWCollectableAsset*, int32>& Pair : Ingredients)
	{
		UMAWCollectableAsset* Ingredient = Pair.Key;
		int32 RequiredQty = Pair.Value;

		if (!Ingredient)
		{
			bCanCraft = false;
			break;
		}

		bool bHasItem = false;
		FInventoryStack StackData;
		InventoryComponent->CheckIfItemExist(Ingredient->ItemID, bHasItem, StackData);

		if (!bHasItem || StackData.Quantity < RequiredQty)
		{
			bCanCraft = false;
			break;
		}
	}

	return bCanCraft;
}