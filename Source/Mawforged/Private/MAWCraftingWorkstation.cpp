// Fill out your copyright notice in the Description page of Project Settings.

#include "MAWCraftingWorkstation.h"

// Sets default values
AMAWCraftingWorkstation::AMAWCraftingWorkstation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CraftingResolver = CreateDefaultSubobject<UMAWCraftingResolver>(TEXT("CraftingResolver"));
}

// Called when the game starts or when spawned
void AMAWCraftingWorkstation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMAWCraftingWorkstation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMAWCraftingWorkstation::EnterWorkstation_Implementation(APawn* InteractingPlayer)
{
	InteractingPawn = InteractingPlayer;
}

void AMAWCraftingWorkstation::ExitWorkstation_Implementation(APawn* InteractingPlayer)
{
	if (InteractingPawn == InteractingPlayer)
	{
		InteractingPawn = nullptr;
	}
}