// Fill out your copyright notice in the Description page of Project Settings.


#include "MAWCollectableObject.h"

// Sets default values
AMAWCollectableObject::AMAWCollectableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMAWCollectableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMAWCollectableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMAWCollectableObject::OnInteraction_Implementation(APawn* InteractingPawn)
{
	//Overrride on child classes
}