// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#pragma once

#include <main.h>
#include <thread>


class NativeTestsRunner final
{
public:
	static const bool RegisterNatives();

	void OnTestStarted( const char* case_name, const char* test_name );
	void OnTestMessage( const char* case_name, const char* test_name, const char* message );
	void OnTestFinished( const char* case_name, const char* test_name, bool is_passed );

private:
	static void StartTests( JNIEnv* local_env, jobject local_object_ref );

	void ThreadMain();

	inline const std::string GetTestName( const char* case_name, const char* test_name ) const
	{
		return std::string{ case_name } + " : " + test_name;
	};

private:
	std::thread			m_thread;

	Jni::Object	m_object;
	Jni::Class	m_object_class	= { "com/pfs/jnipptest/NativeTestsRunner" };

	Jni::MemberFunction<void, std::string>				m_on_test_started	= { m_object_class, "OnTestStarted" };
	Jni::MemberFunction<void, std::string, std::string>	m_on_test_message	= { m_object_class, "OnTestMessage" };
	Jni::MemberFunction<void, std::string, bool>		m_on_test_finished	= { m_object_class, "OnTestFinished" };
};
