using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

class Point
{
	double x;
	double y;
	double z;
	public Point( double x, double y, double z )
	{
		this.x = x; this.y = y; this.z = z;
	}
	double distance( Point A )
	{
		return Math.Sqrt( (x - A.x)*(x - A.x) + (y - A.y)*(y - A.y) + (z - A.z)*(z - A.z) );
	}
	public static double triangleSquare( Point A, Point B, Point C )
	{
		double a = A.distance( B );
		double b = B.distance( C );
		double c = C.distance( A );
		double p = (a + b + c) / 2;
		return Math.Sqrt( p * (p - a) * (p - b) * (p - c) );
	}
}
 
public class SolidArea
{
	public int totalArea( int[] xs, int[] ys, int factor, int shift )
	{
		int n = xs.Length;
		int[] x = new int[n + 1];
		int[] y = new int[n + 1];
		Array.Copy( xs, x, n );
		Array.Copy( ys, y, n );
		x[n] = x[0]; y[n] = y[0];
		double top = 0;
		double side = 0;
		for( int i = 0; i < n; i++ )
		{
			top += (x[i] - x[i + 1]) * (y[i] + y[i + 1]);
			Point A = new Point( x[i], y[i], 0 );
			Point B = new Point( x[i + 1], y[i + 1], 0 );
			Point C = new Point( x[i] * factor, y[i] * factor, shift );
			Point D = new Point( x[i + 1] * factor, y[i + 1] * factor, shift );
			side += Point.triangleSquare( A, B, C ) + Point.triangleSquare( B, C, D );
		}
		top *= (1.0 + factor * factor) / 2;
		top = Math.Abs( top );
		return (int) (top + side);
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new SolidArea()).totalArea(new int[] {0,1,1,0}, new int[] {0,0,1,1}, 3, 5),51);
		eq(2,(new SolidArea()).totalArea(new int[] {-1,1,1,-1}, new int[] {-1,-1,1,1}, 2, 1),36);
		eq(3,(new SolidArea()).totalArea(new int[] {0,2,6,6,8,8,6,2,2,0}, new int[] {10,10,6,10,10,0,0,4,0,0}, 9, 9),14993);
		eq(4,(new SolidArea()).totalArea(new int[] {-100,100,100,-100}, new int[] {-100,-100,100,100}, 50, 50),200005203);
		eq(5,(new SolidArea()).totalArea(new int[] {0,1,3,1,3,0,-3,-1,-3,-1}, new int[] {3,1,1,-1,-3,-2,-3,-1,1,1}, 10, 9),3601);
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
