// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_TEST_ENV( TYPE, NAME )														\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };					\
																							\
	Jni::FieldHandle<TYPE>	field{ class_handle, "m_" NAME "_field" };						\
	Jni::ObjectHandle		test_object{ Jni::ObjectHandle::NewObject( class_handle ) };	\
																							\
	EXPECT_TRUE( field );																	\
	EXPECT_TRUE( test_object );


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



TEST( TestFieldHandle, SetBool )
{
	DECLARE_TEST_ENV( bool, "bool" );
	CHECK_RW( bool, false );
};

TEST( TestFieldHandle, SetStringUtf8 )
{
	DECLARE_TEST_ENV( std::string, "string" );
	
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

TEST( TestFieldHandle, SetStringUtf16 )
{
	DECLARE_TEST_ENV( std::u16string, "string" );
	
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

TEST( TestFieldHandle, SetCharStreamUtf8 )
{
	DECLARE_TEST_ENV( const char*, "string" );

	const char* field_value = "Hello from Jni++!";
	EXPECT_TRUE( field.SetValue( test_object, field_value ) );
};

TEST( TestFieldHandle, SetCharStreamUtf16 )
{
	DECLARE_TEST_ENV( const char16_t*, "string" );

	const char16_t* field_value = u"Hello from Jni++!";
	EXPECT_TRUE( field.SetValue( test_object, field_value ) );
};

TEST( TestFieldHandle, SetFloat )
{
	DECLARE_TEST_ENV( float, "float" );
	CHECK_RW( float, 32.3f );
};

TEST( TestFieldHandle, SetDouble )
{
	DECLARE_TEST_ENV( double, "double" );
	CHECK_RW( double, 62.4 );
};

TEST( TestFieldHandle, SetByte )
{
	DECLARE_TEST_ENV( int8_t, "byte" );
	CHECK_RW( int8_t, -120 );
};

TEST( TestFieldHandle, SetUnsignedByte )
{
	DECLARE_TEST_ENV( uint8_t, "short" );
	CHECK_RW( uint8_t, 250 );
};

TEST( TestFieldHandle, SetChar16 )
{
	DECLARE_TEST_ENV( char16_t, "char" );
	CHECK_RW( char16_t, u'J' );
};

TEST( TestFieldHandle, SetShort )
{
	DECLARE_TEST_ENV( int16_t, "short" );
	CHECK_RW( int16_t, 32000 );
};

TEST( TestFieldHandle, SetUnsignedShort )
{
	DECLARE_TEST_ENV( uint16_t, "int" );
	CHECK_RW( uint16_t, 64328 );
};

TEST( TestFieldHandle, SetInt )
{
	DECLARE_TEST_ENV( int32_t, "int" );
	CHECK_RW( int32_t, -58 );
};

TEST( TestFieldHandle, SetUnsignedInt )
{
	DECLARE_TEST_ENV( uint32_t, "long" );
	CHECK_RW( uint32_t, 280 );
};

TEST( TestFieldHandle, SetLong )
{
	DECLARE_TEST_ENV( int64_t, "long" );
	CHECK_RW( int64_t, 1LL << 33 );
};

TEST( TestFieldHandle, SetUnsignedLong )
{
	DECLARE_TEST_ENV( uint64_t, "long" );
	CHECK_RW( uint64_t, 1LL << 35 );
};
