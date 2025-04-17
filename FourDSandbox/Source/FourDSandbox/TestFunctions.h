// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	void TestSlice4DPlane() const;
};
