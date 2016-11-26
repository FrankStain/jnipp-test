package com.pfs.jnipptest;


import android.app.Activity;

final class NativeTestsRunner
{
	NativeTestsRunner( Activity host_activity ) {
		m_activity = host_activity;
	}

	native void StartTests();

	private Activity m_activity = null;
}
