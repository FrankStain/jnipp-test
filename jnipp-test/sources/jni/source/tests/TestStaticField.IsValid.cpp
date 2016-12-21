// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestStaticField, ValidBool )
{
	DECLARE_STATIC_FIELD_TEST_ENV( bool, "bool" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidStringUtf8 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidStringUtf16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::u16string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidCharStreamUtf8 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( const char*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidCharStreamUtf16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( const char16_t*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidFloat )
{
	DECLARE_STATIC_FIELD_TEST_ENV( float, "float" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidDouble )
{
	DECLARE_STATIC_FIELD_TEST_ENV( double, "double" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidByte )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int8_t, "byte" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidUnsignedByte )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint8_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidChar16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( char16_t, "char" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidShort )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int16_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidUnsignedShort )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint16_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidInt )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int32_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidUnsignedInt )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint32_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidLong )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticField, ValidUnsignedLong )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};
