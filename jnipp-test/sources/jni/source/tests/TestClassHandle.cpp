// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestClassHandle, EmptyIsValid )
{
	jnipp::ClassHandle class_handle;

	EXPECT_FALSE( class_handle.IsValid() );
};

TEST( TestClassHandle, ConstructedIsValid )
{
	jnipp::ClassHandle class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );
};

TEST( TestClassHandle, Invalidate )
{
	jnipp::ClassHandle class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );
	
	class_handle.Invalidate();
	EXPECT_FALSE( class_handle.IsValid() );
};

TEST( TestClassHandle, AssignString )
{
	jnipp::ClassHandle class_handle;

	EXPECT_FALSE( class_handle.IsValid() );

	class_handle = "java/lang/String";
	EXPECT_TRUE( class_handle.IsValid() );
};

TEST( TestClassHandle, CopyValid )
{
	jnipp::ClassHandle class_handle1;
	const jnipp::ClassHandle class_handle2{ "java/lang/String" };

	EXPECT_FALSE( class_handle1.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );

	class_handle1 = class_handle2;
	EXPECT_TRUE( class_handle1.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );

	const jnipp::ClassHandle class_handle3{ class_handle2 };
	EXPECT_TRUE( class_handle3.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );
};

TEST( TestClassHandle, MoveValid )
{
	jnipp::ClassHandle class_handle1;
	jnipp::ClassHandle class_handle2{ "java/lang/String" };

	EXPECT_FALSE( class_handle1.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );

	class_handle1 = std::move( class_handle2 );
	EXPECT_TRUE( class_handle1.IsValid() );
	EXPECT_FALSE( class_handle2.IsValid() );

	jnipp::ClassHandle class_handle3{ std::move( class_handle1 ) };
	EXPECT_TRUE( class_handle3.IsValid() );
	EXPECT_FALSE( class_handle1.IsValid() );
};

TEST( TestClassHandle, GetReference )
{
	jnipp::ClassHandle class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );
	EXPECT_NE( nullptr, *class_handle );
};
