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

		if( m_is_finished )
		{
			m_progress.setVisibility( View.INVISIBLE );
			if( m_is_passed )
			{
				m_status.setTextColor( 0xFF00CC00 );
			}
			else
			{
				m_status.setTextColor( 0xFFCC0000 );
			}
		}
		else
		{
			m_progress.setVisibility( View.VISIBLE );
			m_status.setTextColor( 0xFFFFFFFF );
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

	void Finish( boolean is_passed )
	{
		m_is_finished	= true;
		m_is_passed		= is_passed;
		if( m_view == null )
		{
			return;
		}

		m_progress.setVisibility( View.INVISIBLE );
		if( m_is_passed )
		{
			m_status.setTextColor( 0xFF00CC00 );
		}
		else
		{
			m_status.setTextColor( 0xFFCC0000 );
		}
	}

	private boolean m_is_finished = false;
	private boolean m_is_passed	= false;
	private String m_name = "";
	private View m_view = null;
	private ArrayList<String> m_log = new ArrayList<>();
	private ProgressBar m_progress = null;
	private TextView m_status = null;
}
