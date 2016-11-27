// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp)
// Apache 2.0 License
#pragma once

#include <main.h>
#include <thread>


class NativeTestsRunner final
{
public:
	static const bool RegisterNatives();

private:
	static void StartTests();

	static void ThreadRoutine( std::shared_ptr<NativeTestsRunner> runner );

private:
	std::thread	m_thread;
};
