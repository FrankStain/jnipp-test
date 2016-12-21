// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestFunctionHandle, CallVoidNoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidNoArguments", void );

	func.Call( test_object );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestFunctionHandle, CallVoidOneArgument )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidOneArgument", void, const char* );

	func.Call( test_object, "1" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestFunctionHandle, CallVoidTwoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidTwoArguments", void, const char*, const char* );

	func.Call( test_object, "1", "2" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestFunctionHandle, CallVoidThreeArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidThreeArguments", void, const char*, const char*, const char* );

	func.Call( test_object, "1", "2", "3" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
};

TEST( TestFunctionHandle, CallStringNoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringNoArguments", std::string );

	auto ret = func.Call( test_object );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "Jni++", ret.c_str() );
};

TEST( TestFunctionHandle, CallStringOneArgument )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringOneArgument", std::string, const char* );

	auto ret = func.Call( test_object, "1" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1", ret.c_str() );
};

TEST( TestFunctionHandle, CallStringTwoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, const char*, const char* );

	auto ret = func.Call( test_object, "1", "2" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestFunctionHandle, CallStringThreeArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringThreeArguments", std::string, const char*, const char*, const char* );

	auto ret = func.Call( test_object, "1", "2", "3" );

	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1 2 3", ret.c_str() );
};
