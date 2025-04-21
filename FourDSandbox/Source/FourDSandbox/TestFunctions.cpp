// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFunctions.h"

DEFINE_LOG_CATEGORY(TestFunctionsLog);

TestFunctions::TestFunctions()
{
	TestCreateMatrix();
	TestTransformVertex();
	TestCreateObject();
	TestSlice4DPlane();
	TestUpdateW();
}

void TestFunctions::TestCreateMatrix() const
{
	AFourDBlock* testBlock = NewObject<AFourDBlock>();

	testBlock->createMatrix();

	FMatrix compareMatrix = FMatrix::Identity;
	compareMatrix.M[3][3] = 0;

	if (testBlock->transformMatrix == compareMatrix)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateMatrix] 0 transformations SUCCESS"));
		std::cout << "[TestCreateMatrix] 0 transformations SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateMatrix] 0 transformations INCORRECT OUTPUT"));
		std::cout << "[TestCreateMatrix] 0 transformations INCORRECT OUTPUT" << std::endl;
	}

	testBlock->translation.x = 1;
	testBlock->translation.y = -1;
	testBlock->translation.z = 2;
	testBlock->translation.w = -2;

	testBlock->createMatrix();

	compareMatrix = FMatrix::Identity;
	compareMatrix.M[3][0] = 1;
	compareMatrix.M[3][1] = -1;
	compareMatrix.M[3][2] = 2;
	compareMatrix.M[3][3] = -2;

	if (testBlock->transformMatrix == compareMatrix)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateMatrix] translation SUCCESS"));
		std::cout << "[TestCreateMatrix] translation SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateMatrix] translation INCORRECT OUTPUT"));
		std::cout << "[TestCreateMatrix] translation INCORRECT OUTPUT" << std::endl;
	}

	testBlock->Destroy();

}

void TestFunctions::TestTransformVertex() const
{
	AFourDBlock* testBlock = NewObject<AFourDBlock>();

	FourDPoints testPoint;
	FourDPoints comparePoint;

	testBlock->transformMatrix = FMatrix::Identity;
	testPoint = testBlock->transformVertex(FourDPoints());

	if (testPoint.x == comparePoint.x && testPoint.y == comparePoint.y && 
		testPoint.z == comparePoint.z && testPoint.w == comparePoint.w)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestTransformVertex] 0 transformation SUCCESS"));
		std::cout << "[TestTransformVertex] 0 transformation SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestTransformVertex] 0 transformation INCORRECT OUTPUT"));
		std::cout << "[TestTransformVertex] 0 transformation INCORRECT OUTPUT" << std::endl;
	}


	testPoint = testBlock->transformVertex(FourDPoints(1, -1, 2, -2));

	comparePoint.x = 1;
	comparePoint.y = -1;
	comparePoint.z = 2;
	comparePoint.w = -2;

	if (testPoint.x == comparePoint.x && testPoint.y == comparePoint.y &&
		testPoint.z == comparePoint.z && testPoint.w == comparePoint.w)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestTransformVertex] identity transformation SUCCESS"));
		std::cout << "[TestTransformVertex] identity transformation SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestTransformVertex] identity transformation INCORRECT OUTPUT"));
		std::cout << "[TestTransformVertex] identity transformation INCORRECT OUTPUT" << std::endl;
	}

	testBlock->transformMatrix.M[0][0] = -1;
	testBlock->transformMatrix.M[1][1] = -1;
	testBlock->transformMatrix.M[2][2] = -1;
	testBlock->transformMatrix.M[3][3] = 0;

	testPoint = testBlock->transformVertex(FourDPoints(1, -1, 2, -2));

	comparePoint.x = -1;
	comparePoint.y = 1;
	comparePoint.z = -2;
	comparePoint.w = 0;

	if (testPoint.x == comparePoint.x && testPoint.y == comparePoint.y &&
		testPoint.z == comparePoint.z && testPoint.w == comparePoint.w)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestTransformVertex] 90 deg transformation SUCCESS"));
		std::cout << "[TestTransformVertex] 90 deg transformation SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestTransformVertex] 90 deg transformation INCORRECT OUTPUT"));
		std::cout << "[TestTransformVertex] 90 deg transformation INCORRECT OUTPUT" << std::endl;
	}

	testBlock->Destroy();
}

void TestFunctions::TestCreateObject() const
{
	AFourDBlock* testBlock = NewObject<AFourDBlock>();

	testBlock->transformMatrix = FMatrix::Identity;
	testBlock->transformMatrix.M[0][0] = -1;
	testBlock->transformMatrix.M[1][1] = -1;
	testBlock->transformMatrix.M[2][2] = -1;
	testBlock->transformMatrix.M[3][3] = 0;


	testBlock->startGeometry.x = -1;
	testBlock->startGeometry.y = -1;
	testBlock->startGeometry.z = -1;
	testBlock->startGeometry.w = -1;

	testBlock->endGeometry.x = 1;
	testBlock->endGeometry.y = 1;
	testBlock->endGeometry.z = 1;
	testBlock->endGeometry.w = 1;

	testBlock->createObject();

	TArray<FourDPoints> compareVertices
	{
		FourDPoints(1, 1, 1, 0),  
		FourDPoints(-1, 1, 1, 0),    
		FourDPoints(-1, -1, 1, 0),      
		FourDPoints(1, -1, 1, 0),    

		FourDPoints(1, 1, -1, 0),    
		FourDPoints(-1, 1, -1, 0),      
		FourDPoints(-1, -1, -1, 0),        
		FourDPoints(1, -1, -1, 0),      

		FourDPoints(1, 1, 1, 0),  
		FourDPoints(-1, 1, 1, 0),      
		FourDPoints(-1, -1, 1, 0),        
		FourDPoints(1, -1, 1, 0),      

		FourDPoints(1, 1, -1, 0),      
		FourDPoints(-1, 1, -1, 0),        
		FourDPoints(-1, -1, -1, 0),          
		FourDPoints(1, -1, -1, 0)
	};

	bool sameArray = true;

	if (testBlock->vertices.Num() != compareVertices.Num())
	{
		sameArray = false;
	}
	 
	for (int i = 0; sameArray && i < compareVertices.Num(); ++i)
	{
		if (testBlock->vertices[i].x != compareVertices[i].x)
		{
			sameArray = false;
		}
		else if (testBlock->vertices[i].y != compareVertices[i].y)
		{
			sameArray = false;
		}
		else if (testBlock->vertices[i].z != compareVertices[i].z)
		{
			sameArray = false;
		}
		else if (testBlock->vertices[i].w != compareVertices[i].w)
		{
			sameArray = false;
		}
	}

	if (sameArray)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateObject] create object SUCCESS"));
		std::cout << "[TestCreateObject]  create object SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateObject]  create object INCORRECT OUTPUT"));
		std::cout << "[TestCreateObject]  create object INCORRECT OUTPUT" << std::endl;
	}

	testBlock->Destroy();
}

void TestFunctions::TestSlice4DPlane() const
{
	AFourDBlock* testBlock = NewObject<AFourDBlock>();

	testBlock->vertices = {
		FourDPoints(1, 1, 1, 0),
		FourDPoints(-1, 1, 1, 0),
		FourDPoints(-1, -1, 1, 0),
		FourDPoints(1, -1, 1, 0),

		FourDPoints(1, 1, -1, 0),
		FourDPoints(-1, 1, -1, 0),
		FourDPoints(-1, -1, -1, 0),
		FourDPoints(1, -1, -1, 0),

		FourDPoints(1, 1, 1, 0),
		FourDPoints(-1, 1, 1, 0),
		FourDPoints(-1, -1, 1, 0),
		FourDPoints(1, -1, 1, 0),

		FourDPoints(1, 1, -1, 0),
		FourDPoints(-1, 1, -1, 0),
		FourDPoints(-1, -1, -1, 0),
		FourDPoints(1, -1, -1, 0)
	};

	TArray<FVector> testSlicedVertices = testBlock->slice4DPlane();

	TArray<FVector> compareSlicedVertices = {
		FVector(1, 1, 1),
		FVector(-1, 1, 1),
		FVector(-1, -1, 1),
		FVector(1, -1, 1),

		FVector(1, 1, -1),
		FVector(-1, 1, -1),
		FVector(-1, -1, -1),
		FVector(1, -1, -1)
	};

	if (testSlicedVertices == compareSlicedVertices)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestSlice4DPlane] slice SUCCESS"));
		std::cout << "[TestSlice4DPlane] slice SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestSlice4DPlane] slice INCORRECT OUTPUT"));
		std::cout << "[TestSlice4DPlane] slice INCORRECT OUTPUT" << std::endl;
	}

	testBlock->Destroy();
}

void TestFunctions::TestUpdateW() const
{
	AFourDBlock* testBlock = NewObject<AFourDBlock>();

	testBlock->startW = 2;
	testBlock->updateW(8);

	if (testBlock->translation.w == 6)
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestUpdateW] W Updated SUCCESS"));
		std::cout << "[TestUpdateW] W Updated SUCCESS" << std::endl;
	}
	else
	{
		UE_LOG(TestFunctionsLog, Warning, TEXT("[TestUpdateW] W Updated INCORRECT OUTPUT"));
		std::cout << "[TestUpdateW] W Updated INCORRECT OUTPUT" << std::endl;
	}

	testBlock->Destroy();
}
