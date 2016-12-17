package com.pfs.jnipptest;


import android.util.Log;

public class TestFunctionContainer
{
	void VoidNoArguments()
	{
		Log.i( "Jni++", "TestFunctionContainer::VoidNoArguments() checkout." );
	}

	void VoidOneArgument( String arg )
	{
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s' ) checkout.", arg ) );
	}

	void VoidTwoArguments( String arg1, String arg2 )
	{
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s' ) checkout.", arg1, arg2 ) );
	}

	void VoidThreeArguments( String arg1, String arg2, String arg3 )
	{
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s', '%s' ) checkout.", arg1, arg2, arg3 ) );
	}

	String StringNoArguments()
	{
		Log.i( "Jni++", "TestFunctionContainer::VoidNoArguments() checkout." );
		return "Jni++";
	}

	String StringOneArgument( String arg )
	{
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s' ) checkout.", arg ) );
		return arg;
	}

	String StringTwoArguments( String arg1, String arg2 )
	{
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s' ) checkout.", arg1, arg2 ) );
		return String.format( "%s %s", arg1, arg2 );
	}

	String StringThreeArguments( String arg1, String arg2, String arg3 )
	{
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s', '%s' ) checkout.", arg1, arg2, arg3 ) );
		return String.format( "%s %s %s", arg1, arg2, arg3 );
	}
}
