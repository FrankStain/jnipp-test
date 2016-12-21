// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


#define DECLARE_TEST_ENV( TYPE, NAME )												\
	Jni::ClassHandle class_handle{ "com/pfs/jnipptest/TestStaticFieldStorage" };	\
																					\
	Jni::StaticFieldHandle<TYPE>	field{ class_handle, NAME "_field" };			\
	EXPECT_TRUE( field );															\
																					\
	Jni::StaticFunctionHandle<void> reset_func{ class_handle, "Reset" };			\
	reset_func.Call()


#define CHECK_RW( TYPE, VALUE )							\
	{													\
		const TYPE field_value = VALUE;					\
		EXPECT_TRUE( field.SetValue( field_value ) );	\
	};													\
														\
	{													\
		TYPE field_value;								\
		EXPECT_TRUE( field.GetValue( field_value ) );	\
		EXPECT_EQ( VALUE, field_value );				\
	};



TEST( TestStaticFieldHandle, SetBool )
{
	DECLARE_TEST_ENV( bool, "bool" );
	CHECK_RW( bool, false );
};

TEST( TestStaticFieldHandle, SetStringUtf8 )
{
	DECLARE_TEST_ENV( std::string, "string" );
	
	{
		const std::string field_value{ "Hello from Jni++!" };
		EXPECT_TRUE( field.SetValue( field_value ) );
	};

	{
		std::string field_value;
		EXPECT_TRUE( field.GetValue( field_value ) );
		EXPECT_STREQ( "Hello from Jni++!", field_value.c_str() );
	};
};

TEST( TestStaticFieldHandle, SetStringUtf16 )
{
	DECLARE_TEST_ENV( std::u16string, "string" );
	
	{
		const std::u16string field_value{ u"Hello from Jni++!" };
		EXPECT_TRUE( field.SetValue( field_value ) );
	};

	{
		std::u16string field_value;
		EXPECT_TRUE( field.GetValue( field_value ) );
		EXPECT_TRUE( field_value == u"Hello from Jni++!" );
	};
};

TEST( TestStaticFieldHandle, SetCharStreamUtf8 )
{
	DECLARE_TEST_ENV( const char*, "string" );

	const char* field_value = "Hello from Jni++!";
	EXPECT_TRUE( field.SetValue( field_value ) );
};

TEST( TestStaticFieldHandle, SetCharStreamUtf16 )
{
	DECLARE_TEST_ENV( const char16_t*, "string" );

	const char16_t* field_value = u"Hello from Jni++!";
	EXPECT_TRUE( field.SetValue( field_value ) );
};

TEST( TestStaticFieldHandle, SetFloat )
{
	DECLARE_TEST_ENV( float, "float" );
	CHECK_RW( float, 32.3f );
};

TEST( TestStaticFieldHandle, SetDouble )
{
	DECLARE_TEST_ENV( double, "double" );
	CHECK_RW( double, 62.4 );
};

TEST( TestStaticFieldHandle, SetByte )
{
	DECLARE_TEST_ENV( int8_t, "byte" );
	CHECK_RW( int8_t, -120 );
};

TEST( TestStaticFieldHandle, SetUnsignedByte )
{
	DECLARE_TEST_ENV( uint8_t, "short" );
	CHECK_RW( uint8_t, 250 );
};

TEST( TestStaticFieldHandle, SetChar16 )
{
	DECLARE_TEST_ENV( char16_t, "char" );
	CHECK_RW( char16_t, u'J' );
};

TEST( TestStaticFieldHandle, SetShort )
{
	DECLARE_TEST_ENV( int16_t, "short" );
	CHECK_RW( int16_t, 32000 );
};

TEST( TestStaticFieldHandle, SetUnsignedShort )
{
	DECLARE_TEST_ENV( uint16_t, "int" );
	CHECK_RW( uint16_t, 64328 );
};

TEST( TestStaticFieldHandle, SetInt )
{
	DECLARE_TEST_ENV( int32_t, "int" );
	CHECK_RW( int32_t, -58 );
};

TEST( TestStaticFieldHandle, SetUnsignedInt )
{
	DECLARE_TEST_ENV( uint32_t, "long" );
	CHECK_RW( uint32_t, 280 );
};

TEST( TestStaticFieldHandle, SetLong )
{
	DECLARE_TEST_ENV( int64_t, "long" );
	CHECK_RW( int64_t, 1LL << 33 );
};

TEST( TestStaticFieldHandle, SetUnsignedLong )
{
	DECLARE_TEST_ENV( uint64_t, "long" );
	CHECK_RW( uint64_t, 1LL << 35 );
};
