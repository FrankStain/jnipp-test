// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_TEST_ENV( NAME, RET, ... )																	\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestFunctionContainer" };								\
																											\
	Jni::FunctionHandle<RET, ##__VA_ARGS__>	func{ class_handle, NAME };										\
	Jni::FieldHandle<bool>					call_check{ class_handle, "m_is_called" };						\
	Jni::ObjectHandle						test_object{ Jni::ObjectHandle::NewObject( class_handle ) };	\
																											\
	EXPECT_TRUE( func );																					\
	EXPECT_TRUE( call_check );																				\
	EXPECT_TRUE( test_object )

#define EXAMINE_CALL_FLAG( ... )										\
	{																	\
		bool is_called = false;											\
		EXPECT_TRUE( call_check.GetValue( test_object, is_called ) );	\
		EXPECT_TRUE( is_called );										\
	}


TEST( TestFunctionHandle, CallVoidNoArguments )
{
	DECLARE_TEST_ENV( "VoidNoArguments", void );

	func.Call( test_object );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallVoidOneArgument )
{
	DECLARE_TEST_ENV( "VoidOneArgument", void, const char* );

	func.Call( test_object, "1" );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallVoidTwoArguments )
{
	DECLARE_TEST_ENV( "VoidTwoArguments", void, const char*, const char* );

	func.Call( test_object, "1", "2" );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallVoidThreeArguments )
{
	DECLARE_TEST_ENV( "VoidThreeArguments", void, const char*, const char*, const char* );

	func.Call( test_object, "1", "2", "3" );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallStringNoArguments )
{
	DECLARE_TEST_ENV( "StringNoArguments", std::string );

	auto ret = func.Call( test_object );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "Jni++", ret.c_str() );
};

TEST( TestFunctionHandle, CallStringOneArgument )
{
	DECLARE_TEST_ENV( "StringOneArgument", std::string, const char* );

	auto ret = func.Call( test_object, "1" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1", ret.c_str() );
};

TEST( TestFunctionHandle, CallStringTwoArguments )
{
	DECLARE_TEST_ENV( "StringTwoArguments", std::string, const char*, const char* );

	auto ret = func.Call( test_object, "1", "2" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestFunctionHandle, CallStringThreeArguments )
{
	DECLARE_TEST_ENV( "StringThreeArguments", std::string, const char*, const char*, const char* );

	auto ret = func.Call( test_object, "1", "2", "3" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1 2 3", ret.c_str() );
};
