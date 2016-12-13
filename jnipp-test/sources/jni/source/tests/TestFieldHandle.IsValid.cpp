// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestFieldHandle, ValidBool )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<bool>	field{ class_handle, "m_bool_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidStringUtf8 )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<std::string>	field{ class_handle, "m_string_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidStringUtf16 )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<std::u16string>	field{ class_handle, "m_string_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidCharStreamUtf8 )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<const char*>	field{ class_handle, "m_string_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidCharStreamUtf16 )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<const char16_t*>	field{ class_handle, "m_string_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidFloat )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<float>	field{ class_handle, "m_float_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidDouble )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<double>	field{ class_handle, "m_double_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidByte )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int8_t>	field{ class_handle, "m_byte_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedByte )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint8_t>	field{ class_handle, "m_short_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidChar16 )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<char16_t>	field{ class_handle, "m_char_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidShort )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int16_t>	field{ class_handle, "m_short_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedShort )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint16_t>	field{ class_handle, "m_int_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidInt )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int32_t>	field{ class_handle, "m_int_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedInt )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint32_t>	field{ class_handle, "m_long_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidLong )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<int64_t>	field{ class_handle, "m_long_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};

TEST( TestFieldHandle, ValidUnsignedLong )
{
	jnipp::ClassHandle class_handle{ "com/pfs/jnipptest/TestFieldStorage" };

	jnipp::FieldHandle<uint64_t>	field{ class_handle, "m_long_field" };
	EXPECT_TRUE( field.IsValid() );
	EXPECT_NE( nullptr, *field );
};
