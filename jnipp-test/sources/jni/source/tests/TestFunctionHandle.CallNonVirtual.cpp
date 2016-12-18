// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_TEST_ENV( NAME, RET, ... )																		\
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFunctionDerivedContainer" };						\
	jnipp::ClassHandle base_class_handle{ "com/pfs/jnipptest/TestFunctionContainer" };							\
																												\
	jnipp::FunctionHandle<RET, ##__VA_ARGS__>	func{ base_class_handle, NAME };								\
	jnipp::FieldHandle<bool>					call_check{ base_class_handle, "m_is_called" };					\
	jnipp::ObjectHandle							test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };	\
																												\
	EXPECT_TRUE( func );																						\
	EXPECT_TRUE( call_check );																					\
	EXPECT_TRUE( test_object )

#define EXAMINE_CALL_FLAG( ... )										\
	{																	\
		bool is_called = false;											\
		EXPECT_TRUE( call_check.GetValue( test_object, is_called ) );	\
		EXPECT_TRUE( is_called );										\
	}


//TEST( TestFunctionHandle, CheckFunctionIds )
//{
//	jnipp::ClassHandle base_class{ "com/pfs/jnipptest/TestFunctionContainer" };
//	jnipp::ClassHandle derived_class{ "com/pfs/jnipptest/TestFunctionDerivedContainer" };
//
//	jnipp::FunctionHandle<void>	derived_class_func{ derived_class, "VoidNoArguments" };
//	jnipp::FunctionHandle<void>	base_class_func{ base_class, "VoidNoArguments" };
//
//	EXPECT_EQ( *base_class_func, *derived_class_func );
//};

TEST( TestFunctionHandle, CallNvVoidNoArguments )
{
	DECLARE_TEST_ENV( "VoidNoArguments", void );

	func.CallNonVirtual( test_object, class_handle );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallNvVoidOneArgument )
{
	DECLARE_TEST_ENV( "VoidOneArgument", void, const char* );

	func.CallNonVirtual( test_object, class_handle, "1" );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallNvVoidTwoArguments )
{
	DECLARE_TEST_ENV( "VoidTwoArguments", void, const char*, const char* );

	func.CallNonVirtual( test_object, class_handle, "1", "2" );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallNvVoidThreeArguments )
{
	DECLARE_TEST_ENV( "VoidThreeArguments", void, const char*, const char*, const char* );

	func.CallNonVirtual( test_object, class_handle, "1", "2", "3" );

	EXAMINE_CALL_FLAG();
};

TEST( TestFunctionHandle, CallNvStringNoArguments )
{
	DECLARE_TEST_ENV( "StringNoArguments", std::string );

	auto ret = func.CallNonVirtual( test_object, class_handle );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "Jni++", ret.c_str() );
};

TEST( TestFunctionHandle, CallNvStringOneArgument )
{
	DECLARE_TEST_ENV( "StringOneArgument", std::string, const char* );

	auto ret = func.CallNonVirtual( test_object, class_handle, "1" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1", ret.c_str() );
};

TEST( TestFunctionHandle, CallNvStringTwoArguments )
{
	DECLARE_TEST_ENV( "StringTwoArguments", std::string, const char*, const char* );

	auto ret = func.CallNonVirtual( test_object, class_handle, "1", "2" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestFunctionHandle, CallNvStringThreeArguments )
{
	DECLARE_TEST_ENV( "StringThreeArguments", std::string, const char*, const char*, const char* );

	auto ret = func.CallNonVirtual( test_object, class_handle, "1", "2", "3" );

	EXAMINE_CALL_FLAG();
	EXPECT_STREQ( "1 2 3", ret.c_str() );
};
