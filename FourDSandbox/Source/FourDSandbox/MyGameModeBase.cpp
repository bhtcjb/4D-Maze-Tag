// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase()
{
    DefaultPawnClass = AFourDCharacter::StaticClass();
    HUDClass = AMainHUD::StaticClass();

	bUseSeamlessTravel = true;
}

void AMyGameModeBase::StartPlay()
{
    Super::StartPlay();

    TestFunctions test;
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
  
    if (NewPlayer && NewPlayer->PlayerState)
    {
        if (GetNumPlayers() == 1)
        {
            if (AFourDCharacter* Character = Cast<AFourDCharacter>(NewPlayer->GetPawn()))
            {
                Character->SetTagged(true);
                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
                    FString::Printf(TEXT("%s is tagged!"), *Character->GetName()));
            }
        }
    }

}

void AMyGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}
