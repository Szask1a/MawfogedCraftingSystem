// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MAWCraftingResolver.h"
#include "MAWCraftingWorkstation.generated.h"

class UMAWInventoryComponent;

UCLASS()
class MAWFORGED_API AMAWCraftingWorkstation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMAWCraftingWorkstation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	APawn* InteractingPawn = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crafting", meta = (AllowPrivateAccess = "true"))
	UMAWCraftingResolver* CraftingResolver;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void EnterWorkstation(APawn* InteractingPlayer);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void ExitWorkstation(APawn* InteractingPlayer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
