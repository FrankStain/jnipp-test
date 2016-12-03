// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


template< typename TReturnType, typename... TArgumentTypes >
using JniMemberFunction = TReturnType (*)( JNIEnv*, jobject, TArgumentTypes... );

template< typename TReturnType, typename... TArgumentTypes >
using JniStaticFunction = TReturnType (*)( JNIEnv*, jclass, TArgumentTypes... );


#define DECLARE_TEST_MEMBER_FUNC( FUNC_RESULT, ... )									\
jnipp::NativeFunction func{																\
	"test_func",																		\
	JniMemberFunction<FUNC_RESULT, ##__VA_ARGS__>{										\
		[]( JNIEnv*, jobject, ##__VA_ARGS__ ) -> FUNC_RESULT { return FUNC_RESULT(); }	\
	}																					\
}


TEST( TestNativeFunction, VoidNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( void );
	EXPECT_STREQ( "()V", func.signature.c_str() );
};

TEST( TestNativeFunction, BooleanNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jboolean );
	EXPECT_STREQ( "()Z", func.signature.c_str() );
};

TEST( TestNativeFunction, StringNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jstring );
	EXPECT_STREQ( "()Ljava/lang/String;", func.signature.c_str() );
};

TEST( TestNativeFunction, FloatNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jfloat );
	EXPECT_STREQ( "()F", func.signature.c_str() );
};

TEST( TestNativeFunction, DoubleNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jdouble );
	EXPECT_STREQ( "()D", func.signature.c_str() );
};

TEST( TestNativeFunction, ByteNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jbyte );
	EXPECT_STREQ( "()B", func.signature.c_str() );
};

TEST( TestNativeFunction, CharNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jchar );
	EXPECT_STREQ( "()C", func.signature.c_str() );
};

TEST( TestNativeFunction, ShortNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jshort );
	EXPECT_STREQ( "()S", func.signature.c_str() );
};

TEST( TestNativeFunction, IntNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jint );
	EXPECT_STREQ( "()I", func.signature.c_str() );
};

TEST( TestNativeFunction, LongNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jlong );
	EXPECT_STREQ( "()L", func.signature.c_str() );
};
