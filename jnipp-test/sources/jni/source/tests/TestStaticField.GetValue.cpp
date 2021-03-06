// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestStaticField, GetBool )
{
	DECLARE_STATIC_FIELD_TEST_ENV( bool, "bool" );

	bool field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_TRUE( field_value );
};

TEST( TestStaticField, GetString )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::string, "string" );

	std::string field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_STREQ( "Jni++", field_value.c_str() );
};

TEST( TestStaticField, GetFloat )
{
	DECLARE_STATIC_FIELD_TEST_ENV( float, "float" );

	float field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 13.0f, field_value );
};

TEST( TestStaticField, GetDouble )
{
	DECLARE_STATIC_FIELD_TEST_ENV( double, "double" );

	double field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 42.0, field_value );
};

TEST( TestStaticField, GetByte )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int8_t, "byte" );

	int8_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 28, field_value );
};

TEST( TestStaticField, GetUnsignedByte )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint8_t, "short" );

	uint8_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 24, field_value );
};

TEST( TestStaticField, GetChar16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( char16_t, "char" );

	char16_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( u'S', field_value );
};

TEST( TestStaticField, GetShort )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int16_t, "short" );

	int16_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 24, field_value );
};

TEST( TestStaticField, GetUnsignedShort )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint16_t, "int" );

	uint16_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 0, field_value );
};

TEST( TestStaticField, GetInt )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int32_t, "int" );

	int32_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 65536, field_value );
};

TEST( TestStaticField, GetUnsignedInt )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint32_t, "long" );

	uint32_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( 0, field_value );
};

TEST( TestStaticField, GetLong )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int64_t, "long" );

	int64_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( ( 1LL << 48 ), field_value );
};

TEST( TestStaticField, GetUnsignedLong )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint64_t, "long" );

	uint64_t field_value;
	EXPECT_TRUE( field.GetValue( field_value ) );

	EXPECT_EQ( ( 1LL << 48 ), field_value );
};
