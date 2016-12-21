// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#pragma once


#define DECLARE_MEMBER_FIELD_TEST_ENV( TYPE, NAME )													\
	Jni::Class class_handle{ "com/pfs/jnipptest/TestFieldStorage" };								\
																									\
	Jni::MemberField<TYPE>	field{ class_handle, "m_" NAME "_field" };								\
	Jni::Object				test_object{ Jni::Object::NewObject( class_handle ) };					\
																									\
	EXPECT_TRUE( field );																			\
	EXPECT_TRUE( test_object )

#define DECLARE_STATIC_FIELD_TEST_ENV( TYPE, NAME )													\
	Jni::Class class_handle{ "com/pfs/jnipptest/TestStaticFieldStorage" };							\
																									\
	Jni::StaticField<TYPE>	field{ class_handle, NAME "_field" };									\
	EXPECT_TRUE( field );																			\
																									\
	Jni::StaticFunction<void> reset_func{ class_handle, "Reset" };									\
	reset_func.Call()

#define DECLARE_MEMBER_FUNCTION_TEST_ENV( NAME, RET, ... )											\
	Jni::Class basic_class{ "com/pfs/jnipptest/TestFunctionContainer" };							\
																									\
	Jni::MemberFunction<RET, ##__VA_ARGS__>	func{ basic_class, NAME };								\
	Jni::MemberField<bool>					call_check{ basic_class, "m_is_called" };				\
	Jni::Object								test_object{ Jni::Object::NewObject( basic_class ) };	\
																									\
	EXPECT_TRUE( func );																			\
	EXPECT_TRUE( call_check );																		\
	EXPECT_TRUE( test_object )

#define DECLARE_MEMBER_NONVIRTUAL_FUNCTION_TEST_ENV( NAME, RET, ... )								\
	Jni::Class derived_class{ "com/pfs/jnipptest/TestFunctionDerivedContainer" };					\
	Jni::Class basic_class{ derived_class.GetParentClass() };										\
																									\
	Jni::MemberFunction<RET, ##__VA_ARGS__>	func{ basic_class, NAME };								\
	Jni::MemberField<bool>					call_check{ basic_class, "m_is_called" };				\
	Jni::Object								test_object{ Jni::Object::NewObject( derived_class ) };	\
																									\
	EXPECT_TRUE( func );																			\
	EXPECT_TRUE( call_check );																		\
	EXPECT_TRUE( test_object )

#define EXAMINE_MEMBER_FUNCTION_CALL_FLAG( ... )													\
	{																								\
		bool is_called = false;																		\
		EXPECT_TRUE( call_check.GetValue( test_object, is_called ) );								\
		EXPECT_TRUE( is_called );																	\
	}

#define DECLARE_STATIC_FUNCTION_TEST_ENV( NAME, RET, ... )											\
	Jni::Class class_handle{ "com/pfs/jnipptest/TestStaticFunctionContainer" };						\
																									\
	Jni::StaticFunction<RET, ##__VA_ARGS__>	func{ class_handle, NAME };								\
	Jni::StaticField<bool>					call_check{ class_handle, "is_called" };				\
																									\
	EXPECT_TRUE( func );																			\
	EXPECT_TRUE( call_check );																		\
	EXPECT_TRUE( call_check.SetValue( false ) )

#define EXAMINE_STATIC_FUNCTION_CALL_FLAG( ... )													\
	{																								\
		bool is_called = false;																		\
		EXPECT_TRUE( call_check.GetValue( is_called ) );											\
		EXPECT_TRUE( is_called );																	\
	}
