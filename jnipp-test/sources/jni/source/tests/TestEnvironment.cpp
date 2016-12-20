// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_MEMBER_FIELD_TEST_ENV( TYPE, NAME )															\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };									\
																											\
	Jni::FieldHandle<TYPE>	field{ class_handle, "m_" NAME "_field" };										\
	Jni::ObjectHandle		test_object{ Jni::ObjectHandle::NewObject( class_handle ) };					\
																											\
	EXPECT_TRUE( field );																					\
	EXPECT_TRUE( test_object )

#define DECLARE_STATIC_FIELD_TEST_ENV( TYPE, NAME )															\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestStaticFieldStorage" };							\
																											\
	Jni::StaticFieldHandle<TYPE>	field{ class_handle, NAME "_field" };									\
																											\
	EXPECT_TRUE( field )

#define DECLARE_MEMBER_FUNCTION_TEST_ENV( NAME, RET, ... )													\
	Jni::ClassHandle derived_class{ "com/pfs/jnipptest/TestFunctionDerivedContainer" };						\
	Jni::ClassHandle basic_class{ derived_class.GetParentClassHandle() };									\
																											\
	Jni::FunctionHandle<RET, ##__VA_ARGS__>	func{ basic_class, NAME };										\
	Jni::FieldHandle<bool>					call_check{ basic_class, "m_is_called" };						\
	Jni::ObjectHandle						test_object{ Jni::ObjectHandle::NewObject( derived_class ) };	\
																											\
	EXPECT_TRUE( func );																					\
	EXPECT_TRUE( call_check );																				\
	EXPECT_TRUE( test_object )

#define EXAMINE_MEMBER_FUNCTION_CALL_FLAG( ... )															\
	{																										\
		bool is_called = false;																				\
		EXPECT_TRUE( call_check.GetValue( test_object, is_called ) );										\
		EXPECT_TRUE( is_called );																			\
	}

#define DECLARE_STATIC_FUNCTION_TEST_ENV( NAME, RET, ... )													\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestStaticFunctionContainer" };						\
																											\
	Jni::StaticFunctionHandle<RET, ##__VA_ARGS__>	func{ class_handle, NAME };								\
	Jni::StaticFieldHandle<bool>					call_check{ class_handle, "is_called" };				\
																											\
	EXPECT_TRUE( func );																					\
	EXPECT_TRUE( call_check );																				\
	EXPECT_TRUE( call_check.SetValue( false ) )

#define EXAMINE_STATIC_FUNCTION_CALL_FLAG( ... )															\
	{																										\
		bool is_called = false;																				\
		EXPECT_TRUE( call_check.GetValue( is_called ) );													\
		EXPECT_TRUE( is_called );																			\
	}


TEST( TestEnvironment, Allocation )
{
	Jni::JniEnv	local_env;

	EXPECT_TRUE( local_env.IsValid() );
	EXPECT_TRUE( local_env );
};

TEST( TestEnvironment, MemberFieldGetValue )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( bool, "bool" );

	Jni::JniEnv local_env;
	bool field_value;
	EXPECT_TRUE( local_env.GetValue( field, test_object, field_value ) );

	EXPECT_TRUE( field_value );
};

TEST( TestEnvironment, StaticFieldGetValue )
{
	DECLARE_STATIC_FIELD_TEST_ENV( bool, "bool" );

	Jni::JniEnv local_env;
	bool field_value;
	EXPECT_TRUE( local_env.GetValue( field, field_value ) );

	EXPECT_TRUE( field_value );
};

TEST( TestEnvironment, MemberFieldSetValue )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::string, "string" );

	Jni::JniEnv local_env;
	const char* field_value = "Hello Jni++";
	EXPECT_TRUE( local_env.SetValue( field, test_object, { field_value } ) );

	std::string field_check;
	EXPECT_TRUE( local_env.GetValue( field, test_object, field_check ) );

	EXPECT_STREQ( field_value, field_check.c_str() );
};

TEST( TestEnvironment, StaticFieldSetValue )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::string, "string" );

	Jni::JniEnv local_env;
	const char* field_value = "Hello Jni++";
	EXPECT_TRUE( local_env.SetValue( field, { field_value } ) );

	std::string field_check;
	EXPECT_TRUE( local_env.GetValue( field, field_check ) );

	EXPECT_STREQ( field_value, field_check.c_str() );
};

TEST( TestEnvironment, CallMemberFunction )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	Jni::JniEnv local_env;

	auto ret = local_env.Call( func, test_object, { "1" }, { "2" } );
	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();

	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestEnvironment, CallStaticFunction )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	Jni::JniEnv local_env;

	auto ret = local_env.Call( func, { "1" }, { "2" } );
	EXAMINE_STATIC_FUNCTION_CALL_FLAG();

	EXPECT_STREQ( "1 2", ret.c_str() );
};
