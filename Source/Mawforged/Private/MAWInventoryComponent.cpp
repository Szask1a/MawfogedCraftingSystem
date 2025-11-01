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
