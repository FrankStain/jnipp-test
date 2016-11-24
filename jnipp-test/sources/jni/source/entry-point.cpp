// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp)
// Apache 2.0 License
#include <main.h>

#define _ENTRY_POINT_LOGS

#if( defined( _ENTRY_POINT_LOGS ) )
	#include <android/log.h>
	#define LOG_DBG( FORMAT, ... )	__android_log_print( ANDROID_LOG_DEBUG, "AndroidBridge", FORMAT, ##__VA_ARGS__ )
#else
	#define LOG_DBG( FORMAT, ... )
#endif


extern "C"
{
	JNIEXPORT jint JNICALL JNI_OnLoad( JavaVM* vm, void* reserved )
	{
		LOG_DBG( "Attempt to initialize Jni++." );
		CRET_E( !jnipp::VirtualMachine::Initialize( vm ), -1, "Failed to initialize Jni++ interface." );

		LOG_DBG( "Jni++ initialized." );
		return jnipp::VirtualMachine::JNI_VERSION;
	};

	JNIEXPORT void JNICALL JNI_OnUnload( JavaVM* vm, void* reserved )
	{																				   
		jnipp::VirtualMachine::Finalize();
		LOG_DBG( "Jni++ finalized." );
	};
};
