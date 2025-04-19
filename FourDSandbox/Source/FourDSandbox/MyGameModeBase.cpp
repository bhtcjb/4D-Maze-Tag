// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase()
{
    DefaultPawnClass = AFourDCharacter::StaticClass(); 
    HUDClass = AMainHUD::StaticClass();
	bReplicates = true;
}

void AMyGameModeBase::StartPlay()
{
    Super::StartPlay();
	UGameplayStatics::CreatePlayer(this, 1, true);

    TestFunctions test;
}