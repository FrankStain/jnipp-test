// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include "NativeTestsRunner.h"


extern "C"
{
	JNIEXPORT jint JNICALL JNI_OnLoad( JavaVM* vm, void* reserved )
	{
		Jni::Logging::Debug( "Attempt to initialize Jni++." );
		JNI_RETURN_IF_E( !Jni::VirtualMachine::Initialize( vm ), JNI_ERR, "Failed to initialize Jni++ interface." );
		JNI_RETURN_IF_E( !NativeTestsRunner::RegisterNatives(), JNI_ERR, "Failed to register natives for `NativeTestsRunner`." );

		Jni::Logging::Debug( "Jni++ initialized." );
		return Jni::VirtualMachine::JNI_VERSION;
	};

	JNIEXPORT void JNICALL JNI_OnUnload( JavaVM* vm, void* reserved )
	{
		Jni::VirtualMachine::Finalize();
		Jni::Logging::Debug( "Jni++ finalized." );
	};
};
