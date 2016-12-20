// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include "NativeTestsRunner.h"


extern "C"
{
	JNIEXPORT jint JNICALL JNI_OnLoad( JavaVM* vm, void* reserved )
	{
		jnipp::logging::Debug( "Attempt to initialize Jni++." );
		JNI_RETURN_IF_E( !jnipp::VirtualMachine::Initialize( vm ), JNI_ERR, "Failed to initialize Jni++ interface." );
		JNI_RETURN_IF_E( !NativeTestsRunner::RegisterNatives(), JNI_ERR, "Failed to register natives for `NativeTestsRunner`." );

		jnipp::logging::Debug( "Jni++ initialized." );
		return jnipp::VirtualMachine::JNI_VERSION;
	};

	JNIEXPORT void JNICALL JNI_OnUnload( JavaVM* vm, void* reserved )
	{
		jnipp::VirtualMachine::Finalize();
		jnipp::logging::Debug( "Jni++ finalized." );
	};
};
