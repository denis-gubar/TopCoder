using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class PointsOnAxis 
{
	bool calc( int[] distances, int[] LookUp, int[] result, int i, int x )
	{
		for( int j = 0; j < i; j++ )
		{
			if ( LookUp[x - result[j]] == 0 )
			{
				for( int k = 0; k < j; k++ )
					LookUp[x - result[k]]++;
				return false;
			}
			LookUp[x - result[j]]--;
		}
		result[i] = x;
		if ( i == result.Length - 1 ) return true;
		int l = Array.BinarySearch( distances, x + 1 );
		if ( l < 0 ) l = ~l;
		for( int j = l; j < distances.Length; j++ )
			if ( LookUp[distances[j]] > 0 )
				if ( calc( distances, LookUp, result, i + 1, distances[j] ) )
					return true;
		for( int j = 0; j < i; j++ )
			LookUp[x - result[j]]++;
		return false;
	}
	public int[] findPoints( int[] distances ) 
	{
		int m = distances.Length;
		Array.Sort( distances );
		int n = 1;
		while( n * (n - 1) / 2 < m ) n++;
		int[] result = new int[n];
		int[] LookUp = new int[distances[m - 1] + 1];
		for( int i = 0; i < m; i++ )
			LookUp[distances[i]]++;
		if ( calc( distances, LookUp, result, 0, 0 ) )
			return result;
		return new int[] {};
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new PointsOnAxis()).findPoints(new int[] {5, 2, 1, 6, 2, 3, 3, 4, 5, 6, 3, 9, 1, 4, 1}),new int[] { 0,  3,  4,  5,  6,  9 });
		eq(2,(new PointsOnAxis()).findPoints(new int[] {20,100,120}),new int[] { 0,  20,  120 });
		eq(3,(new PointsOnAxis()).findPoints(new int[] {1,2,3,4,5,7}),new int[] { 0,  2,  3,  7 });
		eq(4,(new PointsOnAxis()).findPoints(new int[] {1,2,4}),new int[] { });
		eq(5,(new PointsOnAxis()).findPoints(new int[] {237601, 843904, 56786, 429289, 52254, 83576, 220417,
606303, 180815, 191688, 185347, 154025, 17184, 787118,
414615, 791650, 760328, 623487, 372503, 4532, 26790,
163631, 377035, 345713, 208872, 31322, 168163, 136841}),new int[] { 0,  52254,  56786,  83576,  220417,  237601,  429289,  843904 });
		eq(6,(new PointsOnAxis()).findPoints(new int[] {1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 6, 7}),new int[] { 0,  1,  2,  5,  6,  7 });
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
