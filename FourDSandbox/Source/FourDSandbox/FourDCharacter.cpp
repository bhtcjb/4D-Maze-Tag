// Fill out your copyright notice in the Description page of Project Settings.

#include "FourDCharacter.h"

// Sets default values
AFourDCharacter::AFourDCharacter()
{
	dimensionW = 0.0f;

	// initialize camera to default
	playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// attach camera to player
	playerCamera->SetupAttachment(RootComponent);

	// offset height of camera
	playerCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));

	// let controller control camera
	playerCamera->bUsePawnControlRotation = true;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFourDCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFourDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFourDCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// bind movement inputs - these are set up in project settings under input, axis mappings
	PlayerInputComponent->BindAxis("ForwardBackMovement", this, &AFourDCharacter::forwardBackMovement);
	PlayerInputComponent->BindAxis("RightLeftMovement", this, &AFourDCharacter::rightLeftMovement);
	PlayerInputComponent->BindAxis("FourthDimensionMovement", this, &AFourDCharacter::fourthDimensionMovement);
	PlayerInputComponent->BindAxis("TurnRightLeft", this, &AFourDCharacter::turnRightLeft);
	PlayerInputComponent->BindAxis("TurnUpDown", this, &AFourDCharacter::turnUpDown);
}

void AFourDCharacter::forwardBackMovement(float magnitude)
{
	if (Controller && magnitude != 0.0f) // 0.0f means no input, thus we should disregard it
	{
		// get where camera is facing
		FRotator camera = Controller->GetControlRotation();

		// find forward direction
		FVector forwardDirection = FRotationMatrix(camera).GetUnitAxis(EAxis::X);

		// move forward in direction of camera
		AddMovementInput(forwardDirection, magnitude);
	}
}


void AFourDCharacter::rightLeftMovement(float magnitude)
{
	if (Controller && magnitude != 0.0f)
	{
		// get where camera is facing
		FRotator camera = Controller->GetControlRotation();

		// find right left axis direction
		FVector rightLeftDirection = FRotationMatrix(camera).GetUnitAxis(EAxis::Y);

		// move right or left relative to the direction of camera
		AddMovementInput(rightLeftDirection, magnitude);
	}
}

void AFourDCharacter::fourthDimensionMovement(float magnitude)
{
	if (magnitude != 0.0f)
	{
		float speed = GetCharacterMovement()->MaxWalkSpeed; // because we don't have AddMovementInput() for 4d,
		// we must calculate manually, magnitude * speed * time
		// multiplying by time is necessary for smooth movement across framerates
		dimensionW += magnitude * speed * GetWorld()->DeltaTimeSeconds;
	}
}

void AFourDCharacter::turnRightLeft(float magnitude)
{
	if (magnitude != 0.0f)
	{
		// yaw means left right, moves yaw
		AddControllerYawInput(magnitude);
	}
}

void AFourDCharacter::turnUpDown(float magnitude)
{
	if (magnitude != 0.0f)
	{
		// pitch means up down, moves pitch
		AddControllerPitchInput(magnitude);
	}
}
