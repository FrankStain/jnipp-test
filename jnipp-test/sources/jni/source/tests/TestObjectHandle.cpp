// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestObjectHandle, EmptyIsValid )
{
	Jni::Object object_handle;

	EXPECT_FALSE( object_handle.IsValid() );
};

TEST( TestObjectHandle, NewObject )
{
	Jni::Object object_handle;

	EXPECT_FALSE( object_handle.IsValid() );

	object_handle = Jni::Object::NewObject( { "java/lang/String" } );

	EXPECT_TRUE( object_handle.IsValid() );
};

TEST( TestObjectHandle, Invalidate )
{
	Jni::Object object_handle{ Jni::Object::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle.IsValid() );

	object_handle.Invalidate();
	EXPECT_FALSE( object_handle.IsValid() );
};

TEST( TestObjectHandle, CopyFromClassHandle )
{
	const Jni::Class class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );

	Jni::Object object_handle{ class_handle };
	EXPECT_TRUE( object_handle.IsValid() );
};

TEST( TestObjectHandle, MoveFromClassHandle )
{
	Jni::Class class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );

	Jni::Object object_handle{ std::move( class_handle ) };
	EXPECT_TRUE( object_handle.IsValid() );
	EXPECT_FALSE( class_handle.IsValid() );
};

TEST( TestObjectHandle, CopyValid )
{
	const Jni::Object object_handle1{ Jni::Object::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle1.IsValid() );

	Jni::Object object_handle2{ object_handle1 };
	EXPECT_TRUE( object_handle2.IsValid() );
	EXPECT_TRUE( object_handle1.IsValid() );
};

TEST( TestObjectHandle, MoveValid )
{
	Jni::Object object_handle1{ Jni::Object::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle1.IsValid() );

	Jni::Object object_handle2{ std::move( object_handle1 ) };
	EXPECT_TRUE( object_handle2.IsValid() );
	EXPECT_FALSE( object_handle1.IsValid() );
};

TEST( TestObjectHandle, GetClassHandle )
{
	Jni::Object object_handle{ Jni::Object::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle.IsValid() );
	EXPECT_TRUE( object_handle.GetClass().IsValid() );
};

TEST( TestObjectHandle, GetReference )
{
	Jni::Object object_handle{ Jni::Object::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle.IsValid() );
	EXPECT_NE( nullptr, *object_handle );
};
