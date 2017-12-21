using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

class Triangle: IComparable
{
	int gcd( int a, int b )
	{
		while( a > 0 && b > 0 )
		{
			if ( a > b )
				a %= b;
			else
				b %= a;
		}
		return a + b;
	}
	public static int square( int x1, int x2, int x3, int y1, int y2, int y3 )
	{
		return (x1 - x2) * (y1 + y2) + (x2 - x3) * (y2 + y3) + (x3 - x1) * (y3 + y1);
	}
	public Triangle(int a, int b, int c)
	{
		int[] A = new int[] {a, b, c};
		int z = gcd( a, gcd( b, c ) );
		Array.Sort( A );
		this.a = A[0] / z;
		this.b = A[1] / z;
		this.c = A[2] / z;
	}
	public int CompareTo( object o )
	{
		Triangle a = (Triangle) o;
		if ( a.CompareTo( a.a ) != 0 ) return a.CompareTo( a.a );
		if ( b.CompareTo( a.b ) != 0 ) return b.CompareTo( a.b );
		return c.CompareTo( a.c );
	}
	public override bool Equals(object obj)
	{
		Triangle T = (Triangle) obj;
		return T.a == a && T.b == b && T.c == c;
	}
	public override int GetHashCode()
	{
		return a * 1997 + b * 97 + c;
	}
	public int a;
	public int b;
	public int c;
}

public class UniqueTriangles 
{
	public int side( int x1, int x2, int y1, int y2 )
	{
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
	public int howMany( int[] x, int[] y ) 
	{
		Hashtable H = new Hashtable( 20000 );
		int n = x.Length;
		for( int i = 0; i < n; i++ )
			for( int j = i + 1; j < n; j++ )
				for( int k = j + 1; k < n; k++ )
				{
					if ( Triangle.square( x[i], x[j], x[k], y[i], y[j], y[k] ) == 0 )
						continue;
					H[new Triangle( side( x[i], x[j], y[i], y[j] ),
						side( x[i], x[k], y[i], y[k] ),
						side( x[k], x[j], y[k], y[j] ) )] = null;
				}
		return H.Count;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new UniqueTriangles()).howMany(new int[] {0,1,1,0,2}, new int[] {0,1,0,1,0}),3);
		eq(2,(new UniqueTriangles()).howMany(new int[] {0,8,-3,1000,-9500,-1}, new int[] {7,15,4,1007,-9493,6}),0);
		eq(3,(new UniqueTriangles()).howMany(new int[] {-4,2,5,-5,-4,-4,3,1,1,1,2,0,1,1,5}, new int[] {5,2,-4,2,1,3,1,-1,2,0,1,4,-3,1,0}),256);
		eq(4,(new UniqueTriangles()).howMany(new int[] {-24,-22,33,78,-77,-66,76,-54,32,40,
														   -66,-22,-88,-50,-11,93,16,34,-79,-60,
														   -42,-30,-73,65,92,94,67,-74,69,83,
														   -51,91,78,-30,91,85,-78,-5,36,-91}, new int[] {91,14,27,-98,35,-14,-89,-12,-78,57,
																											 6,-52,-65,-61,-60,46,-84,34,31,11,
																											 41,97,-54,47,-12,-69,19,96,43,-45,
																											 -38,-71,53,6,-2,-43,-43,15,17,-77}),9872);
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
