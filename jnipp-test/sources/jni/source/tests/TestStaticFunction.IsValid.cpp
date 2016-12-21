// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestStaticFunctionHandle, ValidVoidNoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidNoArguments", void );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidVoidOneArgument )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidOneArgument", void, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidVoidTwoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidTwoArguments", void, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidVoidThreeArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidThreeArguments", void, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidStringNoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringNoArguments", std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidStringOneArgument )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringOneArgument", std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidStringTwoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunctionHandle, ValidStringThreeArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringThreeArguments", std::string, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};
