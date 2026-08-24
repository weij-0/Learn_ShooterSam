// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.h"

AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}

void AShooterSamGameMode::BeginPlay()
{
	Super::BeginPlay();


	AShooterSamCharacter* Player = Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	// Initialize array
	TArray<AActor*> ShooterAIActors;

	// Get All Actors into array
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), ShooterAIActors);


	// StartBehaviorTree for each actors
	/*
	for (size_t i = 0; i < ShooterAIActors.Num(); i++)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActors[i]);

		if (ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);
		}
	}
	*/
	

	for (AActor* ShooterAIActor : ShooterAIActors)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActor);

		if (ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);
		}
	}
}
