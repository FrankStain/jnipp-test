// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include "NativeTestsRunner.h"
#include "TestsReporter.h"

#include <gtest/gtest.h>


const bool NativeTestsRunner::RegisterNatives()
{
	return jnipp::VirtualMachine::RegisterClassNatives(
		{
			"com/pfs/jnipptest/NativeTestsRunner",
			{
				{ "StartTests", &NativeTestsRunner::StartTests },
			}
		}
	);
};

void NativeTestsRunner::StartTests()
{
	jnipp::logging::Verbose( "Launching Jni++ tests." );
	std::shared_ptr<NativeTestsRunner> runner{ std::make_shared<NativeTestsRunner>() };

	runner->m_thread = std::thread{
		[runner]()
		{
			runner->ThreadMain();
			runner->m_thread.detach();
		}
	};

	jnipp::logging::Verbose( "Jni++ tests launched." );
};

void NativeTestsRunner::ThreadMain()
{
	const char* argv[] = { "library.so", nullptr };

	int32_t argc = sizeof( argv ) / sizeof( argv[0] );

	testing::InitGoogleTest( &argc, const_cast<char**>( argv ) );
	testing::UnitTest::GetInstance()->listeners().Append( new TestsReporter( this ) );
	jnipp::logging::Info( "Tests result code - %d", RUN_ALL_TESTS() );
};
