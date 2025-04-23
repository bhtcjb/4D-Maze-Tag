// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedCoin.h"

// Sets default values
ASpeedCoin::ASpeedCoin()
{
	bReplicates = true;
	SetReplicateMovement(true);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	RootComponent = CoinMesh;
	CoinMesh->SetSimulatePhysics(true);
	CoinMesh->SetGenerateOverlapEvents(true);
	CoinMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CoinMesh->SetCollisionObjectType(ECC_WorldDynamic);
	CoinMesh->SetCollisionResponseToAllChannels(ECR_Block);
	CoinMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CoinMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	CoinSize = 1.0f;
	Livetime = 2.0f;

	ReappearDelay = 5.0f;
	IsHidden = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> defaultMesh(TEXT("/Engine/EngineMeshes/Cylinder"));
	if (defaultMesh.Succeeded())
	{
		CoinMesh->SetStaticMesh(defaultMesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> defaultMaterial(TEXT("/Game/StarterContent/Materials/M_Metal_Gold"));
	if (defaultMaterial.Succeeded())
	{
		CoinMesh->SetMaterial(0, defaultMaterial.Object);
	}

	CoinMesh->SetRelativeScale3D(FVector(CoinSize, CoinSize, CoinSize));
	CoinMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

}

// Called when the game starts or when spawned
void ASpeedCoin::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) // added by Khoa
	{
		// Adjust spawn position with sweep to ensure on ground.
		FVector Start = GetActorLocation();
		FVector End = Start + FVector(0.0f, 0.0f, -50.0f); // Trace downward.
		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_WorldStatic, FCollisionQueryParams::DefaultQueryParam))
		{
			// Move actor to hit location, just above ground.
			SetActorLocation(Hit.Location + FVector(0.0f, 0.0f, 10.0f));
			UE_LOG(LogTemp, Log, TEXT("JumpingActor snapped to ground at %s"), *Hit.Location.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("JumpingActor: No ground found at %s"), *Start.ToString());
		}

		// Call Server_Jump every 3 seconds
		GetWorldTimerManager().SetTimer(JumpTimerHandle, this, &ASpeedCoin::Server_Jump, 3.0f, true);
	
		CoinMesh->OnComponentBeginOverlap.AddDynamic(this, &ASpeedCoin::OnContact); // -Blake changed it to check overlap to see if that would work
	}
}

void ASpeedCoin::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASpeedCoin, IsHidden); // added by Khoa
}

void ASpeedCoin::OnRep_IsHidden()
{
	CoinMesh->SetVisibility(!IsHidden);
	CoinMesh->SetCollisionEnabled(IsHidden ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	if (!IsHidden)
	{
		CoinMesh->SetSimulatePhysics(true);
	}
}

//void ASpeedCoin::OnContact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
//{
//	if (AFourDCharacter* Player = Cast<AFourDCharacter>(OtherActor))
//	{
//		if (HasAuthority() && !IsHidden)
//		{
//			Player->SetCoinCount(Player->GetCoinCount() + 1);
//			Server_SetHidden(true);
//			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("JumpingActor hidden!"));
//		}
//	}
//}

void ASpeedCoin::OnContact(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AFourDCharacter* Player = Cast<AFourDCharacter>(OtherActor))
	{
		if (/*HasAuthority() &&*/ !IsHidden)
		{
			Player->SetCoinCount(Player->GetCoinCount() + 1);
			Server_SetHidden(true);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Coin collected!"));
		}
	}
}

// Called every frame
void ASpeedCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FRotator NewRotaion = CoinMesh->GetComponentRotation(); // added by Khoa
	NewRotaion.Yaw += 20.0f * DeltaTime;
	CoinMesh->SetWorldRotation(NewRotaion);
}

// Jump action when player touch to collect the coin
void ASpeedCoin::Server_Jump_Implementation()
{
	if (!IsHidden)
	{
		CoinMesh->AddImpulse(FVector(0.0f, 0.0f, 1000.0f), NAME_None, true);
	}
}

void ASpeedCoin::Server_SetHidden_Implementation(bool Hidden)
{
	IsHidden = Hidden;

	if (Hidden)
	{
		CoinMesh->SetSimulatePhysics(true);
		// Call Reappear again after 10 seconds
		GetWorldTimerManager().SetTimer(ReappearTimerHandle, this, &ASpeedCoin::ReappearCoin, ReappearDelay, false);

	}
}

void ASpeedCoin::ReappearCoin()
{
	Server_SetHidden(false);
}