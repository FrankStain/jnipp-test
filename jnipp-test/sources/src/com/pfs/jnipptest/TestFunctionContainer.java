// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
package com.pfs.jnipptest;


import android.util.Log;

class TestFunctionContainer
{
	void VoidNoArguments()
	{
		m_is_called = true;
		Log.i( "Jni++", "TestFunctionContainer::VoidNoArguments() checkpoint." );
	}

	void VoidOneArgument( String arg )
	{
		m_is_called = true;
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s' ) checkpoint.", arg ) );
	}

	void VoidTwoArguments( String arg1, String arg2 )
	{
		m_is_called = true;
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s' ) checkpoint.", arg1, arg2 ) );
	}

	void VoidThreeArguments( String arg1, String arg2, String arg3 )
	{
		m_is_called = true;
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s', '%s' ) checkpoint.", arg1, arg2, arg3 ) );
	}

	String StringNoArguments()
	{
		m_is_called = true;
		Log.i( "Jni++", "TestFunctionContainer::VoidNoArguments() checkpoint." );
		return "Jni++";
	}

	String StringOneArgument( String arg )
	{
		m_is_called = true;
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s' ) checkpoint.", arg ) );
		return arg;
	}

	String StringTwoArguments( String arg1, String arg2 )
	{
		m_is_called = true;
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s' ) checkpoint.", arg1, arg2 ) );
		return String.format( "%s %s", arg1, arg2 );
	}

	String StringThreeArguments( String arg1, String arg2, String arg3 )
	{
		m_is_called = true;
		Log.i( "Jni++", String.format( "TestFunctionContainer::VoidOneArgument( '%s', '%s', '%s' ) checkpoint.", arg1, arg2, arg3 ) );
		return String.format( "%s %s %s", arg1, arg2, arg3 );
	}

	private boolean m_is_called = false;
}
