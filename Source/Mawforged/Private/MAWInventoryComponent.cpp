// Fill out your copyright notice in the Description page of Project Settings.


#include "MAWInventoryComponent.h"

// Sets default values for this component's properties
UMAWInventoryComponent::UMAWInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMAWInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMAWInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMAWInventoryComponent::CheckIfItemExist(FName ID, bool& bHasItem, FInventoryStack& StackData)
{
    bHasItem = false;
    StackData = FInventoryStack();

    for (const FInventorySlotData& Slot : Inventory)
    {
        if (!Slot.bIsOccupied)
            continue;

        if (Slot.ID == ID)
        {
            bHasItem = true;
            StackData = Slot.Stack;
            return;
        }
    }
    bHasItem = false;
}

FInventoryStack UMAWInventoryComponent::GetAllItemsFromID(FName ID) const
{
    int32 LStackQuantity = 0;
    UMAWCollectableAsset* LStackItem = nullptr;
    TArray<FStatModifier> LStackData;

    for (const FInventorySlotData& Slot : Inventory)
    {
        if (!Slot.bIsOccupied)
            continue;

        if (Slot.ID == ID)
        {
            LStackQuantity += Slot.Stack.Quantity;
            LStackItem = Slot.Stack.ItemData;

            LStackData.Append(Slot.Stack.CustomData);
        }
    }

    FInventoryStack CombinedStack;
    CombinedStack.ItemData = LStackItem;
    CombinedStack.Quantity = LStackQuantity;
    CombinedStack.CustomData = LStackData;

    return CombinedStack;
}

template <typename T>
void UMAWInventoryComponent::FillArray(TArray<T>& TargetArray, int32 Size)
{
    if (TargetArray.IsEmpty())
    {
        for (int32 Index = 0; Index < Size; ++Index)
        {
            TargetArray.AddDefaulted();
        }
    }
}

template <typename T>
static bool UMAWInventoryComponent::BindItemToSlot(TArray<T>& TargetArray, int32 Index, T Item)
{
    if (!TargetArray.IsValidIndex(Index))
    {
        return false;
    }

    TargetArray[Index] = Item;
    return true;
}

void UMAWInventoryComponent::InitializeInventory()
{
    OwningActor = GetOwner();

    if (!OwningActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("InventoryComponent on a component with no Owner!"));
    }

    const int32 InventoryCapacity = InventorySize.Rows * InventorySize.Columns;

    FillArray(Inventory, InventoryCapacity);
}

double UMAWInventoryComponent::CalculateTotalInventoryWeight() const
{
    double TotalWeight = 0.0;

    for (const FInventorySlotData& Slot : Inventory)
    {
        const FInventoryStack& Stack = Slot.Stack;

        if (Stack.ItemData && Stack.ItemData->Weight > 0.0)
        {
            TotalWeight += static_cast<double>(Stack.Quantity) * Stack.ItemData->Weight;
        }
    }

    return TotalWeight;
}

bool UMAWInventoryComponent::FindEmptyInventorySlot(int32& SlotIndex) const
{
    for (int32 Index = 0; Index < Inventory.Num(); ++Index)
    {
        const FInventorySlotData& Slot = Inventory[Index];
        if (!Slot.bIsOccupied)
        {
            SlotIndex = Index;
            return true;
        }
    }

    SlotIndex = -1;
    return false;
}

void UMAWInventoryComponent::GetAllItemsInInventory(TArray<FName>& IDs, TArray<FInventoryStack>& Stacks) const
{
    IDs.Empty();
    Stacks.Empty();

    for (const FInventorySlotData& SlotData : Inventory)
    {
        if (SlotData.bIsOccupied)
        {
            IDs.Add(SlotData.ID);

            Stacks.Add(SlotData.Stack);
        }
    }
}