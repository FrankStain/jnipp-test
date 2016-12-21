// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestStaticFunction, ValidVoidNoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidNoArguments", void );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidVoidOneArgument )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidOneArgument", void, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidVoidTwoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidTwoArguments", void, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidVoidThreeArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "VoidThreeArguments", void, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidStringNoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringNoArguments", std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidStringOneArgument )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringOneArgument", std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidStringTwoArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestStaticFunction, ValidStringThreeArguments )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringThreeArguments", std::string, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};
