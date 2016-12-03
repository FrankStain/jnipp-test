// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


template< typename TReturnType, typename... TArgumentTypes >
using JniMemberFunction = TReturnType (*)( JNIEnv*, jobject, TArgumentTypes... );

template< typename TReturnType, typename... TArgumentTypes >
using JniStaticFunction = TReturnType (*)( JNIEnv*, jclass, TArgumentTypes... );


TEST( TestNativeFunction, VoidNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<void>{ []( JNIEnv*, jobject ) -> void { ; } } };
	EXPECT_STREQ( "()V", func.signature.c_str() );
};

TEST( TestNativeFunction, BooleanNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jboolean>{ []( JNIEnv*, jobject ) -> jboolean { return JNI_TRUE; } } };
	EXPECT_STREQ( "()Z", func.signature.c_str() );
};

TEST( TestNativeFunction, StringNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jstring>{ []( JNIEnv*, jobject ) -> jstring { return nullptr; } } };
	EXPECT_STREQ( "()Ljava/lang/String;", func.signature.c_str() );
};

TEST( TestNativeFunction, FloatNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jfloat>{ []( JNIEnv*, jobject ) -> jfloat { return 0.0f; } } };
	EXPECT_STREQ( "()F", func.signature.c_str() );
};

TEST( TestNativeFunction, DoubleNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jdouble>{ []( JNIEnv*, jobject ) -> jdouble { return 0.0; } } };
	EXPECT_STREQ( "()D", func.signature.c_str() );
};

TEST( TestNativeFunction, ByteNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jbyte>{ []( JNIEnv*, jobject ) -> jbyte { return 0; } } };
	EXPECT_STREQ( "()B", func.signature.c_str() );
};

TEST( TestNativeFunction, CharNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jchar>{ []( JNIEnv*, jobject ) -> jchar { return 0; } } };
	EXPECT_STREQ( "()C", func.signature.c_str() );
};

TEST( TestNativeFunction, ShortNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jshort>{ []( JNIEnv*, jobject ) -> jshort { return 0; } } };
	EXPECT_STREQ( "()S", func.signature.c_str() );
};

TEST( TestNativeFunction, IntNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jint>{ []( JNIEnv*, jobject ) -> jint { return 0; } } };
	EXPECT_STREQ( "()I", func.signature.c_str() );
};

TEST( TestNativeFunction, LongNoArgs )
{
	jnipp::NativeFunction func{ "func", JniMemberFunction<jlong>{ []( JNIEnv*, jobject ) -> jlong { return 0; } } };
	EXPECT_STREQ( "()L", func.signature.c_str() );
};
