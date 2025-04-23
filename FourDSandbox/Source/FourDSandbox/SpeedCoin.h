// Khoa

#pragma once

#include "FourDCharacter.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/DefaultPawn.h"
#include "SpeedCoin.generated.h"

UCLASS()
class FOURDSANDBOX_API ASpeedCoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Author: Khoa
	// Sets default values for this actor's properties
	ASpeedCoin();

protected:
	// Author: Epic Games
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Author: Khoa
	UFUNCTION()
//	void OnContact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	// -Blake changed it to check overlap to see if that would work
	void OnContact(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 

	// Author: Khoa
	// Called when the player touches the coin
	UFUNCTION(Server, Reliable)
	void Server_Jump();

	// Author: Khoa
	UFUNCTION(Server, Reliable)
	void Server_SetHidden(bool Hidden);

	// Author: Epic Games
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Author: Khoa
	UFUNCTION()
	virtual void OnRep_IsHidden();

public:	
	// Author: Epic Games
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle JumpTimerHandle;

	FTimerHandle ReappearTimerHandle;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY()
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere)
	float CoinSize;

	UPROPERTY(EditAnywhere)
	float Livetime;

	UPROPERTY(EditAnywhere)
	float ReappearDelay;

	UPROPERTY(VisibleAnywhere, Replicated)
	bool IsHidden;

	// Author: Khoa
	void ReappearCoin();
};
