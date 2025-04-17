// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFunctions.h"

DEFINE_LOG_CATEGORY(TestFunctionsLog);

TestFunctions::TestFunctions()
{
	TestCreateMatrix();
	TestTransformVertex();
	TestSlice4DPlane();
}

void TestFunctions::TestCreateMatrix() const
{
	UE_LOG(TestFunctionsLog, Warning, TEXT("[TestCreateMatrix] incorrect output"))
}

void TestFunctions::TestTransformVertex() const
{
}

void TestFunctions::TestSlice4DPlane() const
{
}
