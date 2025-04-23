// Blake Turman 4/8/25

#pragma once

#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

#include "FourDCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWChange, float, newW); // sets up event to broadcast 

UCLASS()
class FOURDSANDBOX_API AFourDCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Author: Blake
	// Sets default values for this character's properties
	AFourDCharacter();

	// UPROPERTY allows variable dimensionW to be editable in UE
	UPROPERTY(EditAnywhere, Category = "4D Position", Replicated)
	float dimensionW; // position variable for 4th dimension


	UPROPERTY(VisibleAnywhere, Category = "4D Position")
	FWChange wChangeEvent; // variable to broadcast event for changes in W to objects

	// Author: Epic Games
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Author: Khoa
	float GetDimensionW() const;

	// Author: Khoa
	bool GetTagged() const;

	// Author: Khoa
	void SetTagged(bool tagged);

	// Author: Khoa
	float GetSpeed() const;

	// Author: Khoa
	void SetSpeed(float speed);

	// Author: Khoa
	int32 GetCoinCount() const;

	// Author: Khoa
	void SetCoinCount(int32 count);

protected:
	// Author: Epic Games
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Author: Epic Games
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Author: Blake
	// set up forward backward movement
	void forwardBackMovement(float magnitude);

	// Author: Blake
	// set up left right movement
	void rightLeftMovement(float v);

	// Author: Blake
	// set up fourthDimensionalMovement
	void fourthDimensionMovement(float v);

	// Author: Blake
	// set up left right camera movements
	void turnRightLeft(float magnitude);

	// Author: Blake
	// set up upward downward camera movements
	void turnUpDown(float magnitude);

	// Author: Khoa
	// set up tag function
	void TagPlayer(float clicked);

	// Author: Khoa
	// Adjust speed when collect coin
	void AdjustSpeed();

	// Author: Khoa
	// set up tag server logic
	UFUNCTION(Server, Reliable)
	void Server_TagOtherPlayer();

	// Author: Blake
	// set up w slice server logic
	UFUNCTION(Server, Reliable)
	void Server_SetDimensionW(float newW);
	
	// Author: Blake
	// diminishes opacity of other characters if not in same slice
	void sliceOpacity();

	// add camera
	UCameraComponent* playerCamera;

	// add character mesh
	UStaticMeshComponent* playerMesh;

	// for making dynamic material
	UMaterialInstanceDynamic* playerMaterial;

	// change movement speed
	float MoveSpeed;

	// range that one can tag within
	float TagRange;

	// if someone is tagged
	UPROPERTY(Replicated)
	bool Tagged;

	// number coins one has to increase speed
	int32 CoinCount;
};
