// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include "TestsReporter.h"


TestsReporter::TestsReporter( NativeTestsRunner* runner )
	: m_runner( runner )
{
	JNI_EXPECTS( runner != nullptr )
};

void TestsReporter::OnTestProgramStart( const testing::UnitTest& unit_test )
{
	Jni::Logging::Verbose( "Tests started." );
};

void TestsReporter::OnTestIterationStart( const testing::UnitTest& unit_test, int iteration )
{
	JNI_RETURN_IF( iteration < 2 );
	Jni::Logging::Verbose( "Tests iteration : %d.", iteration );
};

void TestsReporter::OnEnvironmentsSetUpStart( const testing::UnitTest& unit_test )
{
	Jni::Logging::Verbose( "Global test environment set-up started." );
};

void TestsReporter::OnEnvironmentsSetUpEnd( const testing::UnitTest& unit_test )
{
	Jni::Logging::Verbose( "Global test environment set-up finished." );
};

void TestsReporter::OnTestCaseStart( const testing::TestCase& test_case )
{
	const char* test_case_param = ( test_case.type_param() != nullptr )? test_case.type_param() : "n/a";
	Jni::Logging::Verbose( "[T] %d test(s) from %s with argument `%s`.", test_case.test_to_run_count(), test_case.name(), test_case_param );
};

void TestsReporter::OnTestStart( const testing::TestInfo& test_info )
{
	Jni::Logging::Verbose( "[ ] %s:%s", test_info.test_case_name(), test_info.name() );
	m_runner->OnTestStarted( test_info.test_case_name(), test_info.name() );
};

void TestsReporter::OnTestPartResult( const testing::TestPartResult& test_part_result )
{
	static const char* RESULT_TYPE_NAMES[] = { "success", "test failed", "case failed" };
		
	JNI_RETURN_IF( test_part_result.type() == testing::TestPartResult::kSuccess );
	const char* file_location = ( test_part_result.file_name() )? test_part_result.file_name() : "unknown file";
	Jni::Logging::Warning(
		"%s(%d): `%s` - %s",
		file_location, test_part_result.line_number(),
		RESULT_TYPE_NAMES[ test_part_result.type() ],
		test_part_result.message()
	);
};

void TestsReporter::OnTestEnd( const testing::TestInfo& test_info )
{
	if( test_info.result()->Passed() )
	{
		Jni::Logging::Info( "[+] %s:%s", test_info.test_case_name(), test_info.name() );
	}
	else
	{
		if( ( test_info.type_param() != nullptr ) || ( test_info.value_param() != nullptr ) )
		{
			const char* type_param	= ( test_info.type_param() != nullptr )? test_info.type_param() : "none";
			const char* value_param	= ( test_info.value_param() != nullptr )? test_info.value_param() : "none";
				
			Jni::Logging::Error( "Type argument == `%s`; Value == `%s`", type_param, value_param );
		};

		Jni::Logging::Error( "[-] %s:%s", test_info.test_case_name(), test_info.name() );
	};

	m_runner->OnTestFinished( test_info.test_case_name(), test_info.name(), test_info.result()->Passed() );
};

void TestsReporter::OnTestCaseEnd( const testing::TestCase& test_case )
{
	Jni::Logging::Verbose( "[T] %s case finished; %d good; %d bad.", test_case.name(), test_case.successful_test_count(), test_case.failed_test_count() );
};

void TestsReporter::OnEnvironmentsTearDownStart( const testing::UnitTest& unit_test )
{
	Jni::Logging::Verbose( "Global test environment tear-down started." );
};

void TestsReporter::OnEnvironmentsTearDownEnd( const testing::UnitTest& unit_test )
{
	Jni::Logging::Verbose( "Global test environment tear-down finished." );
};

void TestsReporter::OnTestIterationEnd( const testing::UnitTest& unit_test, int iteration )
{
	Jni::Logging::Verbose( 
		"%d from %d ran; %d succeeded.",
		unit_test.test_to_run_count(),
		unit_test.test_case_to_run_count(),
		unit_test.successful_test_count()
	);
};

void TestsReporter::OnTestProgramEnd( const testing::UnitTest& unit_test )
{
	Jni::Logging::Verbose( "Tests finished." );
};
