// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestMemberField, ValidBool )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( bool, "bool" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidStringUtf8 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidStringUtf16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::u16string, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidCharStreamUtf8 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( const char*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidCharStreamUtf16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( const char16_t*, "string" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidFloat )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( float, "float" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidDouble )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( double, "double" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidByte )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int8_t, "byte" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidUnsignedByte )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint8_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidChar16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( char16_t, "char" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidShort )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int16_t, "short" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidUnsignedShort )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint16_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidInt )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int32_t, "int" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidUnsignedInt )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint32_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidLong )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestMemberField, ValidUnsignedLong )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint64_t, "long" );
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};
