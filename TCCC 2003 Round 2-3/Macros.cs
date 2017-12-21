using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Macros
{
	void add( ref string s, char c )
	{
		if ( s == null || s.IndexOf( c ) == -1 ) s = s + c.ToString();
	}
	public string[] whichOnes( string[] rules, string output )
	{
		int n = output.Length;
		int m = rules.Length;
		string[,] M = new string[n, n];
		for( int i = 0; i + 2 <= n; i++ )
			for( int j = 0; j < m; j++ )
				if ( output.Substring( i, 2 ).Equals( rules[j].Substring( 2 ) ) )
					add( ref M[i, i + 1], rules[j][0] );
		for( int k = 3; k <= n; k++ )
			for( int i = 0; i + k <= n; i++ )
			{
				for( int l = 2; l < k - 1; l++ )
					if ( M[i, i + l - 1] != null && M[i + l, i + k - 1] != null )
						for( int j = 0; j < m; j++ )
							foreach( char T1 in M[i, i + l - 1] )
								if ( T1 == rules[j][2] )
									foreach( char T2 in M[i + l, i + k - 1] )
										if ( T2 == rules[j][3] )
											add( ref M[i, i + k - 1], rules[j][0] );
				if ( M[i, i + k - 2] != null )
					for( int j = 0; j < m; j++ )
						foreach( char T in M[i, i + k - 2] )
							if ( rules[j][2] == T && rules[j][3] == output[i + k - 1] )
								add( ref M[i, i + k - 1], rules[j][0] );
				if ( M[i + 1, i + k - 1] != null )
					for( int j = 0; j < m; j++ )
						foreach( char T in M[i + 1, i + k - 1] )
							if ( rules[j][3] == T && rules[j][2] == output[i] )
								add( ref M[i, i + k - 1], rules[j][0] );
			}

		if ( M[0, n - 1] == null ) return new string[] {};
		string[] result = new string[M[0, n - 1].Length];
		for( int i = 0; i < result.Length; i++ ) result[i] = M[0, n - 1][i].ToString();
		Array.Sort( result );
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Macros()).whichOnes(new String[] {"S:aA",
 "A:Sb",
 "S:ab",
 "D:aA"}, "aabb"),new String[] { "D",  "S" });
		eq(2,(new Macros()).whichOnes(new String[] {"S:aA",
 "A:Sb",
 "S:ab",
 "D:aA"}, "ab"),new String[] { "S" });
		eq(3,(new Macros()).whichOnes(new String[] {"S:aA",
 "A:Sb",
 "S:ab",
 "D:aA"}, "aaaaabbbb"),new String[] { });
		eq(4,(new Macros()).whichOnes(new String[] {"A:aB",
 "C:dE",
 "Z:FG",
 "B:dd"}, "qqqq"),new String[] { });
		eq(5,(new Macros()).whichOnes(new String[] {"A:aB",
 "C:dE",
 "Z:FG",
 "B:dd"}, "add"),new String[] { "A" });
		eq(6,(new Macros()).whichOnes(new String[] {"A:BC",
 "B:BC",
 "C:BC",
 "B:aa",
 "C:bb"}, "aaaaaaaaaabbbbbbbbbb"),new String[] { "A",  "B",  "C" });
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
