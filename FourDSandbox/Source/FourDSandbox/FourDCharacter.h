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
	// Sets default values for this character's properties
	AFourDCharacter();

	// UPROPERTY allows variable dimensionW to be editable in UE
	UPROPERTY(EditAnywhere, Category = "4D Position", Replicated)
	float dimensionW; // position variable for 4th dimension

	UPROPERTY(VisibleAnywhere, Category = "4D Position")
	FWChange wChangeEvent; // variable to broadcast event for changes in W to objects

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetDimensionW() const;
	bool GetTagged() const;
	void SetTagged(bool tagged);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

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

	// set up tag function
	void TagPlayer(float clicked);

	// set up tag server logic
	UFUNCTION(Server, Reliable)
	void Server_TagOtherPlayer();

	// set up w slice server logic
	UFUNCTION(Server, Reliable)
	void Server_SetDimensionW(float newW);
	
	// diminishes opacity of other characters if not in same slice
	void sliceOpacity();
private: 
	// add camera
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* playerCamera;

	// add character mesh
	UPROPERTY(VisibleAnywhere, Category = "Player")
	UStaticMeshComponent* playerMesh;

	UPROPERTY(VisibleAnywhere, Category = "Material")
	UMaterialInstanceDynamic* playerMaterial;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	float TagRange;

	UPROPERTY(Replicated)
	bool Tagged;

};
