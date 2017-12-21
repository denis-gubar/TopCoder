using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class WhatSort
{
	public string sortType( string[] name, int[] age, int[] wt )
	{
		bool nwa = true;
		bool naw = true;
		bool wan = true;
		bool wna = true;
		bool awn = true;
		bool anw = true;
		for( int i = 1; i < name.Length; i++ )
		{
			bool n0 = name[i - 1].CompareTo( name[i] ) == 0;
			bool n1 = name[i - 1].CompareTo( name[i] ) < 0;
			bool a0 = age[i - 1].CompareTo( age[i] ) == 0;
			bool a1 = age[i - 1].CompareTo( age[i] ) < 0;
			bool w0 = wt[i - 1].CompareTo( wt[i] ) == 0;
			bool w1 = wt[i - 1].CompareTo( wt[i] ) > 0;
			nwa &= n1 || (n0 && (w1 || (w0 && (a0 || a1))));
			naw &= n1 || (n0 && (a1 || (a0 && (w0 || w1))));
			wan &= w1 || (w0 && (a1 || (a0 && (n0 || a1))));
			wna &= w1 || (w0 && (n1 || (n0 && (a0 || a1))));
			awn &= a1 || (a0 && (w1 || (w0 && (n0 || n1))));
			anw &= a1 || (a0 && (n1 || (n0 && (w0 || w1))));
		}
		int count = 0;
		count += nwa ? 1 : 0;
		count += naw ? 1 : 0;
		count += wan ? 1 : 0;
		count += wna ? 1 : 0;
		count += awn ? 1 : 0;
		count += anw ? 1 : 0;
		if ( count > 1 ) return "IND";
		if ( nwa ) return "NWA";
		if ( naw ) return "NAW";
		if ( wan ) return "WAN";
		if ( wna ) return "WNA";
		if ( awn ) return "AWN";
		if ( anw ) return "ANW";
		return "NOT";
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new WhatSort()).sortType(new String[] {"BOB","BOB","DAVE","JOE"}, new int[] {22, 35, 35, 30}, new int[]  {122, 122, 195,  200}),"IND");
		eq(2,(new WhatSort()).sortType(new String[] {"BOB","BOB","DAVE","DAVE"}, new int[] {22, 35, 35, 30}, new int[]  {122, 122, 195,  200}),"NOT");
		eq(3,(new WhatSort()).sortType(new String[] {"BOB","BOB","DAVE","DAVE"}, new int[]  {22, 35, 35, 30}, new int[] {122, 122, 195,  190}),"NWA");
		DateTime t2 = DateTime.Now;
		TimeSpan t = t2 - t1;
		Console.WriteLine( "{0} sec", t.TotalMilliseconds / 1000 ); 
	}
	private static void eq(int n, int a, int b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, double a, double b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, char a, char b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected '"+b+"', received '"+a+"'.");
	}
	private static void eq(int n, long a, long b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, bool a, bool b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, string a, string b)
	{
		if(a == b)
			Console.WriteLine("Case "+n+" passed.");
		else
			Console.WriteLine("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
	}
	private static void eq(int n, int[] a, int[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void eq(int n, double[] a, double[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void eq(int n, long[] a, long[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void eq(int n, string[] a, string[] b)
	{
		if(a.Length != b.Length)
		{
			Console.WriteLine("Case "+n+" failed: returned "+a.Length+" elements; expected "+b.Length+" elements.");
			return;
		}
		for(int i= 0; i < a.Length; i++)
			if(a[i] != b[i])
			{
				Console.WriteLine("Case "+n+" failed. Expected and returned array differ in position "+i);
				print(b);
				print(a);
				return;
			}
		Console.WriteLine("Case "+n+" passed.");
	}
	private static void print(int a)
	{
		Console.Write(a+" ");
	}
	private static void print(string s)
	{
		Console.Write("\""+s+"\" ");
	}
	private static void print(int[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write(rs[i]);
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void print(double[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write(rs[i]);
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void print(long[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write(rs[i]);
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void print(string[] rs)
	{
		if(rs == null) return;
		Console.Write('{');
		for(int i= 0; i < rs.Length; i++)
		{
			Console.Write("\""+rs[i]+"\"");
			if(i != rs.Length-1)
				Console.Write(", ");
		}
		Console.WriteLine('}');
	}
	private static void nl()
	{
		Console.WriteLine();
	}

// END CUT HERE
}
