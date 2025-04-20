// Fill out your copyright notice in the Description page of Project Settings.


#include "FourDObject.h"



// Sets default values
AFourDObject::AFourDObject()
{
    // mesh that can be drawn to denoted vertices dynamically
    mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("mesh"));
    RootComponent = mesh; // makes it so other componants interact with the mesh and not some other part of the object

    sliceWidth = 0; // this should be set to a value in derived class

    startW = 0; // will be set at BeginPlay

}

// Called when the game starts or when spawned
void AFourDObject::BeginPlay()
{
    Super::BeginPlay();

    // set up to change W when event is broadcast from character
    ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0); // find character in scene
    AFourDCharacter* fourDPlayer = Cast<AFourDCharacter>(player); // attempt to cast to FourDCharacter
    if (fourDPlayer != nullptr) 
    {
        // set to change dynamically
        fourDPlayer->wChangeEvent.AddDynamic(this, &AFourDObject::updateW);
        
    }

    startW = translation.w;

}

void AFourDObject::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

  
}

void AFourDObject::createMatrix()
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

FourDPoints AFourDObject::transformVertex(const FourDPoints& vertex) const
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

void AFourDObject::updateW(float newW)
{

    translation.w = newW - startW;
    
}



