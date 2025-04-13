// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FourDSandbox/FourDHallway.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFourDHallway() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMatrix();
ENGINE_API UClass* Z_Construct_UClass_AActor();
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDHallway();
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDHallway_NoRegister();
FOURDSANDBOX_API UScriptStruct* Z_Construct_UScriptStruct_FourDPlanes();
FOURDSANDBOX_API UScriptStruct* Z_Construct_UScriptStruct_FourDPoints();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_FourDSandbox();
// End Cross Module References

// Begin ScriptStruct FourDPoints
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ourDPoints;
class UScriptStruct* FourDPoints::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ourDPoints.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ourDPoints.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FourDPoints, (UObject*)Z_Construct_UPackage__Script_FourDSandbox(), TEXT("ourDPoints"));
	}
	return Z_Registration_Info_UScriptStruct_ourDPoints.OuterSingleton;
}
template<> FOURDSANDBOX_API UScriptStruct* StaticStruct<FourDPoints>()
{
	return FourDPoints::StaticStruct();
}
struct Z_Construct_UScriptStruct_FourDPoints_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// struct for storing 4D points\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "struct for storing 4D points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_x_MetaData[] = {
		{ "Category", "ourDPoints" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_y_MetaData[] = {
		{ "Category", "ourDPoints" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_z_MetaData[] = {
		{ "Category", "ourDPoints" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_w_MetaData[] = {
		{ "Category", "ourDPoints" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_x;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_y;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_z;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_w;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FourDPoints>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPoints, x), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_x_MetaData), NewProp_x_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_y = { "y", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPoints, y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_y_MetaData), NewProp_y_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_z = { "z", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPoints, z), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_z_MetaData), NewProp_z_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_w = { "w", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPoints, w), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_w_MetaData), NewProp_w_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FourDPoints_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_x,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_z,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPoints_Statics::NewProp_w,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FourDPoints_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FourDPoints_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FourDSandbox,
	nullptr,
	&NewStructOps,
	"ourDPoints",
	Z_Construct_UScriptStruct_FourDPoints_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FourDPoints_Statics::PropPointers),
	sizeof(FourDPoints),
	alignof(FourDPoints),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FourDPoints_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FourDPoints_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FourDPoints()
{
	if (!Z_Registration_Info_UScriptStruct_ourDPoints.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ourDPoints.InnerSingleton, Z_Construct_UScriptStruct_FourDPoints_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ourDPoints.InnerSingleton;
}
// End ScriptStruct FourDPoints

// Begin ScriptStruct FourDPlanes
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ourDPlanes;
class UScriptStruct* FourDPlanes::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ourDPlanes.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ourDPlanes.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FourDPlanes, (UObject*)Z_Construct_UPackage__Script_FourDSandbox(), TEXT("ourDPlanes"));
	}
	return Z_Registration_Info_UScriptStruct_ourDPlanes.OuterSingleton;
}
template<> FOURDSANDBOX_API UScriptStruct* StaticStruct<FourDPlanes>()
{
	return FourDPlanes::StaticStruct();
}
struct Z_Construct_UScriptStruct_FourDPlanes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// struct for storing 3 planes to act as the axis of 4D space for rotation\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "struct for storing 3 planes to act as the axis of 4D space for rotation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_xY_MetaData[] = {
		{ "Category", "ourDPlanes" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_xZ_MetaData[] = {
		{ "Category", "ourDPlanes" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_xW_MetaData[] = {
		{ "Category", "ourDPlanes" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_xY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_xZ;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_xW;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FourDPlanes>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPlanes_Statics::NewProp_xY = { "xY", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPlanes, xY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_xY_MetaData), NewProp_xY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPlanes_Statics::NewProp_xZ = { "xZ", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPlanes, xZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_xZ_MetaData), NewProp_xZ_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FourDPlanes_Statics::NewProp_xW = { "xW", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FourDPlanes, xW), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_xW_MetaData), NewProp_xW_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FourDPlanes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPlanes_Statics::NewProp_xY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPlanes_Statics::NewProp_xZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FourDPlanes_Statics::NewProp_xW,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FourDPlanes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FourDPlanes_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FourDSandbox,
	nullptr,
	&NewStructOps,
	"ourDPlanes",
	Z_Construct_UScriptStruct_FourDPlanes_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FourDPlanes_Statics::PropPointers),
	sizeof(FourDPlanes),
	alignof(FourDPlanes),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FourDPlanes_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FourDPlanes_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FourDPlanes()
{
	if (!Z_Registration_Info_UScriptStruct_ourDPlanes.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ourDPlanes.InnerSingleton, Z_Construct_UScriptStruct_FourDPlanes_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ourDPlanes.InnerSingleton;
}
// End ScriptStruct FourDPlanes

// Begin Class AFourDHallway
void AFourDHallway::StaticRegisterNativesAFourDHallway()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFourDHallway);
UClass* Z_Construct_UClass_AFourDHallway_NoRegister()
{
	return AFourDHallway::StaticClass();
}
struct Z_Construct_UClass_AFourDHallway_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FourDHallway.h" },
		{ "ModuleRelativePath", "FourDHallway.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_startGeometry_MetaData[] = {
		{ "Category", "Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// think of these as values for hieght, width, length, etc\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "think of these as values for hieght, width, length, etc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_endGeometry_MetaData[] = {
		{ "Category", "Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// starting bounds for object geometry\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "starting bounds for object geometry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_vertices_MetaData[] = {
		{ "Category", "Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// TArray is UE's dynamic array type\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "TArray is UE's dynamic array type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_transformMatrix_MetaData[] = {
		{ "Category", "Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// FMatrix is UE's matrix type\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FMatrix is UE's matrix type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_translation_MetaData[] = {
		{ "Category", "Transformation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// matrix of values that determine transformations\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "matrix of values that determine transformations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rotation_MetaData[] = {
		{ "Category", "Rotation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// determines position of object to calculate transformations\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "determines position of object to calculate transformations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_sliceWidth_MetaData[] = {
		{ "Category", "Slice Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// determines rotation of object to calculate transformations\n" },
#endif
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "determines rotation of object to calculate transformations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mesh_MetaData[] = {
		{ "Category", "Mesh" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// determines how much the object can be moved on the W axis without clipping out of the slice\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FourDHallway.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "determines how much the object can be moved on the W axis without clipping out of the slice" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_startGeometry;
	static const UECodeGen_Private::FStructPropertyParams NewProp_endGeometry;
	static const UECodeGen_Private::FStructPropertyParams NewProp_vertices_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_vertices;
	static const UECodeGen_Private::FStructPropertyParams NewProp_transformMatrix;
	static const UECodeGen_Private::FStructPropertyParams NewProp_translation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_sliceWidth;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFourDHallway>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_startGeometry = { "startGeometry", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, startGeometry), Z_Construct_UScriptStruct_FourDPoints, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_startGeometry_MetaData), NewProp_startGeometry_MetaData) }; // 753466097
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_endGeometry = { "endGeometry", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, endGeometry), Z_Construct_UScriptStruct_FourDPoints, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_endGeometry_MetaData), NewProp_endGeometry_MetaData) }; // 753466097
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_vertices_Inner = { "vertices", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FourDPoints, METADATA_PARAMS(0, nullptr) }; // 753466097
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_vertices = { "vertices", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_vertices_MetaData), NewProp_vertices_MetaData) }; // 753466097
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_transformMatrix = { "transformMatrix", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, transformMatrix), Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_transformMatrix_MetaData), NewProp_transformMatrix_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_translation = { "translation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, translation), Z_Construct_UScriptStruct_FourDPoints, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_translation_MetaData), NewProp_translation_MetaData) }; // 753466097
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, rotation), Z_Construct_UScriptStruct_FourDPlanes, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rotation_MetaData), NewProp_rotation_MetaData) }; // 4189266400
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_sliceWidth = { "sliceWidth", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, sliceWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_sliceWidth_MetaData), NewProp_sliceWidth_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFourDHallway_Statics::NewProp_mesh = { "mesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDHallway, mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mesh_MetaData), NewProp_mesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFourDHallway_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_startGeometry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_endGeometry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_vertices_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_vertices,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_transformMatrix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_translation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_sliceWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDHallway_Statics::NewProp_mesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDHallway_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFourDHallway_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_FourDSandbox,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDHallway_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFourDHallway_Statics::ClassParams = {
	&AFourDHallway::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFourDHallway_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFourDHallway_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDHallway_Statics::Class_MetaDataParams), Z_Construct_UClass_AFourDHallway_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFourDHallway()
{
	if (!Z_Registration_Info_UClass_AFourDHallway.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFourDHallway.OuterSingleton, Z_Construct_UClass_AFourDHallway_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFourDHallway.OuterSingleton;
}
template<> FOURDSANDBOX_API UClass* StaticClass<AFourDHallway>()
{
	return AFourDHallway::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFourDHallway);
AFourDHallway::~AFourDHallway() {}
// End Class AFourDHallway

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDHallway_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FourDPoints::StaticStruct, Z_Construct_UScriptStruct_FourDPoints_Statics::NewStructOps, TEXT("ourDPoints"), &Z_Registration_Info_UScriptStruct_ourDPoints, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FourDPoints), 753466097U) },
		{ FourDPlanes::StaticStruct, Z_Construct_UScriptStruct_FourDPlanes_Statics::NewStructOps, TEXT("ourDPlanes"), &Z_Registration_Info_UScriptStruct_ourDPlanes, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FourDPlanes), 4189266400U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFourDHallway, AFourDHallway::StaticClass, TEXT("AFourDHallway"), &Z_Registration_Info_UClass_AFourDHallway, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFourDHallway), 2811730850U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDHallway_h_2179492777(TEXT("/Script/FourDSandbox"),
	Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDHallway_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDHallway_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDHallway_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDHallway_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
