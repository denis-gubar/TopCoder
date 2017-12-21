using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;
 
public class Sets
{
	public int[] operate( int[] A, int[] B, string operation )
	{
		ArrayList a = new ArrayList();
		ArrayList b = new ArrayList();
		ArrayList r = new ArrayList();
		for( int i = 0; i < A.Length; i++ )
		{
			if ( !a.Contains( A[i] ) ) a.Add( A[i] );
		}
		for( int i = 0; i < B.Length; i++ )
		{
			if ( !b.Contains( B[i] ) ) b.Add( B[i] );
		}
		switch( operation )
		{
			case "INTERSECTION":
				for( int i = 0; i < a.Count; i++ )
				{
					if ( !r.Contains( a[i] ) && b.Contains( a[i] ) ) r.Add( a[i] );
				}
				break;
			case "UNION":
				for( int i = 0; i < a.Count; i++ )
				{
					if ( !r.Contains( a[i] ) ) r.Add( a[i] );
				}
				for( int i = 0; i < b.Count; i++ )
				{
					if ( !r.Contains( b[i] ) ) r.Add( b[i] );
				}
				break;
			case "SYMMETRIC DIFFERENCE":
				for( int i = 0; i < a.Count; i++ )
				{
					if ( !r.Contains( a[i] ) && !b.Contains( a[i] ) ) r.Add( a[i] );
				}
				for( int i = 0; i < b.Count; i++ )
				{
					if ( !r.Contains( b[i] ) && !a.Contains( b[i] )  ) r.Add( b[i] );
				}
				break;
		}
		int[] result = new int[r.Count];
		for( int i = 0; i < r.Count; i++ )
		{
			result[i] = (int) r[i];
		}
		Array.Sort( result );
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Sets()).operate(new int[] {1,2,3,4}, new int[] {3,4,5,6}, "INTERSECTION"),new int[] { 3,  4 });
		eq(2,(new Sets()).operate(new int[] {1,2,3,4}, new int[] {3,4,5,6}, "UNION"),new int[] { 1,  2,  3,  4,  5,  6 });
		eq(3,(new Sets()).operate(new int[] {432,756,123}, new int[] {534,76,1209}, "INTERSECTION"),new int[] { });
		eq(4,(new Sets()).operate(new int[] {6,5,7,4}, new int[] {7,6,4,10}, "SYMMETRIC DIFFERENCE"),new int[] { 5,  10 });
		eq(5,(new Sets()).operate(new int[] {342,654,897,312,76,23,78}, new int[] {21,43,87,98,23,756,897,234,645,876,123}, "SYMMETRIC DIFFERENCE"),new int[] { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 });
		DateTime t2 = DateTime.Now;
		TimeSpan t = t2 - t1;
		Console.WriteLine( t.TotalMilliseconds / 1000 );
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
