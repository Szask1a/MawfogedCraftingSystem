// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MAWCollectableAsset.h"
#include "MAWInteractables.h"
#include "MAWCollectableObject.generated.h"

UCLASS()
class MAWFORGED_API AMAWCollectableObject : public AActor, public IMAWInteractables
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMAWCollectableObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	UMAWCollectableAsset* ItemData;

	virtual void OnInteraction_Implementation(APawn* InteractingPawn) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
