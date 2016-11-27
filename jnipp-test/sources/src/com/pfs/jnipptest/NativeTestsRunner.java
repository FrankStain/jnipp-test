package com.pfs.jnipptest;


import android.app.Activity;
import android.widget.ListView;

import java.util.ArrayList;

import nothing.R;

final class NativeTestsRunner
{
	NativeTestsRunner( Activity host_activity ) {
		m_activity				= host_activity;
		ListView results_list	= (ListView)m_activity.findViewById( R.id.lv_tests );
		m_results_adapter		= new TestResultsAdapter( m_activity, m_results );
		results_list.setAdapter( m_results_adapter );
	}

	native void StartTests();

	private Activity m_activity = null;
	private TestResultsAdapter m_results_adapter = null;
	private ArrayList<TestResult> m_results = new ArrayList<>();
}
