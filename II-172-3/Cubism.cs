using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Cubism 
{
	int probe( int[] x,  int[,,] A )
	{
		if ( x[0] >= 0 && x[1] >= 0 && x[2] >= 0 && x[0] < 4 && x[1] < 4 && x[2] < 4 && A[x[0], x[1], x[2]] == 1 ) return 1;
		return 0;
	}

	public int lines( string[] lattice, string color ) 
	{
		int result = 0;
		int[,,] A = new int[4,4,4];
		for( int i = 0; i < 4; i++ )
			for( int j = 0; j < 16; j++ )
			{
				if ( lattice[i][j] == 'B' && color == "black" ) A[i, j / 4, j % 4] = 1;
				if ( lattice[i][j] == 'W' && color == "white" ) A[i, j / 4, j % 4] = 1;
			}
		for( int i = 0; i < 4; i++ )
			for( int j = 0; j < 4; j++ )
				for( int k = 0; k < 4; k++ )
					for( int di = -1; di < 2; di++ )
						for( int dj = -1; dj < 2; dj++ )
							for( int dk = -1; dk < 2; dk++ )
							{
								int l = 0;
								if ( di != 0 || dj != 0 || dk != 0 )
									for( int z = 0; z < 4; z++ )
										l += probe( new int[] {i + z * di, j + z * dj, k + z * dk}, A );
								if ( l == 4 ) result++;
							}
		return result / 2;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Cubism()).lines(new String[] {"BBBBBWWWBWWWBWWW",
 "BWWWWWWWWWWWWWWW",
 "BWWWWWWWWWWWWWWW",
 "BWWWWWWWWWWWWWWW"}, "black"),3);
		eq(2,(new Cubism()).lines(new String[] {"BWWWWWWWWWWWWWWW",
 "WWWWWBWWWWWWWWWW",
 "WWWWWWWWWWBWWWWW",
 "WWWWWWWWWWWWWWWB"}, "black"),1);
		eq(3,(new Cubism()).lines(new String[] {"WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW"}, "black"),0);
		eq(4,(new Cubism()).lines(new String[] {"WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW"}, "white"),76);
		eq(5,(new Cubism()).lines(new String[] {"WWWWWWWWWBWWWWWW",
 "WWWBWWWWWWWWWWWW",
 "WWWWWWWWWWWWBWWW",
 "WWWBWWWWWWWWWWWW"}, "white"),58);
		eq(6,(new Cubism()).lines(new String[] {"BWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBW"}, "white"),20);
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
