using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class VendingMachine
{
	public int motorUse( string[] prices, string[] purchases )
	{
		int result = 0;
		int time = 0;
		bool first = true;
		int m = prices.Length;
		int n = prices[0].Split().Length;
		int[, ] M = new int[m, n];
		int[] sum = new int[n];
		for( int i = 0; i < m; i++ )
		{
			string[] x = prices[i].Split();
			for( int j = 0; j < n; j++ )
			{
				M[i, j] = int.Parse( x[j] );
				sum[j] += M[i, j];
			}
		}
		int curCol = 0;
		int c = 0; int max = 0;
		for( int step = 0; step < purchases.Length; step++ )
		{
			string[] x = purchases[step].Split( ",:".ToCharArray() );
			int row = int.Parse( x[0] );
			int col = int.Parse( x[1] );
			int t = int.Parse( x[2] );
			if ( first || t - time >= 5 ) 
			{
				c = 0;
				max = sum[0];				
				for( int i = 1; i < n; i++ )
				{
					if ( max < sum[i] )
					{
						max = sum[i]; c = i;
					}
				}
				result += Math.Min( Math.Abs( curCol - c ), n - Math.Abs( curCol - c ) );
				curCol = c;
			}
			first = false;
			if ( M[row, col] == 0 ) return -1;
			result += Math.Min( Math.Abs( curCol - col ), n - Math.Abs( curCol - col ) );
			sum[col] -= M[row, col];
			M[row, col] = 0;
			time = t;
			curCol = col;
		}
		c = 0;
		max = sum[0];				
		for( int i = 1; i < n; i++ )
		{
			if ( max < sum[i] )
			{
				max = sum[i]; c = i;
			}
		}
		result += Math.Min( Math.Abs( curCol - c ), n - Math.Abs( curCol - c ) );
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new VendingMachine()).motorUse(new String[] {"100 100 100"}, new String[] {"0,0:0", "0,2:5", "0,1:10"}),4);
		eq(2,(new VendingMachine()).motorUse(new String[] {"100 200 300 400 500 600"}, new String[] {"0,2:0", "0,3:5", "0,1:10", "0,4:15"}),17);
		eq(3,(new VendingMachine()).motorUse(new String[] {"100 200 300 400 500 600"}, new String[] {"0,2:0", "0,3:4", "0,1:8", "0,4:12"}),11);
		eq(4,(new VendingMachine()).motorUse(new String[] {"100 100 100"}, new String[] {"0,0:10", "0,0:11"}),-1);
		eq(5,(new VendingMachine()).motorUse(new String[] {"100 200 300",
"600 500 400"}, new String[] {"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"}),6);
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
