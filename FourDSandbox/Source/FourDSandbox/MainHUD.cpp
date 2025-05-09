#include "MainHUD.h"

AMainHUD::AMainHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont> FontFinder(TEXT("/Engine/EngineFonts/Roboto.Roboto"));
	if (FontFinder.Succeeded()) {
		HUDFont = FontFinder.Object;
	}
}

void AMainHUD::DrawHUD()
{
    Super::DrawHUD();

    if (!Canvas || !HUDFont) return; // added by Khoa

    if (!PlayerCharacter) {
        APlayerController* PC = GetOwningPlayerController();
        if (PC && PC->GetPawn()) {
            PlayerCharacter = Cast<AFourDCharacter>(PC->GetPawn());
        }
    }

    if (PlayerCharacter) {
        // Format the dimensionW value
        FString WText = FString::Printf(TEXT("W: %.2f\nTagged: %d"),
            PlayerCharacter->GetDimensionW(),
            (PlayerCharacter->GetTagged()));

        // Calculate text size
        float TextWidth, TextHeight;
        Canvas->TextSize(HUDFont, WText, TextWidth, TextHeight, TextScale, TextScale);

        // Draw background box
        FCanvasBoxItem Background(
            TextPosition - BackgroundPadding,
            FVector2D(TextWidth + 2 * BackgroundPadding.X, TextHeight + 2 * BackgroundPadding.Y)
        );
        Background.SetColor(BackgroundColor);
        Canvas->DrawItem(Background);

        // Draw text (corrected call)
        FCanvasTextItem TextItem(
            TextPosition,
            FText::FromString(WText),
            HUDFont,
            TextColor
        );
        TextItem.Scale = FVector2D(TextScale, TextScale);
        Canvas->DrawItem(TextItem);
    }
}


