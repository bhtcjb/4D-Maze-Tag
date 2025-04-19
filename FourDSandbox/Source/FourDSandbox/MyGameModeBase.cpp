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
  
}

void AMyGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}