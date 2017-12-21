using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Data: IComparable
{
	public Data(int x, int y)
	{
		this.y = y;
		this.x = x;
	}
	public int CompareTo( object o )
	{
		Data a = (Data) o;
		if ( x.CompareTo( a.x ) != 0 ) return x.CompareTo( a.x );
		return y.CompareTo( a.y );
	}

	public int x;
	public int y;
}

public class SkipRope 
{
	public int[] partners( int[] candidates, int height ) 
	{
		int n = candidates.Length;
		Data[] A = new Data[n];
		for( int i = 0; i < n; i++ )
		{
			if ( candidates[i] > height ) A[i] = new Data( 2 * (candidates[i] - height), candidates[i] );
			if ( candidates[i] < height ) A[i] = new Data( 2 * (height - candidates[i] + 1), candidates[i] );
			if ( candidates[i] == height ) A[i] = new Data( 0, candidates[i] );
		}									   
		Array.Sort( A );
		int[] result = new int[] {A[0].y, A[1].y};
		Array.Sort( result );
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new SkipRope()).partners(new int[] {102, 99, 104}, 100),new int[] { 99,  102 });
		eq(2,(new SkipRope()).partners(new int[] {102, 97, 104}, 100),new int[] { 97,  102 });
		eq(3,(new SkipRope()).partners(new int[] {101, 100, 99}, 100),new int[] { 100,  101 });
		eq(4,(new SkipRope()).partners(new int[] {75, 117, 170, 175, 168, 167, 167, 142, 170, 85, 89, 170}, 169),new int[] { 170,  170 });
		eq(5,(new SkipRope()).partners(new int[] {134, 79, 164, 86, 131, 78, 99, 150, 105, 163, 150, 110, 90, 137, 127, 130, 121, 
													 93, 97, 131, 170, 137, 171, 153, 137, 138, 92, 103, 149, 110, 156}, 82),new int[] { 79,  86 });
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
