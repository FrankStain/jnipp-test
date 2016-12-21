// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestEnvironment, Allocation )
{
	Jni::Environment	local_env;

	EXPECT_TRUE( local_env.IsValid() );
	EXPECT_TRUE( local_env );
};

TEST( TestEnvironment, MemberFieldGetValue )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( bool, "bool" );

	Jni::Environment local_env;
	bool field_value;
	EXPECT_TRUE( local_env.GetValue( field, test_object, field_value ) );

	EXPECT_TRUE( field_value );
};

TEST( TestEnvironment, StaticFieldGetValue )
{
	DECLARE_STATIC_FIELD_TEST_ENV( bool, "bool" );

	Jni::Environment local_env;
	bool field_value;
	EXPECT_TRUE( local_env.GetValue( field, field_value ) );

	EXPECT_TRUE( field_value );
};

TEST( TestEnvironment, MemberFieldSetValue )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::string, "string" );

	Jni::Environment local_env;
	const char* field_value = "Hello Jni++";
	EXPECT_TRUE( local_env.SetValue( field, test_object, field_value ) );

	std::string field_check;
	EXPECT_TRUE( local_env.GetValue( field, test_object, field_check ) );

	EXPECT_STREQ( field_value, field_check.c_str() );
};

TEST( TestEnvironment, StaticFieldSetValue )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::string, "string" );

	Jni::Environment local_env;
	const char* field_value = "Hello Jni++";
	EXPECT_TRUE( local_env.SetValue( field, field_value ) );

	std::string field_check;
	EXPECT_TRUE( local_env.GetValue( field, field_check ) );

	EXPECT_STREQ( field_value, field_check.c_str() );
};

TEST( TestEnvironment, CallMemberFunction )
{
	DECLARE_MEMBER_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	Jni::Environment local_env;

	auto ret = local_env.Call( func, test_object, "1", "2" );
	EXAMINE_MEMBER_FUNCTION_CALL_FLAG();

	EXPECT_STREQ( "1 2", ret.c_str() );
};

TEST( TestEnvironment, CallStaticFunction )
{
	DECLARE_STATIC_FUNCTION_TEST_ENV( "StringTwoArguments", std::string, std::string, std::string );

	Jni::Environment local_env;

	auto ret = local_env.Call( func, "1", "2" );
	EXAMINE_STATIC_FUNCTION_CALL_FLAG();

	EXPECT_STREQ( "1 2", ret.c_str() );
};
