using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class GameOfLife 
{
	int m;
	int n;
	int probe( int x, int y, string[] start )
	{
		if ( start[(x + m) % m][(y + n) % n] == '.' ) return 0;
		return 1;
	}
	public int alive( string[] start, string rules, int generations ) 
	{
	    m = start.Length;
		n = start[0].Length;		
		for( int step = 0; step < generations; step++ )
		{
			string[] next = new string[m];
			for( int i = 0; i < m; i++ )
				for( int j = 0; j < n; j++ )
				{
					int count = 0;
					for( int x = i - 1; x <= i + 1; x++ )
						for( int y = j - 1; y <= j + 1; y++ )
							if ( x != i || y != j )
								count += probe( x, y, start );
					if ( rules[count] == 'B' || rules[count] == 'S' && probe( i, j, start ) == 1 )
						next[i] += "X";
					else
						next[i] += ".";
				}
			for( int i = 0; i < m; i++ )
				start[i] = next[i];
		}
		int result = 0;
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
				if ( start[i][j] == 'X' )
					result++;
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
//		eq(1,(new GameOfLife()).alive(new String[] {"......"
//,"......"
//,".XXXX."
//,"......"
//,"......"}, "DDSBDDDDD", 2),6);
		eq(2,(new GameOfLife()).alive(new String[] {"XX","XX"}, "DDSBDDDDD", 1),0);
		eq(3,(new GameOfLife()).alive(new String[] {"........XXX"
,"..........X"
,".........X."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."}, "DDSBDDDDD", 1000),5);
		eq(4,(new GameOfLife()).alive(new String[] {".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"......................XXX.XX......................"
,".......................X..X......................."
,".......................X..XX......................"
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."}, "DBDBDBDBD", 16),80);
		eq(5,(new GameOfLife()).alive(new String[] {"X"}, "BDDDDDDDD", 2),1);
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
