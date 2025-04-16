// Blake Turman 4/8/25

#pragma once

#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FourDCharacter.generated.h"


UCLASS()
class FOURDSANDBOX_API AFourDCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFourDCharacter();

	// UPROPERTY allows variable dimensionW to be editable in UE
	UPROPERTY(EditAnywhere, Category = "4D Position")
	float dimensionW; // position variable for 4th dimension

	// add camera
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* playerCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// set up forward backward movement
	void forwardBackMovement(float magnitude);

	// set up left right movement
	void rightLeftMovement(float v);

	// set up fourthDimensionalMovement
	void fourthDimensionMovement(float v);

	// set up left right camera movements
	void turnRightLeft(float magnitude);

	// set up upward downward camera movements
	void turnUpDown(float magnitude);
};
