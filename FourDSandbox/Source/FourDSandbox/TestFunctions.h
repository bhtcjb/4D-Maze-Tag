// Blake

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
	TestFunctions();
	void TestCreateMatrix() const;
	void TestTransformVertex() const;
	void TestCreateObject() const;
	void TestSlice4DPlane() const;
	void TestUpdateW() const;
};
