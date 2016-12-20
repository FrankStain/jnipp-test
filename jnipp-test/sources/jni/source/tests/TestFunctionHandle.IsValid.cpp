// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_TEST_ENV( NAME, RET, ... )										\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestFunctionContainer" };	\
																				\
	Jni::FunctionHandle<RET, ##__VA_ARGS__>	func{ class_handle, NAME };


TEST( TestFunctionHandle, ValidVoidNoArguments )
{
	DECLARE_TEST_ENV( "VoidNoArguments", void );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidVoidOneArgument )
{
	DECLARE_TEST_ENV( "VoidOneArgument", void, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidVoidTwoArguments )
{
	DECLARE_TEST_ENV( "VoidTwoArguments", void, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidVoidThreeArguments )
{
	DECLARE_TEST_ENV( "VoidThreeArguments", void, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringNoArguments )
{
	DECLARE_TEST_ENV( "StringNoArguments", std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringOneArgument )
{
	DECLARE_TEST_ENV( "StringOneArgument", std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringTwoArguments )
{
	DECLARE_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};

TEST( TestFunctionHandle, ValidStringThreeArguments )
{
	DECLARE_TEST_ENV( "StringThreeArguments", std::string, std::string, std::string, std::string );

	EXPECT_TRUE( func.IsValid() );
	EXPECT_NE( nullptr, *func );
};
