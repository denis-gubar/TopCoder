using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Ordered
{
	int gcd( int a, int b )
	{
		while( a > 0 && b > 0 )
		{
			if ( a > b ) a %= b;
			else b %= a;
		}
		return Math.Max( a, b );
	}

	public string getType( int[] values )
	{
		bool asc = true;
		bool desc = true;
		bool nasc = true;
		bool ndesc = true;
		int mean = values[0];
		int max = 1;
		int freq = 1;
		for( int i = 1; i < values.Length; i++ )
		{
			mean += values[i];
			if ( values[i] == values[i - 1] )
			{
				asc = false;
				desc = false;
				freq++;
			}
			else
			{
				if ( max < freq ) max = freq;
				freq = 1;				
			}
			asc &= values[i] > values[i - 1];
			desc &= values[i] < values[i - 1];
			nasc &= values[i] <= values[i - 1];
			ndesc &= values[i] >= values[i - 1];
		}
		if ( max < freq ) max = freq;
		int k = gcd( mean, values.Length );
		mean /= k; int y = values.Length / k;		
		if ( asc ) return "ASCENDING " + mean.ToString() + "/" + y.ToString();
		if ( desc ) return "DESCENDING " + mean.ToString() + "/" + y.ToString();
		if ( nasc ) return "NONASCENDING " + max.ToString();
		if ( ndesc ) return "NONDESCENDING " + max.ToString();
		return "NOTHING";
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Ordered()).getType(new int[] {1,2,4,11}),"ASCENDING 9/2");
		eq(2,(new Ordered()).getType(new int[] {1,2,2,2,3,4}),"NONDESCENDING 3");
		eq(3,(new Ordered()).getType(new int[] {6,5,1}),"DESCENDING 4/1");
		eq(4,(new Ordered()).getType(new int[] {5,5,4,4,1}),"NONASCENDING 2");
		eq(5,(new Ordered()).getType(new int[] {1,2,3,4,1}),"NOTHING");
		eq(6,(new Ordered()).getType(new int[] {1000,999,998}),"DESCENDING 999/1");
		eq(7,(new Ordered()).getType(new int[] {999,1000,1000,1000,1000,1000}),"NONDESCENDING 5");
		eq(8,(new Ordered()).getType(new int[] {1,1000,1,1000,1,1000}),"NOTHING");
		eq(9,(new Ordered()).getType(new int[] {1,2,3,4,5,6,7,8,9,10,
11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,
31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,51}),"ASCENDING 638/25");
		eq(10,(new Ordered()).getType(new int[] {2,2,1}),"NONASCENDING 2");
		eq(11,(new Ordered()).getType(new int[] {1,2,2}),"NONDESCENDING 2");
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
