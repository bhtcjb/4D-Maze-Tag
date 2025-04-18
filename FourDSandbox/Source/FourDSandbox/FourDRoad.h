// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "FourDRoad.generated.h"

UCLASS()
class FOURDSANDBOX_API AFourDRoad : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFourDRoad();

	UPROPERTY(EditAnywhere, Category = "4D Settings")
	float dimensionW;

	UPROPERTY(EditAnywhere, Category = "4D Settings")
	float dimensionWAutoSpeed;

	UPROPERTY(EditAnywhere, Category = "4D Settings")
	bool autoAnimateDimensionW;

	UPROPERTY(EditAnywhere, Category = "4D Settings")
	float roadWidth;

	UPROPERTY(EditAnywhere, Category = "Visual Settings")
	UStaticMesh* CrossSectionMesh;

	UPROPERTY(EditAnywhere, Category = "Visual Settings")
	UMaterialInterface* RoadMaterial;

	UFUNCTION(BlueprintCallable, Category = "4D Functions")
	void UpdateCrossSection();

	UFUNCTION(BlueprintCallable, Category = "4D Functions")
	void AttachCustomGeometry(UStaticMesh* CustomMesh, UMaterialInterface* CustomMaterial);

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* RoadMesh;

	UPROPERTY()
	TArray<UStaticMeshComponent*> AttachedGeometryComponents;

	TArray<FVector4> RoadVertices;

	TArray<TPair<int32, int32>> RoadEdges;

	void SetupRoad();

	void GenerateCrossSection(float dimW);

	FVector ProjectTo3D(const FVector4& Point4D, float dimW);

	bool EdgeIntersectsWPlane(const FVector4& V1, const FVector4& V2, float dimW, FVector& Intersection);

	float AnimationDirection = 1.0f;

};
