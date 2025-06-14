// Fill out your copyright notice in the Description page of Project Settings.


#include "SlashPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
void ASlashPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    HUD->RemoveFromParent();
    if(bIsWinner)
    {
        UUserWidget* WinScreen=CreateWidget(this,WinScreenClass);
        if(WinScreen) WinScreen->AddToViewport(); 
    }
    else
    {
        UUserWidget* LoseScreen=CreateWidget(this,LoseScreenClass);
        if(LoseScreen) LoseScreen->AddToViewport(); 
    }
    GetWorldTimerManager().SetTimer(RestartTimer,this,&APlayerController::RestartLevel,RestartDelay);
}

void ASlashPlayerController::BeginPlay()
{
        HUD=CreateWidget(this,HUDClass);
        if(HUD) HUD->AddToViewport(); 
}