using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class DesertWind 
{
	public int daysNeeded( string[] theMap ) 
	{
		int m = theMap.Length;
		int n = theMap[0].Length;
		int[,] M = new int[m, n];
		int x = 0;
		int y = 0;
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
				switch( theMap[i][j] )
				{
					case '@':
						M[i, j] = -1;
						x = i; y = j;
						break;
					case 'X':
					case '-':
						M[i, j] = -1;
						break;
				}
		bool flag = true;
		while( flag )
		{
			flag = false;
			for( int i = 0; i < m; i++ )
				for( int j = 0; j < n; j++ )
					if ( theMap[i][j] != 'X' && theMap[i][j] != '*' )
					{
						ArrayList A = new ArrayList();
						for( int dx = Math.Max( 0, i - 1 ); dx <= Math.Min( m - 1, i + 1 ); dx++ )
							for( int dy = Math.Max( 0, j - 1 ); dy <= Math.Min( n - 1, j + 1 ); dy++ )
								if ( (dx != i || dy != j) && M[dx, dy] >= 0 )
									A.Add( M[dx, dy] );
						if ( A.Count == 0 ) continue;
						A.Sort();
						int a = (int) A[0];
						int b = A.Count > 1 ? (int) A[1] : a + 3;
						int z = Math.Max( Math.Min( a + 3, b + 1 ), Math.Min( a + 1, b + 3 ) );
						if ( M[i, j] < 0 || z < M[i, j] )
						{
							flag = true;
							M[i, j] = z;
						}
					}			
		}
		return M[x, y] > 0 ? M[x, y] : -1;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new DesertWind()).daysNeeded(new String[] {"--*","@-*","X--"}),2);
		eq(2,(new DesertWind()).daysNeeded(new String[] {"-X-*","-@X-","---X","--**"}),3);
		eq(3,(new DesertWind()).daysNeeded(new String[] {"*--X-----",
 "--XX--@--",
 "*-X------"}),-1);
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
