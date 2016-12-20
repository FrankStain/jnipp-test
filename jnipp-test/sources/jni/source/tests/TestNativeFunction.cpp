// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


template< typename TReturnType, typename... TArgumentTypes >
using JniMemberFunction = TReturnType (*)( JNIEnv*, jobject, TArgumentTypes... );

template< typename TReturnType, typename... TArgumentTypes >
using JniStaticFunction = TReturnType (*)( JNIEnv*, jclass, TArgumentTypes... );


#define DECLARE_TEST_MEMBER_FUNC( FUNC_RESULT, ... )									\
Jni::NativeFunction func{																\
	"test_func",																		\
	JniMemberFunction<FUNC_RESULT, ##__VA_ARGS__>{										\
		[]( JNIEnv*, jobject, ##__VA_ARGS__ ) -> FUNC_RESULT { return FUNC_RESULT(); }	\
	}																					\
}


TEST( TestNativeFunction, SignatureVoidNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( void );
	EXPECT_STREQ( "()V", func.signature );
};

TEST( TestNativeFunction, SignatureBooleanNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jboolean );
	EXPECT_STREQ( "()Z", func.signature );
};

TEST( TestNativeFunction, SignatureStringNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jstring );
	EXPECT_STREQ( "()Ljava/lang/String;", func.signature );
};

TEST( TestNativeFunction, SignatureFloatNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jfloat );
	EXPECT_STREQ( "()F", func.signature );
};

TEST( TestNativeFunction, SignatureDoubleNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jdouble );
	EXPECT_STREQ( "()D", func.signature );
};

TEST( TestNativeFunction, SignatureByteNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jbyte );
	EXPECT_STREQ( "()B", func.signature );
};

TEST( TestNativeFunction, SignatureCharNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jchar );
	EXPECT_STREQ( "()C", func.signature );
};

TEST( TestNativeFunction, SignatureShortNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jshort );
	EXPECT_STREQ( "()S", func.signature );
};

TEST( TestNativeFunction, SignatureIntNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jint );
	EXPECT_STREQ( "()I", func.signature );
};

TEST( TestNativeFunction, SignatureLongNoArgs )
{
	DECLARE_TEST_MEMBER_FUNC( jlong );
	EXPECT_STREQ( "()J", func.signature );
};

TEST( TestNativeFunction, SignatureVoidWithArgs )
{
	DECLARE_TEST_MEMBER_FUNC( void, jint, jstring, jlong );
	EXPECT_STREQ( "(ILjava/lang/String;J)V", func.signature );
};
