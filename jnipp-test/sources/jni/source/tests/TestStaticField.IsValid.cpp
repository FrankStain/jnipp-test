// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestStaticFieldStorage, ValidBool )
{
	DECLARE_STATIC_FIELD_TEST_ENV( bool, "bool" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidStringUtf8 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidStringUtf16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( std::u16string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidCharStreamUtf8 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( const char*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidCharStreamUtf16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( const char16_t*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidFloat )
{
	DECLARE_STATIC_FIELD_TEST_ENV( float, "float" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidDouble )
{
	DECLARE_STATIC_FIELD_TEST_ENV( double, "double" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidByte )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int8_t, "byte" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidUnsignedByte )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint8_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidChar16 )
{
	DECLARE_STATIC_FIELD_TEST_ENV( char16_t, "char" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidShort )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int16_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidUnsignedShort )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint16_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidInt )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int32_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidUnsignedInt )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint32_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidLong )
{
	DECLARE_STATIC_FIELD_TEST_ENV( int64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestStaticFieldStorage, ValidUnsignedLong )
{
	DECLARE_STATIC_FIELD_TEST_ENV( uint64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};
