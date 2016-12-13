// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestFieldHandle, GetBool )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<bool>	field{ class_handle, "m_bool_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	bool field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_TRUE( field_value );
};

TEST( TestFieldHandle, GetString )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<std::string>	field{ class_handle, "m_string_field" };
	jnipp::ObjectHandle				test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	std::string field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_STREQ( "Jni++", field_value.c_str() );
};

TEST( TestFieldHandle, GetFloat )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<float>	field{ class_handle, "m_float_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	float field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 13.0f, field_value );
};

TEST( TestFieldHandle, GetDouble )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<double>	field{ class_handle, "m_double_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	double field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 42.0, field_value );
};

TEST( TestFieldHandle, GetByte )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int8_t>	field{ class_handle, "m_byte_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	int8_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 28, field_value );
};

TEST( TestFieldHandle, GetUnsignedByte )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint8_t>	field{ class_handle, "m_short_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	uint8_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 24, field_value );
};

TEST( TestFieldHandle, GetChar16 )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<char16_t>	field{ class_handle, "m_char_field" };
	jnipp::ObjectHandle				test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	char16_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( u'S', field_value );
};

TEST( TestFieldHandle, GetShort )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int16_t>	field{ class_handle, "m_short_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	int16_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 24, field_value );
};

TEST( TestFieldHandle, GetUnsignedShort )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint16_t>	field{ class_handle, "m_int_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	uint16_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 0, field_value );
};

TEST( TestFieldHandle, GetInt )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int32_t>	field{ class_handle, "m_int_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	int32_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 65536, field_value );
};

TEST( TestFieldHandle, GetUnsignedInt )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint32_t>	field{ class_handle, "m_long_field" };
	jnipp::ObjectHandle				test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	uint32_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( 0, field_value );
};

TEST( TestFieldHandle, GetLong )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int64_t>	field{ class_handle, "m_long_field" };
	jnipp::ObjectHandle			test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	int64_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( ( 1LL << 48 ), field_value );
};

TEST( TestFieldHandle, GetUnsignedLong )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint64_t>	field{ class_handle, "m_long_field" };
	jnipp::ObjectHandle				test_object{ jnipp::ObjectHandle::NewObject( class_handle ) };

	EXPECT_TRUE( field );
	EXPECT_TRUE( test_object );

	uint64_t field_value;
	EXPECT_TRUE( field.GetValue( test_object, field_value ) );

	EXPECT_EQ( ( 1LL << 48 ), field_value );
};
