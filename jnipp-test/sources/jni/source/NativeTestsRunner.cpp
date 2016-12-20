// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include "NativeTestsRunner.h"
#include "TestsReporter.h"

#include <gtest/gtest.h>


const bool NativeTestsRunner::RegisterNatives()
{
	return Jni::VirtualMachine::RegisterClassNatives(
		{
			"com/pfs/jnipptest/NativeTestsRunner",
			{
				{ "StartTests", &NativeTestsRunner::StartTests },
			}
		}
	);
};

void NativeTestsRunner::StartTests( JNIEnv* local_env, jobject local_object_ref )
{
	Jni::Logging::Verbose( "Launching Jni++ tests." );
	std::shared_ptr<NativeTestsRunner> runner{ std::make_shared<NativeTestsRunner>() };

	runner->m_object		= local_object_ref;
	runner->m_thread		= std::thread{
		[runner]()
		{
			runner->ThreadMain();
			runner->m_thread.detach();
		}
	};

	Jni::Logging::Verbose( "Jni++ tests launched." );
};

void NativeTestsRunner::ThreadMain()
{
	const char* argv[] = { "library.so", nullptr };

	int32_t argc = ( sizeof( argv ) / sizeof( argv[0] ) ) - 1;

	testing::InitGoogleTest( &argc, const_cast<char**>( argv ) );
	testing::UnitTest::GetInstance()->listeners().Append( new TestsReporter( this ) );
	Jni::Logging::Info( "Tests result code - %d", RUN_ALL_TESTS() );
};

void NativeTestsRunner::OnTestStarted( const char* case_name, const char* test_name )
{
	m_on_test_started.Call( m_object, GetTestName( case_name, test_name ) );
};

void NativeTestsRunner::OnTestMessage( const char* case_name, const char* test_name, const char* message )
{
	m_on_test_message.Call( m_object, GetTestName( case_name, test_name ), { message } );
};

void NativeTestsRunner::OnTestFinished( const char* case_name, const char* test_name, bool is_passed )
{
	m_on_test_finished.Call( m_object, GetTestName( case_name, test_name ), is_passed );
};
