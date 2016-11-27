package com.pfs.jnipptest;


import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

import java.util.ArrayList;

import nothing.R;

final class TestResultsAdapter extends BaseAdapter
{

	TestResultsAdapter( Context host_context, ArrayList<TestResult> results )
	{
		m_layout_inflater	= (LayoutInflater)host_context.getSystemService( Context.LAYOUT_INFLATER_SERVICE );
		m_host_context		= host_context;
		m_results			= results;
	}

	@Override
	public int getCount()
	{
		return m_results.size();
	}

	@Override
	public Object getItem( int position )
	{
		return m_results.get( position );
	}

	@Override
	public long getItemId( int position )
	{
		return position;
	}

	@Override
	public View getView( int position, View convertView, ViewGroup parent )
	{
		TestResult result	= m_results.get( position );
		View element_view	= result.GetView();
		if( element_view != null )
		{
			return element_view;
		}

		element_view = m_layout_inflater.inflate( R.layout.testsuite_layout, parent, false );
		result.SetView( element_view );
		element_view.setTag( position );
		return element_view;
	}

	private LayoutInflater m_layout_inflater = null;
	private Context m_host_context = null;
	private ArrayList<TestResult> m_results = null;
}
