using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class TurretDefense 
{
	public int firstMiss( int[] xs, int[] ys, int[] times ) 
	{
		int x = 0;
		int y = 0;
		int t = 0;
		for( int i = 0; i < xs.Length; i++ )
		{
			if ( Math.Abs( xs[i] - x ) + Math.Abs( ys[i] - y ) > times[i] - t )
				return i;
			x = xs[i];
			y = ys[i];
			t = times[i];
		}
		return -1;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new TurretDefense()).firstMiss(new int[] {3,5,6}, new int[] {7,5,6}	, new int[] {11,15,16}),2);
		eq(2,(new TurretDefense()).firstMiss(new int[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, new int[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, new int[] {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32}),-1);
		eq(3,(new TurretDefense()).firstMiss(new int[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, new int[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, new int[] {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,31}),15);
		eq(4,(new TurretDefense()).firstMiss(new int[] {1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0}, new int[] {1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0,
 1000,0,1000,0,1000,0,1000,0,1000,0}, new int[] {2000,4000,6000,8000,10000,12000,14000,16000,18000,20000,
 22000,24000,26000,28000,30000,32000,34000,36000,38000,40000,
 42000,44000,46000,48000,50000,52000,54000,56000,58000,60000,
 62000,64000,66000,68000,70000,72000,74000,76000,78000,80000,
 82000,84000,86000,88000,90000,92000,94000,96000,98000,100000}),-1);
		eq(5,(new TurretDefense()).firstMiss(new int[] {4,5}, new int[] {4,5}, new int[] {7,8}),0);
		eq(6,(new TurretDefense()).firstMiss(new int[] {1,2,3,4,15}, new int[] {1,2,3,4,15}, new int[] {100,200,300,400,405}),4);
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
