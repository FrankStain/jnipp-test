// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestObjectHandle, EmptyIsValid )
{
	Jni::ObjectHandle object_handle;

	EXPECT_FALSE( object_handle.IsValid() );
};

TEST( TestObjectHandle, NewObject )
{
	Jni::ObjectHandle object_handle;

	EXPECT_FALSE( object_handle.IsValid() );

	object_handle = Jni::ObjectHandle::NewObject( { "java/lang/String" } );

	EXPECT_TRUE( object_handle.IsValid() );
};

TEST( TestObjectHandle, Invalidate )
{
	Jni::ObjectHandle object_handle{ Jni::ObjectHandle::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle.IsValid() );

	object_handle.Invalidate();
	EXPECT_FALSE( object_handle.IsValid() );
};

TEST( TestObjectHandle, CopyFromClassHandle )
{
	const Jni::ClassHandle class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );

	Jni::ObjectHandle object_handle{ class_handle };
	EXPECT_TRUE( object_handle.IsValid() );
};

TEST( TestObjectHandle, MoveFromClassHandle )
{
	Jni::ClassHandle class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );

	Jni::ObjectHandle object_handle{ std::move( class_handle ) };
	EXPECT_TRUE( object_handle.IsValid() );
	EXPECT_FALSE( class_handle.IsValid() );
};

TEST( TestObjectHandle, CopyValid )
{
	const Jni::ObjectHandle object_handle1{ Jni::ObjectHandle::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle1.IsValid() );

	Jni::ObjectHandle object_handle2{ object_handle1 };
	EXPECT_TRUE( object_handle2.IsValid() );
	EXPECT_TRUE( object_handle1.IsValid() );
};

TEST( TestObjectHandle, MoveValid )
{
	Jni::ObjectHandle object_handle1{ Jni::ObjectHandle::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle1.IsValid() );

	Jni::ObjectHandle object_handle2{ std::move( object_handle1 ) };
	EXPECT_TRUE( object_handle2.IsValid() );
	EXPECT_FALSE( object_handle1.IsValid() );
};

TEST( TestObjectHandle, GetClassHandle )
{
	Jni::ObjectHandle object_handle{ Jni::ObjectHandle::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle.IsValid() );
	EXPECT_TRUE( object_handle.GetClassHandle().IsValid() );
};

TEST( TestObjectHandle, GetReference )
{
	Jni::ObjectHandle object_handle{ Jni::ObjectHandle::NewObject( { "java/lang/String" } ) };

	EXPECT_TRUE( object_handle.IsValid() );
	EXPECT_NE( nullptr, *object_handle );
};
