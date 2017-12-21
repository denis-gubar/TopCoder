using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

#region class Combinatorial
public class Combinatorial
{
	private static long[] cacheFactorial;
	private static int maxFactorial = 20;
	private static long[,] cacheBinominalCoefficient;
	private static int maxBinominalCoefficient = 50;
	private static long[,] cacheStirling;
	private static int maxStirling = 25;
	static Combinatorial()
	{
		#region Factorial init
		cacheFactorial = new long[maxFactorial + 1];
		cacheFactorial[0] = 1;
		for( int i = 1; i <= maxFactorial; i++ )
			cacheFactorial[i] = cacheFactorial[i - 1] * i;
		#endregion
		#region Binominal coeffiecients init
		cacheBinominalCoefficient = new long[maxBinominalCoefficient + 1, maxBinominalCoefficient + 1];		
		for( int i = 0; i <= maxBinominalCoefficient; i++ )
		{
			cacheBinominalCoefficient[i, 0] = cacheBinominalCoefficient[i, i] = 1;
			for( int j = 1; j < i; j++ )
				cacheBinominalCoefficient[i, j] = cacheBinominalCoefficient[i - 1, j - 1] + cacheBinominalCoefficient[i - 1, j];
		}
		#endregion
		#region Stirling number of second kind init
		cacheStirling = new long[maxStirling + 1, maxStirling + 1];
		for( int i = 1; i <= maxStirling; i++ )
		{
			cacheStirling[i, i] = cacheStirling[i, 1] = 1;
			for( int j = 2; j < i; j++ )
				cacheStirling[i, j] = cacheStirling[i - 1, j] * j + cacheStirling[i - 1, j - 1];
		}
		#endregion
	}
	static public long Factorial( int n )
	{
		if ( n <= maxFactorial ) return cacheFactorial[n];
		return 0;
	}
	static public long C( int n, int k )
	{
		if ( n <= maxBinominalCoefficient && k <= maxBinominalCoefficient ) return cacheBinominalCoefficient[n, k];
		return 0;
	}
	static public long Choose( int n, int k, bool isSorted, bool isUnique )
	{
		long result = 1;
		if ( !isSorted && !isUnique )
			for( int i = 0; i < k; i++ )
				result *= n;
		if ( !isSorted && isUnique )
			result = Combinatorial.C( n, k ) * Combinatorial.Factorial( k );
		if ( isSorted && isUnique )
			result = Combinatorial.C( n, k );
		if ( isSorted && !isUnique )
			result = Combinatorial.C( n + k - 1, k );
		return result;
	}
	public static long Stirling( int n, int k )
	{
		if ( k > n || n == 0 || maxStirling < n ) return 0;
		return cacheStirling[n, k];		
	}
}
#endregion

public class PermutationCounter 
{
	public long count( string n )
	{
		long result = 0;
		int[] digits = new int[10];
		for( int i = 0; i < n.Length; i++ )
			digits[n[i] - '0']++;
		while( n != "" )
		{			
			for( int i = 0; i < n[0] - '0'; i++ )
				if ( digits[i] > 0 )
				{
					int k = n.Length - 1;
					long x = 1;
					digits[i]--;
					for( int j = 0; j < 10; j++ )
					{
						x *= Combinatorial.C( k, digits[j] );
						k -= digits[j];
					}
					digits[i]++;
					result += x;
				}
			digits[n[0] - '0']--;
			n = n.Substring( 1 );
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new PermutationCounter()).count("1020"),7);
		eq(2,(new PermutationCounter()).count("50000000000000"),13);
		eq(3,(new PermutationCounter()).count("1030000040000"),1414);
		eq(4,(new PermutationCounter()).count("1901712530271201432987123"),141588146596382454);
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
