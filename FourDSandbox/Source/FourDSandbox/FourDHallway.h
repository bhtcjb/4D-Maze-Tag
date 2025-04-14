// Blake Turman 4/11/25
// Blake Turman 4/12/25

#pragma once

#include "ProceduralMeshComponent.h"
#include "UObject/NoExportTypes.h"
#include "Math/Matrix.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FourDHallway.generated.h"

// struct for storing 4D points
USTRUCT()
struct FourDPoints
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float x;

	UPROPERTY(EditAnywhere)
	float y;

	UPROPERTY(EditAnywhere)
	float z;

	UPROPERTY(EditAnywhere)
	float w;

	FourDPoints(const float& newX = 0.0f, const float& newY = 0.0f, 
        const float& newZ = 0.0f, const float& newW = 0.0f) :
        x(newX), y(newY), z(newZ), w(newW) {}
};

// struct for storing 3 planes to act as the axis of 4D space for rotation
USTRUCT()
struct FourDPlanes
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    float xY;

    UPROPERTY(EditAnywhere)
    float xZ;

    UPROPERTY(EditAnywhere)
    float xW;

    FourDPlanes() : xY(0.0f), xZ(0.0f), xW(0.0f) {}
};

UCLASS()
class FOURDSANDBOX_API AFourDHallway : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFourDHallway();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

    // think of these as values for hieght, width, length, etc
    UPROPERTY(EditAnywhere, Category = "Geometry")
    FourDPoints startGeometry; // starting bounds for object geometry
    UPROPERTY(EditAnywhere, Category = "Geometry")
    FourDPoints endGeometry; // ending bounds for object geometry

    // TArray is UE's dynamic array type
    UPROPERTY(VisibleAnywhere, Category = "Geometry")
    TArray<FourDPoints> vertices; // all of the 4D object's vertices

    // FMatrix is UE's matrix type
    UPROPERTY(VisibleAnywhere, Category = "Geometry")
    FMatrix transformMatrix; // matrix of values that determine transformations

    UPROPERTY(EditAnywhere, Category = "Transformation")
    FourDPoints translation; // determines position of object to calculate transformations

    UPROPERTY(EditAnywhere, Category = "Rotation")
    FourDPlanes rotation; // determines rotation of object to calculate transformations

    UPROPERTY(VisibleAnywhere, Category = "Slice Properties")
    float sliceWidth; // determines how much the object can be moved on the W axis without clipping out of the slice

    UPROPERTY(VisibleAnywhere, Category = "Mesh")
    UProceduralMeshComponent* mesh; // mesh that can be drawn to denoted vertices dynamically

    // creates matrix to use to apply transformations
    void createMatrix();

    // creates vertices for a 4D hallway
    // createMatrix() should be called prior
    void createHallway();

    // creates 3D mesh from 4D vertices
    // createMatrix and createMesh should be called prior
    void createMesh();

private:
    // helper for createHallway(), multiplies one vertex by the transformation matrix
    FourDPoints transformVertex(const FourDPoints& vertex) const;

    // helper for createMesh(), slices 8 3D vertices from the 4D vertices within slice range
    TArray<FVector> slice4DPlane();

    // helper for createMesh, constructs the mesh for the 3D slice
    void updateMesh(const TArray<FVector>& slicedVertices);
};
