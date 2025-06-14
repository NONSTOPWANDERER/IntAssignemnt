// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProject2GameMode.h"
#include "MyProject2Character.h"
#include "UObject/ConstructorHelpers.h"
#include "SlashAIController.h"
#include "EngineUtils.h"

AMyProject2GameMode::AMyProject2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void AMyProject2GameMode::PawnKilled(APawn* PawnKilled)
{
    UE_LOG(LogTemp, Warning, TEXT("Dead"));
    APlayerController* PlayerController=Cast<APlayerController>(PawnKilled->GetController());
    if(PlayerController)
    {
        EndGame(false);
    }
    for(ASlashAIController* Controller:TActorRange<ASlashAIController>(GetWorld()))
    {
        if(!Controller->IsDead()) return; 
    }
    EndGame(true);
}

void AMyProject2GameMode::EndGame(bool bIsPlayerWinner)
{
    for(AController* Controller:TActorRange<AController>(GetWorld()))
    {
        if((Controller->IsPlayerController()==bIsPlayerWinner)){
        Controller->GameHasEnded(Controller->GetPawn(),true);
		UE_LOG(LogTemp, Warning, TEXT("Not Done"));
		}
        else{
        Controller->GameHasEnded(Controller->GetPawn(),false);
		UE_LOG(LogTemp, Warning, TEXT("Done"));
		}
    } 
}
