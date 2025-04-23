// Blake Turman 

#pragma once

#include "FourDCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "ProceduralMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FourDObject.generated.h"


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
        x(newX), y(newY), z(newZ), w(newW) {
    }
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

// abstract class for making 4D objects
UCLASS(Abstract)
class FOURDSANDBOX_API AFourDObject : public AActor
{
	GENERATED_BODY()
	
public:	
    // Author: Blake
	// Sets default values for this actor's properties
	AFourDObject();

protected:
    // Author: Epic Games
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
    // Author: Epic Games
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // These variables must be public in order to control in editor
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

    UPROPERTY(VisibleAnywhere, Category = "Slice Properties")
    float startW; // sets object's starting position at begin play to calculate changes in W

    UPROPERTY(VisibleAnywhere, Category = "Mesh")
    UProceduralMeshComponent* mesh; // mesh that can be drawn to denoted vertices dynamically

protected:
    // Author: Blake
    // creates matrix to use to apply transformations
    void createMatrix();

    // Author: Blake
    // creates vertices for a 4D object
    // createMatrix() should be called prior
    virtual void createObject() PURE_VIRTUAL(AFourDObject::createObject, );

    // Author: Blake
    // creates 3D mesh from 4D vertices
    // createMatrix and createObject should be called prior
    virtual void createMesh() PURE_VIRTUAL(AFourDObject::createMesh, );

    // Author: Blake
    // helper for createObject(), multiplies one vertex by the transformation matrix
    FourDPoints transformVertex(const FourDPoints& vertex) const;

    // Author: Blake
    // helper for createMesh(), slices 8 3D vertices from the 4D vertices within slice range
    virtual TArray<FVector> slice4DPlane() PURE_VIRTUAL(AFourDObject::slice4DPlane, return TArray<FVector>({ FVector() }););

    // Author: Blake
    // helper for createMesh, constructs the mesh for the 3D slice
    virtual void updateMesh(const TArray<FVector>& slicedVertices) PURE_VIRTUAL(AFourDObject::updateMesh, );

private:
    // Author: Blake
    // helper for BeginPlay() event setup to calculate new W during play
    UFUNCTION()
    void updateW(float newW);

    friend class TestFunctions;
};
