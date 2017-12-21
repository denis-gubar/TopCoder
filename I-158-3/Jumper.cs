using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Point
{
	public Point(int x, int y, int step)
	{
		this.x = x;
		this.y = y;
		this.step = step;
	}

	public int x;
	public int y;
	public int step;
}

public class Jumper 
{
	string[] patterns;
	int[] speeds;
	string rows;
	int n;
	Queue Q = new Queue( 10000 );
	bool[,,] M;

	private int s( int x )
	{
		return x >= 0 ? speeds[int.Parse(rows[x].ToString())] : 0;
	}

	private void probe( Point P )
	{
		if ( P.x >= -1 && P.y >= 0 && P.y < 20 &&
			 P.y + s(P.x) >= 0 && P.y + s(P.x) < 20 && !M[P.x + 1, P.y, P.step] &&
			(P.x == -1 ||
			patterns[int.Parse(rows[P.x].ToString())][((-s(P.x) + 10) * P.step + P.y) % 5] == '#') )
		{
			Q.Enqueue( new Point( P.x, P.y + s(P.x), P.step + 1 ) );
			M[P.x + 1, P.y, P.step] = true;
		}
	}

	public int minTime( string[] patterns, int[] speeds, string rows ) 
	{
		this.patterns = patterns;
		this.speeds = speeds;
		this.rows = rows;
		n = rows.Length;
		M = new bool[n + 1, 20, 500];
		int result = int.MaxValue;
		Point P = new Point( -1, 0, 0 );
		Q.Enqueue( P );
		while( Q.Count > 0 )
		{
			P = (Point) Q.Dequeue();
			if ( P.step >= 500 || P.step + n - P.x >= result ) continue;
			if ( P.x == n - 1 )
			{
				result = Math.Min( result, P.step + 1 );
				continue;
			}
			probe( new Point( P.x + 1, P.y, P.step ) );
			probe( new Point( P.x, P.y, P.step ) );
			probe( new Point( P.x, P.y + 1, P.step ) );
			probe( new Point( P.x, P.y - 1, P.step ) );
			probe( new Point( P.x - 1, P.y, P.step ) );
		}
		return result == int.MaxValue ? -1 : result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Jumper()).minTime(new String[] {"###..", "..###"}, new int[] {1,1}, "01"),5);
		eq(2,(new Jumper()).minTime(new String[] {"###..", "..###"}, new int[] {5,5}, "01"),5);
		eq(3,(new Jumper()).minTime(new String[] {"....#", "....#"}, new int[] {4,5}, "0111"),9);
		eq(4,(new Jumper()).minTime(new String[] {"#....", "#...."}, new int[] {-4,-5}, "0111"),24);
		eq(5,(new Jumper()).minTime(new String[] {"#####","#####"}, new int[] {10,10}, "01"),-1);
		eq(6,(new Jumper()).minTime(new String[] {"#####","#####","....."}, new int[] {1,-1,1}, "01010101010101010102"),-1);
		eq(7,(new Jumper()).minTime(new String[] {"#....", "#....", "#...."}, new int[] {5,-5,6}, "2012"),12);
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
