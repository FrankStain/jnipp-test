// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestFieldHandle, ValidBool )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( bool, "bool" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidStringUtf8 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidStringUtf16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::u16string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidCharStreamUtf8 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( const char*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidCharStreamUtf16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( const char16_t*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidFloat )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( float, "float" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidDouble )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( double, "double" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidByte )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int8_t, "byte" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedByte )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint8_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidChar16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( char16_t, "char" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidShort )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int16_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedShort )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint16_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidInt )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int32_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedInt )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint32_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidLong )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedLong )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};
