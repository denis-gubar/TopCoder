using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class ProbabilityTree 
{
	public int[] getOdds( string[] tree, int lowerBound, int upperBound ) 
	{
		ArrayList A = new ArrayList();
		int n = tree.Length;
		double[] probs = new double[n];
		probs[0] = double.Parse( tree[0], nfi ) / 100;
		bool[] flag = new bool[n];
		flag[0] = true;
		int left = n - 1;
		while( left > 0 )
		{
			int i = 0;
			while( flag[i] || !flag[int.Parse( tree[i].Split()[0] )] ) i++;
			string[] x = tree[i].Split();
			double p = probs[int.Parse( x[0] )];
			double p1 = double.Parse( x[1] ) / 100;
			double p2 = double.Parse( x[2] ) / 100;
			probs[i] = p * p1 + (1 - p) * p2;
			flag[i] = true;
			left--;
		}
		for( int i = 0; i < n; i++ )
			if ( lowerBound < probs[i] * 100 && probs[i] * 100 < upperBound )
				A.Add( i );
		return (int[]) A.ToArray( n.GetType() );
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new ProbabilityTree()).getOdds(new String[] {"40","0 70 10"}, 30, 50),new int[] { 0,  1 });
		eq(2,(new ProbabilityTree()).getOdds(new String[] {"20","2 50 50","0 50 50"}, 49, 51),new int[] { 1,  2 });
		eq(3,(new ProbabilityTree()).getOdds(new String[] {"10","0 99 41","1 40 3","2 91 43"}, 81, 88),new int[] { });
		eq(4,(new ProbabilityTree()).getOdds(new String[] {"79","0 64 52","1 70 87","0 38 99","1 24 8"}, 47, 81),new int[] { 0,  1,  2,  3 });
		eq(5,(new ProbabilityTree()).getOdds(new String[] {"51",
 "29 58 3",
 "6 56 86",
 "18 97 1",
 "44 99 25",
 "33 69 90",
 "27 67 49",
 "32 15 19",
 "33 1 21",
 "45 12 33",
 "29 24 40",
 "45 86 74",
 "40 30 65",
 "0 18 27",
 "1 90 65",
 "0 47 62",
 "40 81 72",
 "42 25 56",
 "45 16 81",
 "8 94 92",
 "29 41 92",
 "24 4 29",
 "32 56 91",
 "20 16 77",
 "1 35 79",
 "45 77 61",
 "6 50 19",
 "20 69 43",
 "4 6 16",
 "15 55 26",
 "42 73 90",
 "40 8 49",
 "33 16 33",
 "15 95 47",
 "9 66 40",
 "25 80 39",
 "35 72 70",
 "27 10 36",
 "40 36 10",
 "32 2 48",
 "33 44 23",
 "22 51 45",
 "25 8 43",
 "18 32 96",
 "45 41 74",
 "0 51 6",
 "18 48 15"}, 8, 82),new int[] { 0,  1,  2,  3,  4,  5,  6,  7,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  20,  21,  23,  24,  25,  26,  27,  28,  29,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46 });
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
