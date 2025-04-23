// Blake Turman

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
    // Author: Blake
    // Sets default values for this actor's properties
    AFourDBlock();

    // Author: Epic Games
    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Author: Epic Games
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Author: Epic Games
    void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

private:
    // think of these as values for hieght, width, length, etc
    UPROPERTY(EditAnywhere, Category = "Geometry")
    FourDPoints startGeometry; // starting bounds for object geometry
    UPROPERTY(EditAnywhere, Category = "Geometry")
    FourDPoints endGeometry; // ending bounds for object geometry

    // Author: Blake
    // creates vertices for a 4D block
    // createMatrix() should be called prior
    void createObject() override;

    // Author: Blake
    // creates 3D mesh from 4D vertices
    // createMatrix and createObject should be called prior
    void createMesh() override;

    // Author: Blake
    // helper for createMesh(), slices 8 3D vertices from the 4D vertices within slice range
    TArray<FVector> slice4DPlane() override;

    // Author: Blake
    // helper for createMesh, constructs the mesh for the 3D slice
    void updateMesh(const TArray<FVector>& slicedVertices) override;

    friend class TestFunctions;
};
