// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
package com.pfs.jnipptest;


import android.util.Log;

class TestFunctionDerivedContainer extends TestFunctionContainer
{
	@Override
	void VoidNoArguments()
	{
		Log.i( "Jni++", "TestFunctionDerivedContainer::VoidNoArguments() checkpoint." );
	}

	@Override
	void VoidOneArgument( String arg )
	{
		Log.i( "Jni++", String.format( "TestFunctionDerivedContainer::VoidOneArgument( '%s' ) checkpoint.", arg ) );
	}

	@Override
	void VoidTwoArguments( String arg1, String arg2 )
	{
		Log.i( "Jni++", String.format( "TestFunctionDerivedContainer::VoidOneArgument( '%s', '%s' ) checkpoint.", arg1, arg2 ) );
	}

	@Override
	void VoidThreeArguments( String arg1, String arg2, String arg3 )
	{
		Log.i( "Jni++", String.format( "TestFunctionDerivedContainer::VoidOneArgument( '%s', '%s', '%s' ) checkpoint.", arg1, arg2, arg3 ) );
	}

	@Override
	String StringNoArguments()
	{
		Log.i( "Jni++", "TestFunctionDerivedContainer::VoidNoArguments() checkpoint." );
		return "Jni++";
	}

	@Override
	String StringOneArgument( String arg )
	{
		Log.i( "Jni++", String.format( "TestFunctionDerivedContainer::VoidOneArgument( '%s' ) checkpoint.", arg ) );
		return arg;
	}

	@Override
	String StringTwoArguments( String arg1, String arg2 )
	{
		Log.i( "Jni++", String.format( "TestFunctionDerivedContainer::VoidOneArgument( '%s', '%s' ) checkpoint.", arg1, arg2 ) );
		return String.format( "%s %s", arg1, arg2 );
	}

	@Override
	String StringThreeArguments( String arg1, String arg2, String arg3 )
	{
		Log.i( "Jni++", String.format( "TestFunctionDerivedContainer::VoidOneArgument( '%s', '%s', '%s' ) checkpoint.", arg1, arg2, arg3 ) );
		return String.format( "%s %s %s", arg1, arg2, arg3 );
	}
}
