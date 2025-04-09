// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FourDSandbox/FourDCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFourDCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDCharacter();
FOURDSANDBOX_API UClass* Z_Construct_UClass_AFourDCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_FourDSandbox();
// End Cross Module References

// Begin Class AFourDCharacter
void AFourDCharacter::StaticRegisterNativesAFourDCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFourDCharacter);
UClass* Z_Construct_UClass_AFourDCharacter_NoRegister()
{
	return AFourDCharacter::StaticClass();
}
struct Z_Construct_UClass_AFourDCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FourDCharacter.h" },
		{ "ModuleRelativePath", "FourDCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_dimensionW_MetaData[] = {
		{ "Category", "4D Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY allows variable dimensionW to be editable in UE\n" },
#endif
		{ "ModuleRelativePath", "FourDCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY allows variable dimensionW to be editable in UE" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_playerCamera_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// add camera\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FourDCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "add camera" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_dimensionW;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_playerCamera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFourDCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFourDCharacter_Statics::NewProp_dimensionW = { "dimensionW", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDCharacter, dimensionW), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_dimensionW_MetaData), NewProp_dimensionW_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFourDCharacter_Statics::NewProp_playerCamera = { "playerCamera", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFourDCharacter, playerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_playerCamera_MetaData), NewProp_playerCamera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFourDCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDCharacter_Statics::NewProp_dimensionW,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFourDCharacter_Statics::NewProp_playerCamera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFourDCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_FourDSandbox,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFourDCharacter_Statics::ClassParams = {
	&AFourDCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFourDCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFourDCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFourDCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AFourDCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFourDCharacter()
{
	if (!Z_Registration_Info_UClass_AFourDCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFourDCharacter.OuterSingleton, Z_Construct_UClass_AFourDCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFourDCharacter.OuterSingleton;
}
template<> FOURDSANDBOX_API UClass* StaticClass<AFourDCharacter>()
{
	return AFourDCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFourDCharacter);
AFourDCharacter::~AFourDCharacter() {}
// End Class AFourDCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_FourDSandbox_Source_FourDSandbox_FourDCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFourDCharacter, AFourDCharacter::StaticClass, TEXT("AFourDCharacter"), &Z_Registration_Info_UClass_AFourDCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFourDCharacter), 1346383453U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_FourDSandbox_Source_FourDSandbox_FourDCharacter_h_410555670(TEXT("/Script/FourDSandbox"),
	Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_FourDSandbox_Source_FourDSandbox_FourDCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_blakt_Documents_Unreal_Projects_FourDSandbox_Source_FourDSandbox_FourDCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
