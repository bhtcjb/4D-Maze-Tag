// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "FourDCharacter.h"

void AMyPlayerState::sliceOpacity(AFourDCharacter* thisPlayer)
{
    TArray<AActor*> allPlayers;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFourDCharacter::StaticClass(), allPlayers);

    for (int i = 0; i < allPlayers.Num(); ++i)
    {
        AFourDCharacter* otherPlayer = Cast<AFourDCharacter>(allPlayers[i]);
        if (otherPlayer != nullptr && otherPlayer != thisPlayer)
        {

            if (FMath::Abs(thisPlayer->dimensionW - otherPlayer->dimensionW) > 0.5f)
            {
                if (otherPlayer->playerMaterial)
                {
                    otherPlayer->playerMaterial->SetScalarParameterValue(TEXT("Opacity Mask"), 0.25f);
                }
         
            }
            else
            {
                if (otherPlayer->playerMaterial)
                {
                    otherPlayer->playerMaterial->SetScalarParameterValue(TEXT("Opacity Mask"), 1.0f);
                }
                
            }
        }
    }
}
