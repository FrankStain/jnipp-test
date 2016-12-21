// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
package com.pfs.jnipptest;


final class TestStaticFieldStorage
{
	static void Reset() {
		bool_field		= true;
		string_field	= "Jni++";
		float_field		= 13.0f;
		double_field	= 42.0;
		byte_field		= 28;
		char_field		= 'S';
		short_field		= 24;
		int_field		= 65536;
		long_field		= 1L << 48;
	}

	private static boolean	bool_field		= true;
	private static String	string_field	= "Jni++";
	private static float	float_field		= 13.0f;
	private static double	double_field	= 42.0;
	private static byte		byte_field		= 28;
	private static char		char_field		= 'S';
	private static short	short_field		= 24;
	private static int		int_field		= 65536;
	private static long		long_field		= 1L << 48;
}
