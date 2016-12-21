// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestStaticFunctionHandle, CallVoidNoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidNoArguments", void );

	func.Call();

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallVoidOneArgument )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidOneArgument", void, const char* );

	func.Call( "1" );

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallVoidTwoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidTwoArguments", void, const char*, const char* );

	func.Call( "1", "2" );

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallVoidThreeArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidThreeArguments", void, const char*, const char*, const char* );

	func.Call( "1", "2", "3" );

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallStringNoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringNoArguments", std::string );

	auto ret = func.Call();

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "Jni++", ret.c_str() );
};

TEST( TestStaticFunctionHandle, CallStringOneArgument )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringOneArgument", std::string, const char* );

	auto ret = func.Call( "1" );

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1", ret.c_str() );
};

TEST( TestStaticFunctionHandle, CallStringTwoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, const char*, const char* );

	auto ret = func.Call( "1", "2" );

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestStaticFunctionHandle, CallStringThreeArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringThreeArguments", std::string, const char*, const char*, const char* );

	auto ret = func.Call( "1", "2", "3" );

	EXAMINE_STATIC_FUNCTION_CALL_FLAG();
	EXPECT_STREQ( "1 2 3", ret.c_str() );
};
