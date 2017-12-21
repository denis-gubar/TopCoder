using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Pair: IComparable
{
	public Pair(long x, long y)
	{
		this.x = x;
		this.y = y;
	}
	public int CompareTo( object o )
	{
		Pair a = (Pair) o;
		if ( x.CompareTo( a.x ) != 0 ) return x.CompareTo( a.x );
		return y.CompareTo( a.y );
	}

	public long x;
	public long y;
}

public class Factorial
{
	private static long[] cache;
	private static int n = 21;
	static Factorial()
	{
		cache = new long[n];
		cache[0] = 1;
		for( int i = 1; i < n; i++ )
			cache[i] = cache[i - 1] * i;
	}
	static public long calc( long x )
	{
		if ( x < n ) return cache[x];
		return 0;
	}
}
public class Permutations
{
	public static int[] Permutation( long size, long M )
	{
		int[] result = new int[size];
		long factorial = Factorial.calc( size );
		for( int i = 0; i < size; i++ )
			result[i] = i;
		for( int i = 1; i < size; i++ )
		{
			if ( factorial == 0 )
				factorial = Factorial.calc( 20 );
			else
				factorial /= size - i + 1;
			int x = (int) (i + M / factorial - 1);
			long temp = result[x];
			for( int j = x; j >= i; j-- )
				result[j] = result[j - 1];
			result[i - 1] = (int) temp;
			M %= factorial;
		}
		return result;
	}
}
public class PermutationValues 
{
	public int get( long x, Pair[] P )
	{
		int i = 0;
		long result = 0;
		while( result + P[i].y - P[i].x + 1 <= x )
		{
			result += P[i].y - P[i].x + 1;
			i++;
		}
		return (int) (x - result + P[i].x);
	}
	public int[] getValues( int[] lows, int[] highs, string lexPos, string[] retInts ) 
	{
		int n = lows.Length;
		int m = retInts.Length;
		int[] result = new int[m];
		Pair[] P = new Pair[n];
		long count = n;
		for( int i = 0; i < n; i++ )
		{
			P[i] = new Pair( lows[i], highs[i] );
			count += P[i].y - P[i].x;
		}
		Array.Sort( P );
		long k = long.Parse( lexPos );
		if ( Factorial.calc( count ) > 0 )
			k %= Factorial.calc( count );
		for( int i = 0; i < m; i++ )
		{
			long r = long.Parse( retInts[i] );
			if ( count - r > 21 )
				result[i] = get( r, P );
			else
			{
				int[] M = Permutations.Permutation( Math.Min( 21, count ), k );
				result[i] = get( Math.Max( count - 21, 0 ) + M[M.Length - count + r], P );
			}
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new PermutationValues()).getValues(new int[] {1}, new int[] {4}, "0", new String[] {"0","1","2","3"}),new int[] { 1,  2,  3,  4 });
		eq(2,(new PermutationValues()).getValues(new int[] {1}, new int[] {3}, "5", new String[] {"0","1","2"}),new int[] { 3,  2,  1 });
		eq(3,(new PermutationValues()).getValues(new int[] {1,16}, new int[] {5,20}, "1000000", new String[] {"0","1","2","3","4","5","6","7","8","9","1","2","3"}),new int[] { 3,  18,  19,  4,  20,  2,  16,  17,  1,  5,  18,  19,  4 });
		eq(4,(new PermutationValues()).getValues(new int[] {1}, new int[] {5}, "100000000000001", new String[] {"0","1","2","3","4"}),new int[] { 2,  4,  5,  3,  1 });
		eq(5,(new PermutationValues()).getValues(new int[] {-1000000000,500000}, new int[] {0,2000000000}, "99999999999999999", new String[] {"2999500000","1234123","123344","9293939","2999500001","2999499950"}),new int[] { 1999999987,  -998765877,  -999876656,  -990706061,  1999999982,  1999999949 });
		eq(6,(new PermutationValues()).getValues(new int[] {9}, new int[] {9}, "999999", new String[] {"0"}),new int[] { 9 });
		eq(7,(new PermutationValues()).getValues(new int[] {0,-100,101}, new int[] {99,-11,100000000}, "100000000000009", new String[] {"4","100000087","7"}),new int[] { -96,  99999993,  -93 });
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
