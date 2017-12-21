using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Scale 
{
	public string[] scale( int x, int y, string[] image ) 
	{
		int m = image.Length;
		int n = image[0].Length;
		string[] result = new string[y];
		int[,] M = new int[x, y];
		for( int i = 0; i < y * m; i++ )
			for( int j = 0; j < x * n; j++ )
				M[j / n, i / m] += image[i / y][j / x];
		for( int i = 0; i < y; i++ )
			for( int j = 0; j < x; j++ )
				result[i] += (char) ((2 * M[j, i] / m / n + 1) / 2);
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Scale()).scale(3, 3, new String[] {"AB","BC"}),new String[] { "ABB",  "BBC",  "BCC" });
		eq(2,(new Scale()).scale(2, 4, new String[] {"AB","BC"}),new String[] { "AB",  "AB",  "BC",  "BC" });
		eq(3,(new Scale()).scale(51, 43, new String[] {"......",
 ".X....",
 ".X....",
 ".X....",
 ".X....",
 ".XXXX.",
 "......"}),new String[] { "...................................................",  "...................................................",  
"...................................................",  "...................................................",  "...................................................",  "...................................................",  
"........@RRRRRRRR..................................",  "........CXXXXXXXX..................................",  
"........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX..................................",  "........CXXXXXXXX:::::::::::::::::::::::::4........",  "........CXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC........",  "........CXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC........",  "........CXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC........",  "........CXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC........",  "........CXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC........",  "........@RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR@........",  "...................................................",  "...................................................",  "...................................................",  "...................................................",  "...................................................",  "..................................................." });
		eq(4,(new Scale()).scale(4, 4, new String[] {"...AAA...",
 "...AAA..."}),new String[] { ".;;.",  ".;;.",  ".;;.",  ".;;." });
		eq(5,(new Scale()).scale(4, 4, new String[] {"......",
 ".X....",
 ".X....",
 ".X....",
 ".X....",
 ".XXXX.",
 "......"}),new String[] { "44..",  "<<..",  "<@40",  "4@@4" });
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
