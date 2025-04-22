// Blake Turman 4/11/25
// Blake Turman 4/12/25

#pragma once

#include "FourDObject.h"
#include "UObject/NoExportTypes.h"
#include "Math/Matrix.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FourDBlock.generated.h"



UCLASS()
class FOURDSANDBOX_API AFourDBlock : public AFourDObject
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFourDBlock();

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

    // creates vertices for a 4D block
    // createMatrix() should be called prior
    void createObject() override;

    // creates 3D mesh from 4D vertices
    // createMatrix and createObject should be called prior
    void createMesh() override;

private:
    // helper for createMesh(), slices 8 3D vertices from the 4D vertices within slice range
    TArray<FVector> slice4DPlane() override;

    // helper for createMesh, constructs the mesh for the 3D slice
    void updateMesh(const TArray<FVector>& slicedVertices) override;

    friend class TestFunctions;
};
