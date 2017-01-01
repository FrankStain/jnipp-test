// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>

#include "TestingEnvironment.h"


TEST( TestArays, CaptureArrayField )
{
	Jni::Class class_handle{ "com/pfs/jnipptest/TestArrayStorage" };

	Jni::MemberField<std::vector<bool>> field{ class_handle, "m_bool_out_array" };

	EXPECT_TRUE( field.IsValid() );
};

TEST( TestArays, ReadArrayField )
{
	Jni::Class class_handle{ "com/pfs/jnipptest/TestArrayStorage" };

	Jni::MemberField<std::vector<bool>>	field{ class_handle, "m_bool_out_array" };
	Jni::Object							test_object{ Jni::Object::NewObject( class_handle ) };

	EXPECT_TRUE( field.IsValid() );

	std::vector<bool> value;
	EXPECT_TRUE( field.GetValue( test_object, value ) );

	const bool etalon_values[] = {
		true, false, true, true, false, true, false, true,
		true, false, true, true, false, true, false, true,
		true, false, true, true, false, true, false, true,
		true, false, true, true, false, true, false, true,
	};

	EXPECT_EQ( sizeof( etalon_values ), value.size() );
	for( size_t index = 0; index < value.size(); ++index )
	{
		EXPECT_EQ( etalon_values[ index ], value[ index ] );
	};
};
