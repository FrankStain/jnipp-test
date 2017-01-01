// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
package com.pfs.jnipptest;


final class TestArrayStorage
{
	void SetStringArray( String[] string_array )
	{
		m_string_in_array = string_array;
	}

	String[] GetStringArray()
	{
		return m_string_in_array;
	}


	private boolean[] m_bool_out_array	= new boolean[]{
		true, false, true, true, false, true, false, true,
		true, false, true, true, false, true, false, true,
		true, false, true, true, false, true, false, true,
		true, false, true, true, false, true, false, true,
	};

	private boolean[] m_bool_in_array	= null;

	private int[] m_int_in_array		= null;

	private String[] m_string_in_array	= null;
}
