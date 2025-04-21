// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"



class AFourDCharacter;
/**
 * 
 */
UCLASS()
class FOURDSANDBOX_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	void sliceOpacity(AFourDCharacter* thisPlayer);
};
