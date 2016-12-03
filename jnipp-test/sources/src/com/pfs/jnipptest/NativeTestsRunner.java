package com.pfs.jnipptest;


import android.app.Activity;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.HashMap;

import nothing.R;

final class NativeTestsRunner
{
	NativeTestsRunner( Activity host_activity )
	{
		m_activity = host_activity;
		ListView results_list = (ListView)m_activity.findViewById( R.id.lv_tests );
		m_results_adapter = new TestResultsAdapter( m_activity, m_results );
		results_list.setAdapter( m_results_adapter );
	}

	void OnTestStarted( final String test_name )
	{
		m_activity.runOnUiThread( new Runnable()
		{
			@Override
			public void run()
			{
				TestResult test_result = new TestResult( test_name );
				m_results.add( test_result );
				m_indexed_results.put( test_name, test_result );
				m_results_adapter.notifyDataSetChanged();
			}
		} );
	}

	void OnTestMessage( final String test_name, final String test_message )
	{
		m_activity.runOnUiThread( new Runnable()
		{
			@Override
			public void run()
			{
				TestResult test_result = m_indexed_results.get( test_name );
				if( test_result == null )
				{
					return;
				}

				test_result.DispatchLog( test_message );
				m_results_adapter.notifyDataSetChanged();
			}
		} );
	}

	void OnTestFinished( final String test_name, final boolean is_passed )
	{
		m_activity.runOnUiThread( new Runnable()
		{
			@Override
			public void run()
			{
				TestResult test_result = m_indexed_results.get( test_name );
				if( test_result == null )
				{
					return;
				}

				test_result.DispatchLog( String.format( "Test is passed : %b.", is_passed ) );
				test_result.Finish();
				m_results_adapter.notifyDataSetChanged();
			}
		} );
	}

	native void StartTests();

	private Activity m_activity = null;
	private TestResultsAdapter m_results_adapter = null;
	private ArrayList<TestResult> m_results = new ArrayList<>();
	private HashMap<String, TestResult> m_indexed_results = new HashMap<>();
}
