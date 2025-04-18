// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase()
{
    DefaultPawnClass = AFourDCharacter::StaticClass(); 
    HUDClass = AMainHUD::StaticClass();
}

void AMyGameModeBase::StartPlay()
{
    Super::StartPlay();

    TestFunctions test;
}