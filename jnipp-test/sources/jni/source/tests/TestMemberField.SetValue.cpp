// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


#define CHECK_RW( TYPE, VALUE )										\
	{																\
		const TYPE field_value = VALUE;								\
		EXPECT_TRUE( field.SetValue( test_object, field_value ) );	\
	};																\
																	\
	{																\
		TYPE field_value;											\
		EXPECT_TRUE( field.GetValue( test_object, field_value ) );	\
		EXPECT_EQ( VALUE, field_value );							\
	};



TEST( TestMemberField, SetBool )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( bool, "bool" );
	CHECK_RW( bool, false );
};

TEST( TestMemberField, SetStringUtf8 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::string, "string" );
	
	{
		const std::string field_value{ "Hello from Jni++!" };
		EXPECT_TRUE( field.SetValue( test_object, field_value ) );
	};

	{
		std::string field_value;
		EXPECT_TRUE( field.GetValue( test_object, field_value ) );
		EXPECT_STREQ( "Hello from Jni++!", field_value.c_str() );
	};
};

TEST( TestMemberField, SetStringUtf16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( std::u16string, "string" );
	
	{
		const std::u16string field_value{ u"Hello from Jni++!" };
		EXPECT_TRUE( field.SetValue( test_object, field_value ) );
	};

	{
		std::u16string field_value;
		EXPECT_TRUE( field.GetValue( test_object, field_value ) );
		EXPECT_TRUE( field_value == u"Hello from Jni++!" );
	};
};

TEST( TestMemberField, SetCharStreamUtf8 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( const char*, "string" );

	const char* field_value = "Hello from Jni++!";
	EXPECT_TRUE( field.SetValue( test_object, field_value ) );
};

TEST( TestMemberField, SetCharStreamUtf16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( const char16_t*, "string" );

	const char16_t* field_value = u"Hello from Jni++!";
	EXPECT_TRUE( field.SetValue( test_object, field_value ) );
};

TEST( TestMemberField, SetFloat )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( float, "float" );
	CHECK_RW( float, 32.3f );
};

TEST( TestMemberField, SetDouble )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( double, "double" );
	CHECK_RW( double, 62.4 );
};

TEST( TestMemberField, SetByte )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int8_t, "byte" );
	CHECK_RW( int8_t, -120 );
};

TEST( TestMemberField, SetUnsignedByte )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint8_t, "short" );
	CHECK_RW( uint8_t, 250 );
};

TEST( TestMemberField, SetChar16 )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( char16_t, "char" );
	CHECK_RW( char16_t, u'J' );
};

TEST( TestMemberField, SetShort )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int16_t, "short" );
	CHECK_RW( int16_t, 32000 );
};

TEST( TestMemberField, SetUnsignedShort )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint16_t, "int" );
	CHECK_RW( uint16_t, 64328 );
};

TEST( TestMemberField, SetInt )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int32_t, "int" );
	CHECK_RW( int32_t, -58 );
};

TEST( TestMemberField, SetUnsignedInt )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint32_t, "long" );
	CHECK_RW( uint32_t, 280 );
};

TEST( TestMemberField, SetLong )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( int64_t, "long" );
	CHECK_RW( int64_t, 1LL << 33 );
};

TEST( TestMemberField, SetUnsignedLong )
{
	DECLARE_MEMBER_FIELD_TEST_ENV( uint64_t, "long" );
	CHECK_RW( uint64_t, 1LL << 35 );
};
