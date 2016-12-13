// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
package com.pfs.jnipptest;

import android.os.Bundle;
import android.app.Activity;

import nothing.R;

public class MainActivity extends Activity
{

	@Override
	protected void onCreate( Bundle savedInstanceState )
	{
		super.onCreate( savedInstanceState );
		setContentView( R.layout.main_layout );
	}

	@Override
	protected void onResume()
	{
		super.onResume();
		if( m_test_runner != null )
		{
			return;
		}

		m_test_runner = new NativeTestsRunner( this );
		m_test_runner.StartTests();
	}

	@Override
	protected void onStop()
	{
		super.onStop();
		m_test_runner = null;
	}

	static
	{
		System.loadLibrary( "jnipp-test" );
	}

	private NativeTestsRunner m_test_runner = null;
}
