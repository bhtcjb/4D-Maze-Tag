// Fill out your copyright notice in the Description page of Project Settings.

#include "FourDCharacter.h"

// Sets default values
AFourDCharacter::AFourDCharacter()
{
	dimensionW = 0.0f;
	location = FVector(0.0f, 0.0f, 0.0f);
	MoveSpeed = 2.0f;
	RotateSpeed = 2.0f;

	// initialize camera to default
	playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// set mesh for character
	playerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = playerMesh; // Set the root component to the mesh
	playerMesh->SetWorldRotation(FRotator(0.0f, 90.0f, 0.0f));

	// attach camera to player
	playerCamera->SetupAttachment(playerMesh);

	// offset height of camera
	playerCamera->SetRelativeLocation(FVector(0.0f, -200.0f, 160.0f));
	playerCamera->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
	playerCamera->FieldOfView = 120.0f;

	// let controller control camera
	//playerCamera->bUsePawnControlRotation = true;

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
	FVector newLocation = GetActorLocation();
	newLocation += GetActorForwardVector() * magnitude * MoveSpeed;
	SetActorLocation(newLocation);
	location = newLocation;

	/*if (magnitude != 0.0f) {
		AddMovementInput(GetActorForwardVector(), magnitude * speed);
		dimensionY += magnitude * speed;
	}*/

}


void AFourDCharacter::rightLeftMovement(float magnitude)
{
	FVector newLocation = GetActorLocation();
	newLocation += GetActorRightVector() * magnitude * MoveSpeed;
	SetActorLocation(newLocation);
	location = newLocation;

	/*if (magnitude != 0.0f) {
		AddMovementInput(GetActorRightVector(), magnitude * speed);
		dimensionX += magnitude * speed;
	}*/
}

void AFourDCharacter::fourthDimensionMovement(float magnitude)
{
	if (magnitude != 0.0f)
	{
		float speed = GetCharacterMovement()->MaxWalkSpeed * .01; // because we don't have AddMovementInput() for 4d,
		// we must calculate manually, magnitude * speed * time
		// multiplying by time is necessary for smooth movement across framerates
		dimensionW += magnitude * speed * GetWorld()->DeltaTimeSeconds;

		// broadcast event to the objects
		wChangeEvent.Broadcast(dimensionW);
	}
}

void AFourDCharacter::turnRightLeft(float magnitude)
{
	FRotator newRotation = GetActorRotation();
	newRotation.Yaw += magnitude * RotateSpeed;
	SetActorRotation(newRotation);
}

void AFourDCharacter::turnUpDown(float magnitude)
{
	// pitch means up down, moves pitch
	/*FRotator newRotation = GetActorRotation();
	newRotation.Roll += magnitude * RotateSpeed;
	SetActorRotation(newRotation);*/
}
