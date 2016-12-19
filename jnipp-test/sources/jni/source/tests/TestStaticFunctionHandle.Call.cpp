// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_TEST_ENV( NAME, RET, ... )														\
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestStaticFunctionContainer" };			\
																								\
	jnipp::StaticFunctionHandle<RET, ##__VA_ARGS__>	func{ class_handle, NAME };					\
	jnipp::StaticFieldHandle<bool>					call_check{ class_handle, "is_called" };	\
																								\
	EXPECT_TRUE( func );																		\
	EXPECT_TRUE( call_check );																	\
	EXPECT_TRUE( call_check.SetValue( false ) )

#define EXAMINE_CALL_FLAG( ... )							\
	{														\
		bool is_called = false;								\
		EXPECT_TRUE( call_check.GetValue( is_called ) );	\
		EXPECT_TRUE( is_called );							\
	}


TEST( TestStaticFunctionHandle, CallVoidNoArguments )
{
	DECLARE_TEST_ENV( "VoidNoArguments", void );

	func.Call();

	EXAMINE_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallVoidOneArgument )
{
	DECLARE_TEST_ENV( "VoidOneArgument", void, const char* );

	func.Call( "1" );

	EXAMINE_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallVoidTwoArguments )
{
	DECLARE_TEST_ENV( "VoidTwoArguments", void, const char*, const char* );

	func.Call( "1", "2" );

	EXAMINE_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallVoidThreeArguments )
{
	DECLARE_TEST_ENV( "VoidThreeArguments", void, const char*, const char*, const char* );

	func.Call( "1", "2", "3" );

	EXAMINE_CALL_FLAG();
};

TEST( TestStaticFunctionHandle, CallStringNoArguments )
{
	DECLARE_TEST_ENV( "StringNoArguments", std::string );

	auto ret = func.Call();

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "Jni++", ret.c_str() );
};

TEST( TestStaticFunctionHandle, CallStringOneArgument )
{
	DECLARE_TEST_ENV( "StringOneArgument", std::string, const char* );

	auto ret = func.Call( "1" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1", ret.c_str() );
};

TEST( TestStaticFunctionHandle, CallStringTwoArguments )
{
	DECLARE_TEST_ENV( "StringTwoArguments", std::string, const char*, const char* );

	auto ret = func.Call( "1", "2" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestStaticFunctionHandle, CallStringThreeArguments )
{
	DECLARE_TEST_ENV( "StringThreeArguments", std::string, const char*, const char*, const char* );

	auto ret = func.Call( "1", "2", "3" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1 2 3", ret.c_str() );
};
