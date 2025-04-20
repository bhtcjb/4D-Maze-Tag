// Fill out your copyright notice in the Description page of Project Settings.

#include "FourDCharacter.h"

// Sets default values
AFourDCharacter::AFourDCharacter()
{
	dimensionW = 0.0f;

	// set mesh for character
	playerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));

	// attach camera to player
	playerCamera->SetupAttachment(RootComponent);

	// attach mesh to player
	playerMesh->SetupAttachment(RootComponent);

	// set the default mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> defaultMesh(TEXT("/Game/Assets/andy"));
	if (defaultMesh.Succeeded())
	{
		playerMesh->SetStaticMesh(defaultMesh.Object);
	}

	// offset height of camera
	playerCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 65.0f));

	// offset height of mesh
	playerMesh->SetRelativeLocation(FVector(-4.0f, 0.0f, -95.0f));

	// correct rotation
	playerMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// correct height
	playerMesh->SetRelativeScale3D(FVector(0.85f, 0.85f, 0.85f));

	// let controller control camera
	playerCamera->bUsePawnControlRotation = true;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);
	SetReplicateMovement(true);

}

// Called when the game starts or when spawned
void AFourDCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFourDCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);
	if (APlayerController* PC = Cast<APlayerController>(NewController)) {
		PC->SetViewTarget(this);
		UE_LOG(LogTemp, Log, TEXT("Possessed by %s, view target set (Role: %d)"), *PC->GetName(), (int32)GetLocalRole());
	}
}

void AFourDCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFourDCharacter, dimensionW);
}

// Called every frame
void AFourDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// update the mesh rotation to match the camera's rotation
	if (playerCamera && playerMesh)
	{
		FRotator cameraRotation = playerCamera->GetComponentRotation();
		FRotator meshRotation(0.0f, cameraRotation.Yaw - 90.0f, 0.0f);
		playerMesh->SetWorldRotation(meshRotation);
	}
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
	AddMovementInput(GetActorRightVector(), magnitude * MoveSpeed);
}


void AFourDCharacter::rightLeftMovement(float magnitude)
{
	AddMovementInput(GetActorForwardVector(), magnitude * MoveSpeed * -1);
}

void AFourDCharacter::fourthDimensionMovement(float magnitude)
{
	if (magnitude != 0.0f)
	{
		float speed = 1; // because we don't have AddMovementInput() for 4d,
		// we must calculate manually, magnitude * speed * time
		// multiplying by time is necessary for smooth movement across framerates
		dimensionW += magnitude * speed * GetWorld()->DeltaTimeSeconds;

		// broadcast event to the objects
		wChangeEvent.Broadcast(dimensionW);
	}
}

void AFourDCharacter::turnRightLeft(float magnitude)
{
	AddControllerYawInput(magnitude * RotateSpeed);
}

void AFourDCharacter::turnUpDown(float magnitude)
{
	if (magnitude != 0.0f)
	{
		// pitch means up down, moves pitch
		AddControllerPitchInput(magnitude);
	}
}
