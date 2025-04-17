// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FourDSandbox/FourDBlock.h"
#include "FourDSandbox/FourDObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFourDBlock() {}

// Begin Cross Module References
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDBlock();
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDBlock_NoRegister();
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDObject();
FOURDSANDBOX_API UScriptStruct* Z_Construct_UScriptStruct_FourDPoints();
UPackage* Z_Construct_UPackage__Script_FourDSandbox();
// End Cross Module References

// Begin Class AFourDBlock
void AFourDBlock::StaticRegisterNativesAFourDBlock()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFourDBlock);
UClass* Z_Construct_UClass_AFourDBlock_NoRegister()
{
	return AFourDBlock::StaticClass();
}
struct Z_Construct_UClass_AFourDBlock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FourDBlock.h" },
		{ "ModuleRelativePath", "FourDBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_startGeometry_MetaData[] = {
		{ "Category", "Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// think of these as values for hieght, width, length, etc\n" },
#endif
		{ "ModuleRelativePath", "FourDBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "think of these as values for hieght, width, length, etc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_endGeometry_MetaData[] = {
		{ "Category", "Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// starting bounds for object geometry\n" },
#endif
		{ "ModuleRelativePath", "FourDBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "starting bounds for object geometry" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_startGeometry;
	static const UECodeGen_Private::FStructPropertyParams NewProp_endGeometry;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFourDBlock>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDBlock_Statics::NewProp_startGeometry = { "startGeometry", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDBlock, startGeometry), Z_Construct_UScriptStruct_FourDPoints, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_startGeometry_MetaData), NewProp_startGeometry_MetaData) }; // 2250753697
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFourDBlock_Statics::NewProp_endGeometry = { "endGeometry", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDBlock, endGeometry), Z_Construct_UScriptStruct_FourDPoints, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_endGeometry_MetaData), NewProp_endGeometry_MetaData) }; // 2250753697
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFourDBlock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDBlock_Statics::NewProp_startGeometry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDBlock_Statics::NewProp_endGeometry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDBlock_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFourDBlock_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AFourDObject,
	(UObject* (*)())Z_Construct_UPackage__Script_FourDSandbox,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDBlock_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFourDBlock_Statics::ClassParams = {
	&AFourDBlock::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFourDBlock_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFourDBlock_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDBlock_Statics::Class_MetaDataParams), Z_Construct_UClass_AFourDBlock_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFourDBlock()
{
	if (!Z_Registration_Info_UClass_AFourDBlock.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFourDBlock.OuterSingleton, Z_Construct_UClass_AFourDBlock_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFourDBlock.OuterSingleton;
}
template<> FOURDSANDBOX_API UClass* StaticClass<AFourDBlock>()
{
	return AFourDBlock::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFourDBlock);
AFourDBlock::~AFourDBlock() {}
// End Class AFourDBlock

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDBlock_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFourDBlock, AFourDBlock::StaticClass, TEXT("AFourDBlock"), &Z_Registration_Info_UClass_AFourDBlock, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFourDBlock), 1899293207U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDBlock_h_2274732357(TEXT("/Script/FourDSandbox"),
	Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDBlock_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_4D_Playground_FourDSandbox_Source_FourDSandbox_FourDBlock_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
