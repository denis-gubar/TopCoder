using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class QuipuReader 
{
	public int[] readKnots( string[] knots ) 
	{
		int n = knots.Length;
		int[] result = new int[n];
		for( int i = 0; i < knots[0].Length; i++ )
		{
			bool f1 = true;
			bool f2 = false;
			for( int j = 0; f1 && j < n; j++ )
			{
				f1 &= knots[j][i] == 'X' && i > 0 && knots[j][i - 1] == '-' || knots[j][i] == '-';
				f2 |= knots[j][i] == 'X';
			}
			for( int j = 0; j < n; j++ )
			{
				if ( f1 && f2 )
					result[j] *= 10;
				if ( knots[j][i] == 'X' ) 
					result[j]++;
			}
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new QuipuReader()).readKnots(new String[] { "-XXXXXXX--XX-----XXXXX---",
  "---XX----XXX-----XXXX----",
  "-XXXXX---XXXXX--XXXXXXXX-" }),new int[] { 725,  234,  558 });
		eq(2,(new QuipuReader()).readKnots(new String[] { "XX---XXXX",
  "XXX-----X" }),new int[] { 24,  31 });
		eq(3,(new QuipuReader()).readKnots(new String[] { "-XXX---XX----X",
  "--X----X-XXXXX",
  "-XX--XXXX---XX" }),new int[] { 321,  115,  242 });
		eq(4,(new QuipuReader()).readKnots(new String[] { "-------X--------",
  "--XXX----XXXX---",
  "--------------XX" }),new int[] { 100,  3040,  2 });
		eq(5,(new QuipuReader()).readKnots(new String[] { "--XXX-XXXXXXXX----------XXXXXXXXX--XXXXXXXX-",
  "--XX----XXXX-----XXXXXX---XXX------XXXXXXXX-",
  "--------------------X----XXXXXXXX--XXXXXXXX-",
  "--XX-------X------XXXX----XXX-------XXXXXX--",
  "--XXX---XXXXX-------X------XX--------X------",
  "-XXXX--XXXXXXX-----------XXXXXXX----XXXXX---",
  "-----------X---XXXXXXXX----XX--------XXX----",
  "-----------X---XXXXXXXX----X----------------",
  "---X--XXXXXXXX--XXXXXXX---XXX---------------",
  "--XX---XXXXXXX--XXXXXXX----XX-------XXXXX---" }),new int[] { 38098,  24638,  188,  21436,  35121,  47075,  1823,  1810,  18730,  27725 });
		eq(6,(new QuipuReader()).readKnots(new String[] {"X","-"}),new int[] { 1,  0 });
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
