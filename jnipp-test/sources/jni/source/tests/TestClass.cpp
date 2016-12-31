// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestClass, EmptyIsValid )
{
	Jni::Class class_handle;

	EXPECT_FALSE( class_handle.IsValid() );
};

TEST( TestClass, ConstructedIsValid )
{
	Jni::Class class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );
};

TEST( TestClass, Invalidate )
{
	Jni::Class class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );
	
	class_handle.Invalidate();
	EXPECT_FALSE( class_handle.IsValid() );
};

TEST( TestClass, AssignString )
{
	Jni::Class class_handle;

	EXPECT_FALSE( class_handle.IsValid() );

	class_handle = "java/lang/String";
	EXPECT_TRUE( class_handle.IsValid() );
};

TEST( TestClass, CopyValid )
{
	Jni::Class class_handle1;
	const Jni::Class class_handle2{ "java/lang/String" };

	EXPECT_FALSE( class_handle1.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );

	class_handle1 = class_handle2;
	EXPECT_TRUE( class_handle1.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );

	const Jni::Class class_handle3{ class_handle2 };
	EXPECT_TRUE( class_handle3.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );
};

TEST( TestClass, MoveValid )
{
	Jni::Class class_handle1;
	Jni::Class class_handle2{ "java/lang/String" };

	EXPECT_FALSE( class_handle1.IsValid() );
	EXPECT_TRUE( class_handle2.IsValid() );

	class_handle1 = std::move( class_handle2 );
	EXPECT_TRUE( class_handle1.IsValid() );
	EXPECT_FALSE( class_handle2.IsValid() );

	Jni::Class class_handle3{ std::move( class_handle1 ) };
	EXPECT_TRUE( class_handle3.IsValid() );
	EXPECT_FALSE( class_handle1.IsValid() );
};

TEST( TestClass, GetReference )
{
	Jni::Class class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );
	EXPECT_NE( nullptr, *class_handle );
};

TEST( TestClass, ValidGetName )
{
	Jni::Class class_handle{ "java/lang/String" };

	EXPECT_TRUE( class_handle.IsValid() );

	const std::string class_name{ class_handle.GetName() };
	EXPECT_STREQ( "java/lang/String", class_name.c_str() );
};

TEST( TestClass, InvalidGetName )
{
	Jni::Class class_handle;

	EXPECT_FALSE( class_handle.IsValid() );

	const std::string class_name{ class_handle.GetName() };
	EXPECT_STREQ( "", class_name.c_str() );
};

TEST( TestClass, ArrayClass )
{
	Jni::Class test_class;

	//test_class = "Ljava/lang/String;";
	//EXPECT_TRUE( test_class.IsValid() );

	//test_class = "[java/lang/String";
	//EXPECT_TRUE( test_class.IsValid() );

	test_class = "[Ljava/lang/String;";
	EXPECT_TRUE( test_class.IsValid() );

	//test_class = "[[java/lang/String";
	//EXPECT_TRUE( test_class.IsValid() );

	test_class = "[[Ljava/lang/String;";
	EXPECT_TRUE( test_class.IsValid() );
};
