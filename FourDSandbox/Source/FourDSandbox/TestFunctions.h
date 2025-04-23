// Blake Turman

#pragma once

#include <iostream>
#include "CoreMinimal.h"
#include "FourDBlock.h"


DECLARE_LOG_CATEGORY_EXTERN(TestFunctionsLog, Log, All);
/**
 * 
 */
class FOURDSANDBOX_API TestFunctions
{
public:
	// Author: Blake
	// constructor calls all test functions
	TestFunctions();

	// Author: Blake
	// tests blank and translated matrix
	void TestCreateMatrix() const;

	// Author: Blake
	// tests transform with blank, identity, and 90 degree rotation on 3 planes
	void TestTransformVertex() const;

	// Author: Blake
	// tests create 4d vertices for block of size -1 to 1 and rotated 90 degrees on 3 planes
	void TestCreateObject() const;

	// Author: Blake
	// tests create 3d vertices for block of size -1 to 1 and rotated 90 degrees on 3 planes
	void TestSlice4DPlane() const;

	// Author: Blake
	// tests change in W
	void TestUpdateW() const;
};
