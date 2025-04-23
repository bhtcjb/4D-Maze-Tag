// Khoa

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "FourDCharacter.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class FOURDSANDBOX_API AMainHUD : public AHUD
{
	GENERATED_BODY()

public:
    // Author: Khoa
	AMainHUD();

    // Author: Epic Games
    virtual void DrawHUD() override;

protected:
    UPROPERTY()
	class AFourDCharacter* PlayerCharacter;

    UPROPERTY(EditAnywhere, Category = "HUD")
    UFont* HUDFont;

    // Text and background properties
    UPROPERTY(EditAnywhere, Category = "HUD")
    FVector2D TextPosition = FVector2D(50, 50);

    UPROPERTY(EditAnywhere, Category = "HUD")
    float TextScale = 1.5f;

    UPROPERTY(EditAnywhere, Category = "HUD")
    FLinearColor TextColor = FLinearColor::White;

    UPROPERTY(EditAnywhere, Category = "HUD")
    FLinearColor BackgroundColor = FLinearColor(0, 0, 0, 0.7f);

    UPROPERTY(EditAnywhere, Category = "HUD")
    FVector2D BackgroundPadding = FVector2D(10, 5);
};
