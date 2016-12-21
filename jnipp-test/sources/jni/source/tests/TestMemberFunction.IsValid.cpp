// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestFunctionHandle, ValidVoidNoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidNoArguments", void );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidVoidOneArgument )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidOneArgument", void, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidVoidTwoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidTwoArguments", void, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidVoidThreeArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "VoidThreeArguments", void, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringNoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringNoArguments", std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringOneArgument )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringOneArgument", std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringTwoArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringThreeArguments )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringThreeArguments", std::string, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};
