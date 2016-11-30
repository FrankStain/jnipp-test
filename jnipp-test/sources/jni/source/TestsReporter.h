// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#pragma once

#include <main.h>
#include <gtest/gtest.h>

#include "NativeTestsRunner.h"


class TestsReporter final : public testing::TestEventListener
{
public:
	TestsReporter( NativeTestsRunner* runner );


	// Fired before any test activity starts.
	virtual void OnTestProgramStart( const testing::UnitTest& unit_test ) override;

	// Fired before each iteration of tests starts.  There may be more than
	// one iteration if GTEST_FLAG(repeat) is set. iteration is the iteration
	// index, starting from 0.
	virtual void OnTestIterationStart( const testing::UnitTest& unit_test, int iteration ) override;

	// Fired before environment set-up for each iteration of tests starts.
	virtual void OnEnvironmentsSetUpStart( const testing::UnitTest& unit_test ) override;

	// Fired after environment set-up for each iteration of tests ends.
	virtual void OnEnvironmentsSetUpEnd( const testing::UnitTest& unit_test ) override;

	// Fired before the test case starts.
	virtual void OnTestCaseStart( const testing::TestCase& test_case ) override;

	// Fired before the test starts.
	virtual void OnTestStart( const testing::TestInfo& test_info ) override;

	// Fired after a failed assertion or a SUCCEED() invocation.
	virtual void OnTestPartResult( const testing::TestPartResult& test_part_result ) override;

	// Fired after the test ends.
	virtual void OnTestEnd( const testing::TestInfo& test_info ) override;

	// Fired after the test case ends.
	virtual void OnTestCaseEnd( const testing::TestCase& test_case ) override;

	// Fired before environment tear-down for each iteration of tests starts.
	virtual void OnEnvironmentsTearDownStart( const testing::UnitTest& unit_test ) override;

	// Fired after environment tear-down for each iteration of tests ends.
	virtual void OnEnvironmentsTearDownEnd( const testing::UnitTest& unit_test ) override;

	// Fired after each iteration of tests finishes.
	virtual void OnTestIterationEnd( const testing::UnitTest& unit_test, int iteration ) override;

	// Fired after all test activities have ended.
	virtual void OnTestProgramEnd( const testing::UnitTest& unit_test ) override;

private:
	NativeTestsRunner*	m_runner = nullptr;
};
