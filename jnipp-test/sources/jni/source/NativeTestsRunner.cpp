// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include "NativeTestsRunner.h"


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
	jnipp::logging::Verbose( "Jni++ tests here." );
};
