// Blake Turman 4/8/2025

#pragma once

#include "FourDCharacter.h"
#include "MainHUD.h"
#include "TestFunctions.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FOURDSANDBOX_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Author: Blake
	AMyGameModeBase();

	// Author: Epic Games
	void StartPlay() override;

	// Author: Epic Games
	virtual void PostLogin(APlayerController* NewPlayer) override;

	// Author: Epic Games
	virtual void Logout(AController* Exiting) override;
};
