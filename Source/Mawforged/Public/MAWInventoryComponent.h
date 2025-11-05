// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FMAWInventorySlotData.h"
#include "FMAWInventoryStack.h"
#include "FMAWInventorySize.h"
#include "FMAWForgableStat.h"
#include "MAWInventoryComponent.generated.h"


UCLASS(ClassGroup = (Custom), Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class MAWFORGED_API UMAWInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMAWInventoryComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	class AActor* OwningActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FInventorySize InventorySize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventorySlotData> Inventory;

	template <typename T>
	void FillArray(TArray<T>& TargetArray, int32 Size);

	template <typename T>
	static bool BindItemToSlot(TArray<T>& TargetArray, int32 Index, T Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeInventory();

	UFUNCTION(BlueprintCallable, Category = "Item Validation")
	void CheckIfItemExist(FName ID, bool& bHasItem, FInventoryStack& StackData);

	UFUNCTION(BlueprintCallable, Category = "Item Validation")
	FInventoryStack GetAllItemsFromID(FName ID) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool FindEmptyInventorySlot(int32& SlotIndex) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void GetAllItemsInInventory(TArray<FName>& IDs, TArray<FInventoryStack>& Stacks) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	double CalculateTotalInventoryWeight() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
