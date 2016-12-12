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
