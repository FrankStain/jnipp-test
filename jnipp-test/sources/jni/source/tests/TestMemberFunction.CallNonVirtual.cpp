// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


//TEST( TestMemberFunction, CheckFunctionIds )
//{
//	Jni::Class base_class{ "com/pfs/jnipptest/TestFunctionContainer" };
//	Jni::Class derived_class{ "com/pfs/jnipptest/TestFunctionDerivedContainer" };
//
//	Jni::FunctionHandle<void>	derived_class_func{ derived_class, "VoidNoArguments" };
//	Jni::FunctionHandle<void>	base_class_func{ base_class, "VoidNoArguments" };
//
//	EXPECT_EQ( *base_class_func, *derived_class_func );
//};

TEST( TestMemberFunction, CallNvVoidNoArguments )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "VoidNoArguments", void );

	func.CallNonVirtual( test_object );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestMemberFunction, CallNvVoidOneArgument )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "VoidOneArgument", void, const char* );

	func.CallNonVirtual( test_object, "1" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestMemberFunction, CallNvVoidTwoArguments )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "VoidTwoArguments", void, const char*, const char* );

	func.CallNonVirtual( test_object, "1", "2" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestMemberFunction, CallNvVoidThreeArguments )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "VoidThreeArguments", void, const char*, const char*, const char* );

	func.CallNonVirtual( test_object, "1", "2", "3" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestMemberFunction, CallNvStringNoArguments )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "StringNoArguments", std::string );

	auto ret = func.CallNonVirtual( test_object );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "Jni++", ret.c_str() );
};

TEST( TestMemberFunction, CallNvStringOneArgument )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "StringOneArgument", std::string, const char* );

	auto ret = func.CallNonVirtual( test_object, "1" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1", ret.c_str() );
};

TEST( TestMemberFunction, CallNvStringTwoArguments )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, const char*, const char* );

	auto ret = func.CallNonVirtual( test_object, "1", "2" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestMemberFunction, CallNvStringThreeArguments )
{
	DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( "StringThreeArguments", std::string, const char*, const char*, const char* );

	auto ret = func.CallNonVirtual( test_object, "1", "2", "3" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1 2 3", ret.c_str() );
};
