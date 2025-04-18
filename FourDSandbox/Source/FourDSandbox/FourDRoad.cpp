// Fill out your copyright notice in the Description page of Project Settings.


#include "FourDRoad.h"
#include "Components/InstancedStaticMeshComponent.h" // Add this include at the top of the file


// Sets default values
AFourDRoad::AFourDRoad()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create procedural mesh component
	RoadMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("RoadMesh"));
	SetRootComponent(RoadMesh);
	RoadMesh->bUseAsyncCooking = true;

	// Set up the road structure
	SetupRoad();

}

// Called when the game starts or when spawned
void AFourDRoad::BeginPlay()
{
	Super::BeginPlay();
	UpdateCrossSection();
}

// Called every frame
void AFourDRoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (autoAnimateDimensionW)
	{
		dimensionW += dimensionWAutoSpeed * DeltaTime * AnimationDirection;

		if (dimensionW >= 1.0f) {
			dimensionW = 1.0f;
			AnimationDirection = -1.0f;
		}
		else if (dimensionW <= 0.0f) {
			dimensionW = 0.0f;
			AnimationDirection = 1.0f;
		}
		UpdateCrossSection();
	}

}

void AFourDRoad::SetupRoad()
{
	float halfSize = roadWidth * 0.5f;

	RoadVertices.Empty();

	// Define vertices
	for (int w = 0; w <= 1; w++)
	{
		for (int z = 0; z <= 1; z++)
		{
			for (int y = 0; y <= 1; y++)
			{
				for (int x = 0; x <= 1; x++)
				{
					RoadVertices.Add(FVector4(
						(x * 2 - 1) * halfSize,
						(y * 2 - 1) * halfSize,
						(z * 2 - 1) * halfSize,
						(w * 2 - 1) * halfSize
					));
				}
			}
		}
	}

	// Define edges
	for (int i = 0; i < RoadVertices.Num(); i++)
	{
		for (int j = i + 1; j < RoadVertices.Num(); j++)
		{
			// Count how many coordinates differ
			int diffCount = 0;
			if (FMath::Abs(RoadVertices[i].X - RoadVertices[j].X) > KINDA_SMALL_NUMBER) diffCount++;
			if (FMath::Abs(RoadVertices[i].Y - RoadVertices[j].Y) > KINDA_SMALL_NUMBER) diffCount++;
			if (FMath::Abs(RoadVertices[i].Z - RoadVertices[j].Z) > KINDA_SMALL_NUMBER) diffCount++;
			if (FMath::Abs(RoadVertices[i].W - RoadVertices[j].W) > KINDA_SMALL_NUMBER) diffCount++;

			// If exactly one coordinate differs, these vertices form an edge
			if (diffCount == 1)
			{
				RoadEdges.Add(TPair<int32, int32>(i, j));
			}
		}
	}
}

void AFourDRoad::UpdateCrossSection()
{
	// Clear previous mesh
	RoadMesh->ClearAllMeshSections();

	// Generate new mesh at the current dimensionW
	GenerateCrossSection(dimensionW);

	// Update attached geometry
	for (UStaticMeshComponent* GeomComp : AttachedGeometryComponents)
	{
		if (GeomComp)
		{
			GeomComp->SetRelativeTransform(FTransform(FRotator::ZeroRotator, FVector::ZeroVector,
				FVector(1.0f + dimensionW * 0.5f, 1.0f + dimensionW * 0.5f, 1.0f + dimensionW * 0.5f)));
		}
	}
}

void AFourDRoad::GenerateCrossSection(float dimW)
{
	float haftSize = roadWidth * 0.5f;
	float actualDimW = FMath::Lerp(-haftSize, haftSize, dimW);

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UV0;
	TArray<FColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;

	TArray<FVector> IntersectionPoints;

	for (const TPair<int32, int32>& Edge : RoadEdges)
	{
		FVector4 V1 = RoadVertices[Edge.Key];
		FVector4 V2 = RoadVertices[Edge.Value];

		FVector Intersection;
		if (EdgeIntersectsWPlane(V1, V2, actualDimW, Intersection))
		{
			IntersectionPoints.Add(Intersection);
		}
	}


	if (IntersectionPoints.Num() >= 3)
	{

		for (const FVector& Point : IntersectionPoints)
		{
			Vertices.Add(Point);
			Normals.Add(FVector(1, 0, 0));
			UV0.Add(FVector2D(0, 0));
			VertexColors.Add(FColor::White);
			Tangents.Add(FProcMeshTangent(0, 1, 0));
		}

		FVector Center = FVector::ZeroVector;
		for (const FVector& Vertex : Vertices)
		{
			Center += Vertex;
		}
		Center /= Vertices.Num();

		int32 CenterIndex = Vertices.Num();
		Vertices.Add(Center);
		Normals.Add(FVector(1, 0, 0));
		UV0.Add(FVector2d(0.5f, 0.5f));
		VertexColors.Add(FColor::White);
		Tangents.Add(FProcMeshTangent(0, 1, 0));

		for (int i = 0; i < IntersectionPoints.Num(); i++)
		{
			int j = (i + 1) % IntersectionPoints.Num();

			Triangles.Add(i);
			Triangles.Add(j);
			Triangles.Add(CenterIndex);
		}

		RoadMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0,
			TArray<FLinearColor>(), Tangents, true);

		if (RoadMaterial)
		{
			RoadMesh->SetMaterial(0, RoadMaterial);
		}
	}
}

bool AFourDRoad::EdgeIntersectsWPlane(const FVector4& V1, const FVector4& V2, float dimW, FVector& Intersection)
{
	if ((V1.W <= dimW && V2.W >= dimW) || (V1.W >= dimW && V2.W <= dimW))
	{
		// If the edge is parallel to the w-plane, no unique intersection
		if (FMath::Abs(V2.W - V1.W) < KINDA_SMALL_NUMBER)
		{
			return false;
		}

		// Calculate the interpolation factor
		float t = (dimW - V1.W) / (V2.W - V1.W);

		// Calculate the intersection point in 3D space
		Intersection.X = FMath::Lerp(V1.X, V2.X, t);
		Intersection.Y = FMath::Lerp(V1.Y, V2.Y, t);
		Intersection.Z = FMath::Lerp(V1.Z, V2.Z, t);

		return true;
	}

	return false;
}

FVector AFourDRoad::ProjectTo3D(const FVector4& Point4D, float dimW)
{
	// Simple projection to 3D space
	return FVector(Point4D.X, Point4D.Y, Point4D.Z);
}

void AFourDRoad::AttachCustomGeometry(UStaticMesh* CustomMesh, UMaterialInterface* CustomMaterial)
{
	if (!CustomMesh) { return; }

	UStaticMeshComponent* NewGeometryComp = NewObject<UStaticMeshComponent>(this);
	NewGeometryComp->SetStaticMesh(CustomMesh);

	if (CustomMaterial)
	{
		NewGeometryComp->SetMaterial(0, CustomMaterial);
	}

	NewGeometryComp->SetupAttachment(GetRootComponent());
	NewGeometryComp->RegisterComponent();

	AttachedGeometryComponents.Add(NewGeometryComp);

	NewGeometryComp->SetRelativeTransform(FTransform(FRotator::ZeroRotator, FVector::ZeroVector,
		FVector(1.0f + dimensionW * 0.5, 1.0f + dimensionW * 0.5f, 1.0f + dimensionW * 0.5f)));
}


