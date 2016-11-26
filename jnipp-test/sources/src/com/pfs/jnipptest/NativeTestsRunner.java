package com.pfs.jnipptest;


import android.app.Activity;

final class NativeTestsRunner
{
	public NativeTestsRunner( Activity host_activity ) {
		m_activity = host_activity;
	}

	public native void StartTests();

	private Activity m_activity = null;
}
