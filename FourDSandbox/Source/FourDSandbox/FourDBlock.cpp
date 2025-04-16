


#include "FourDBlock.h"

// Sets default values
AFourDBlock::AFourDBlock()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // mesh that can be drawn to denoted vertices dynamically
    mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("mesh"));
    RootComponent = mesh; // makes it so other componants interact with the mesh and not some other part of the object

    // determines geometry of the object, use to change length width height etc, 
    startGeometry = FourDPoints(-100.0f, -100.0f, -100.0f, -100.0f); // startGeometry should pretty much always be negative values
    endGeometry = FourDPoints(100.0f, 100.0f, 100.0f, 100.0f); // endGeometry should pretty much always be positive values

    // determines how much the object can be moved on the W axis without clipping out of the slice
    // right now i just set it to the length of the object along the w axis, but will probably have to be changed to smaller
    sliceWidth = endGeometry.w - startGeometry.w;

    // main 4D creation algorithm, will be called in Tick function for dynamic changes
    createMatrix(); // do matrix math for translating and rotating a 4D object
    createBlock(); // creates vertices for 4D cube based on matrix and geometry
    createMesh(); // draws 3D mesh for the 4D slice

    // load and set basic wall from starter content, this can be set to whatever
    UMaterialInterface* material = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/StarterContent/Materials/M_Basic_Wall"));
    mesh->SetMaterial(0, material);

}

// Called when the game starts or when spawned
void AFourDBlock::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AFourDBlock::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // call every tick for dynamic changes
    sliceWidth = endGeometry.w - startGeometry.w;
    createMatrix();
    createBlock();
    createMesh();
}

#if WITH_EDITOR
void AFourDBlock::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    // allows dynamic changes if trying to control from editor
    sliceWidth = endGeometry.w - startGeometry.w;
    createMatrix();
    createBlock();
    createMesh();
}
#endif

void AFourDBlock::createMatrix()
{
    // reset matrix
    transformMatrix = FMatrix::Identity;

    // rotation algorithm explained here
    // https://math.stackexchange.com/questions/1402362/can-rotations-in-4d-be-given-an-explicit-matrix-form
    // do rotation along X-Y plane
    transformMatrix.M[0][0] = FMath::Cos(rotation.xY);
    transformMatrix.M[0][1] = -FMath::Sin(rotation.xY);
    transformMatrix.M[1][0] = FMath::Sin(rotation.xY);
    transformMatrix.M[1][1] = FMath::Cos(rotation.xY);

    // do rotation along X-Z plane
    transformMatrix.M[0][0] *= FMath::Cos(rotation.xZ);
    transformMatrix.M[0][2] = -FMath::Sin(rotation.xZ);
    transformMatrix.M[2][0] = FMath::Sin(rotation.xZ);
    transformMatrix.M[2][2] *= FMath::Cos(rotation.xZ);

    // do rotation along X-W plane
    transformMatrix.M[0][0] *= FMath::Cos(rotation.xW);
    transformMatrix.M[0][3] = -FMath::Sin(rotation.xW);
    transformMatrix.M[3][0] = FMath::Sin(rotation.xW);
    transformMatrix.M[3][3] *= FMath::Cos(rotation.xW);

    // do translation
    transformMatrix.M[3][0] = translation.x;
    transformMatrix.M[3][1] = translation.y;
    transformMatrix.M[3][2] = translation.z;
    transformMatrix.M[3][3] = translation.w;

}

void AFourDBlock::createBlock()
{
    // a 4d block's gonna have 16 vertices
    TArray<FourDPoints> verticesBefore = {
        // order does matter here for mapping the mesh
        // the mesh is indexed according to order of the vertices, which will be set in the updateMesh() function
        FourDPoints(startGeometry.x, startGeometry.y, startGeometry.z, startGeometry.w),  // 0
        FourDPoints(endGeometry.x, startGeometry.y, startGeometry.z, startGeometry.w),    // 1
        FourDPoints(endGeometry.x, endGeometry.y, startGeometry.z, startGeometry.w),      // 2
        FourDPoints(startGeometry.x, endGeometry.y, startGeometry.z, startGeometry.w),    // 3

        FourDPoints(startGeometry.x, startGeometry.y, endGeometry.z, startGeometry.w),    // 4
        FourDPoints(endGeometry.x, startGeometry.y, endGeometry.z, startGeometry.w),      // 5
        FourDPoints(endGeometry.x, endGeometry.y, endGeometry.z, startGeometry.w),        // 6
        FourDPoints(startGeometry.x, endGeometry.y, endGeometry.z, startGeometry.w),      // 7

        FourDPoints(startGeometry.x, startGeometry.y, startGeometry.z, endGeometry.w),    // 8
        FourDPoints(endGeometry.x, startGeometry.y, startGeometry.z, endGeometry.w),      // 9
        FourDPoints(endGeometry.x, endGeometry.y, startGeometry.z, endGeometry.w),        // 10
        FourDPoints(startGeometry.x, endGeometry.y, startGeometry.z, endGeometry.w),      // 11

        FourDPoints(startGeometry.x, startGeometry.y, endGeometry.z, endGeometry.w),      // 12
        FourDPoints(endGeometry.x, startGeometry.y, endGeometry.z, endGeometry.w),        // 13
        FourDPoints(endGeometry.x, endGeometry.y, endGeometry.z, endGeometry.w),          // 14
        FourDPoints(startGeometry.x, endGeometry.y, endGeometry.z, endGeometry.w),        // 15
    };

    // clear previous contents
    vertices.Empty();

    // fill with transformations
    for (int i = 0; i < verticesBefore.Num(); ++i)
    {
        vertices.Add(transformVertex(verticesBefore[i]));
    }

};


void AFourDBlock::createMesh()
{
    // make slice and update mesh with slice
    updateMesh(slice4DPlane());
}


FourDPoints AFourDBlock::transformVertex(const FourDPoints& vertex) const
{
    FourDPoints transformedVertex;

    // multiply each axis position of the vertex by the transfom matrix
    transformedVertex.x = vertex.x * transformMatrix.M[0][0] +
        vertex.y * transformMatrix.M[1][0] +
        vertex.z * transformMatrix.M[2][0] +
        vertex.w * transformMatrix.M[3][0];

    transformedVertex.y = vertex.x * transformMatrix.M[0][1] +
        vertex.y * transformMatrix.M[1][1] +
        vertex.z * transformMatrix.M[2][1] +
        vertex.w * transformMatrix.M[3][1];

    transformedVertex.z = vertex.x * transformMatrix.M[0][2] +
        vertex.y * transformMatrix.M[1][2] +
        vertex.z * transformMatrix.M[2][2] +
        vertex.w * transformMatrix.M[3][2];

    transformedVertex.w = vertex.x * transformMatrix.M[0][3] +
        vertex.y * transformMatrix.M[1][3] +
        vertex.z * transformMatrix.M[2][3] +
        vertex.w * transformMatrix.M[3][3];

    return transformedVertex;
}

TArray<FVector> AFourDBlock::slice4DPlane()
{
    TArray<FVector> slicedVertices;

    // iterate through vertices, up to 8 for a cube
    for (int i = 0; slicedVertices.Num() < 8 && i < vertices.Num(); ++i)
    {
        // only insert vertex if it is within the 3D slice
        if (FMath::Abs(vertices[i].w - translation.w) < sliceWidth)
        {
            slicedVertices.Add(FVector(vertices[i].x, vertices[i].y, vertices[i].z));
        }
    }

    return slicedVertices;
}

void AFourDBlock::updateMesh(const TArray<FVector>& slicedVertices)
{
    // two triangles per face, which i set in a counter-clockwise rotation so that the faces will face outward
    TArray<int32> indices = {
        0, 1, 2, 0, 2, 3,
        4, 6, 5, 4, 7, 6,
        3, 2, 6, 3, 6, 7,
        0, 5, 1, 0, 4, 5,
        0, 3, 7, 0, 7, 4,
        1, 6, 2, 1, 5, 6
    };
    TArray<FVector> normals;
    TArray<FVector2D> UVs;
    TArray<FLinearColor> colors;
    TArray<FProcMeshTangent> tangents;

    // construct arrays for the following properties
    for (int i = 0; i < slicedVertices.Num(); ++i)
    {
        normals.Add(FVector(0, 0, 1));
        UVs.Add(FVector2D(0, 0));
        colors.Add(FColor::White);
        tangents.Add(FProcMeshTangent(1, 0, 0));
    }

    // reset mesh
    mesh->ClearAllMeshSections();

    // set mesh with following properties
    mesh->CreateMeshSection_LinearColor(
        0,                // index for defining multiple sections, we don't need this
        slicedVertices, // vertex array
        indices,        // array of numbers defines how vertices are connected
        normals,      // normals for lighting
        UVs,          // texture mapping    
        colors,     // vertex colors, for more complex shading, we don't need this
        tangents,    // for texture orientation       
        true              // collision set true
    );



}

