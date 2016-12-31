// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestStaticString, GetString )
{
	using TestString = Jni::StaticString<'t', 'e', 's', 't', '_', 's', 't', 'r', 'i', 'n', 'g'>;

	EXPECT_STREQ( "test_string", TestString::GetString() );
};

TEST( TestStaticString, CombineStrings )
{
	auto test_string = Jni::CombinedStaticString<Jni::StaticString<'J'>, Jni::StaticString<'n'>, Jni::StaticString<'i'>, Jni::StaticString<'+', '+'>>::GetString();

	EXPECT_STREQ( "Jni++", test_string );
};

TEST( TestStaticString, ClassName )
{
	auto test_string = Jni::ClassName<'a', '/', 'b', '/', 'c'>::GetString();

	EXPECT_STREQ( "La/b/c;", test_string );
};

TEST( TestStaticString, ArrayName )
{
	auto test_string = Jni::ArrayName<Jni::ClassName<'a', '/', 'b', '/', 'c'>>::GetString();

	EXPECT_STREQ( "[La/b/c;", test_string );
};

TEST( TestStaticString, ClassPath )
{
	auto test_string = Jni::ClassPath<Jni::ClassName<'a', '/', 'b', '/', 'c'>>::GetString();

	EXPECT_STREQ( "a/b/c", test_string );
};

TEST( TestStaticString, ArrayClassPath )
{
	auto test_string = Jni::ClassPath<Jni::ArrayName<Jni::ClassName<'a', '/', 'b', '/', 'c'>>>::GetString();

	EXPECT_STREQ( "[La/b/c;", test_string );
};
