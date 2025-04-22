// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	ASpeedCoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnContact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// Called when the player touches the coin
	UFUNCTION(Server, Reliable)
	void Server_Jump();
	void Server_Jump_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_SetHidden(bool Hidden);
	void Server_SetHidden_Implementation(bool Hidden);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void OnRep_IsHidden();

public:	
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

	void ReappearCoin();
};
