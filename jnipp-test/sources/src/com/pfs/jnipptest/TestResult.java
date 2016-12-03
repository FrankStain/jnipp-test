package com.pfs.jnipptest;


import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.ArrayList;

import nothing.R;

final class TestResult
{
	TestResult( String name )
	{
		m_name = name;
	}

	View GetView()
	{
		return m_view;
	}

	void SetView( View view )
	{
		m_view = view;

		m_progress = (ProgressBar)view.findViewById( R.id.pb_test );
		TextView caption = (TextView)view.findViewById( R.id.tv_test_name );
		m_status = (TextView)view.findViewById( R.id.tv_test_result );

		caption.setText( m_name );

		if( is_finished )
		{
			m_progress.setVisibility( View.INVISIBLE );
		}
		else
		{
			m_progress.setVisibility( View.VISIBLE );
		}

		if( m_log.size() > 0 )
		{
			m_status.setText( m_log.get( m_log.size() - 1 ) );
		}
		else
		{
			m_status.setText( "" );
		}
	}

	void DispatchLog( String message )
	{
		m_log.add( message );
		if( m_view == null )
		{
			return;
		}

		m_status.setText( message );
	}

	void Finish()
	{
		is_finished = true;
		if( m_view == null )
		{
			return;
		}

		if( is_finished )
		{
			m_progress.setVisibility( View.INVISIBLE );
		}
		else
		{
			m_progress.setVisibility( View.VISIBLE );
		}
	}

	private boolean is_finished = false;
	private String m_name = "";
	private View m_view = null;
	private ArrayList<String> m_log = new ArrayList<>();
	private ProgressBar m_progress = null;
	private TextView m_status = null;
}
