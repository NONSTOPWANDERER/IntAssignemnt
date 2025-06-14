// Fill out your copyright notice in the Description page of Project Settings.


#include "SlashAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyProject2Character.h"

void ASlashAIController::BeginPlay()
{
    Super::BeginPlay();
    if(AIBehavior)
    {
        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
    } 
}

void ASlashAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

bool ASlashAIController::IsDead() const
{
    AMyProject2Character* ControlledCharacter=Cast<AMyProject2Character>(GetPawn());
    if(ControlledCharacter) return ControlledCharacter->IsDead();
    return true;
}
