// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
package com.pfs.jnipptest;


import android.util.Log;

class TestStaticFunctionContainer
{
	static void VoidNoArguments()
	{
		is_called = true;
		Log.i( "Jni++", "static TestStaticFunctionContainer::VoidNoArguments() checkpoint." );
	}

	static void VoidOneArgument( String arg )
	{
		is_called = true;
		Log.i( "Jni++", String.format( "static TestStaticFunctionContainer::VoidOneArgument( '%s' ) checkpoint.", arg ) );
	}

	static void VoidTwoArguments( String arg1, String arg2 )
	{
		is_called = true;
		Log.i( "Jni++", String.format( "static TestStaticFunctionContainer::VoidOneArgument( '%s', '%s' ) checkpoint.", arg1, arg2 ) );
	}

	static void VoidThreeArguments( String arg1, String arg2, String arg3 )
	{
		is_called = true;
		Log.i( "Jni++", String.format( "static TestStaticFunctionContainer::VoidOneArgument( '%s', '%s', '%s' ) checkpoint.", arg1, arg2, arg3 ) );
	}

	static String StringNoArguments()
	{
		is_called = true;
		Log.i( "Jni++", "static TestStaticFunctionContainer::VoidNoArguments() checkpoint." );
		return "Jni++";
	}

	static String StringOneArgument( String arg )
	{
		is_called = true;
		Log.i( "Jni++", String.format( "static TestStaticFunctionContainer::VoidOneArgument( '%s' ) checkpoint.", arg ) );
		return arg;
	}

	static String StringTwoArguments( String arg1, String arg2 )
	{
		is_called = true;
		Log.i( "Jni++", String.format( "static TestStaticFunctionContainer::VoidOneArgument( '%s', '%s' ) checkpoint.", arg1, arg2 ) );
		return String.format( "%s %s", arg1, arg2 );
	}

	static String StringThreeArguments( String arg1, String arg2, String arg3 )
	{
		is_called = true;
		Log.i( "Jni++", String.format( "static TestStaticFunctionContainer::VoidOneArgument( '%s', '%s', '%s' ) checkpoint.", arg1, arg2, arg3 ) );
		return String.format( "%s %s %s", arg1, arg2, arg3 );
	}

	private static boolean is_called = false;
}
