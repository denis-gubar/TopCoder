using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class Factorial
{
	private long[] cache;
	private bool isNeedCache = false;
	private int n = 20;
	
	public Factorial( bool isNeedCache )
	{
		this.isNeedCache = isNeedCache;
		if ( isNeedCache )
		{
			cache = new long[n];
			cache[0] = 1;
			for( int i = 1; i < n; i++ )
			{
				cache[i] = cache[i - 1] * i;
			}
		}
	}

	public long fact( int x )
	{
		if ( x < n && isNeedCache ) return cache[x];
		long result = 1;
		for( int i = 1; i < x; i++ )
		{
			result *= i;
		}
		return result;
	}
}

public class BinominalCoefficient
{
	private long[,] cache;
	private bool isNeedCache = false;
	private int n;
	private int k;
	
	public BinominalCoefficient( bool isNeedCache, int n, int k )
	{
		this.isNeedCache = isNeedCache;
		this.n = n;
		this.k = k;
		if ( isNeedCache ) cache = new long[n, k];
	}
	public BinominalCoefficient( bool isNeedCache ) : this( isNeedCache, 50, 50 ) {}
	
	public long binominal(int n, int k)
	{		
		k = k < (n - k) ? k : n - k;
		if ( n < this.n && k < this.k && isNeedCache )
		{
			if ( cache[n, k] > 0 ) return cache[n, k];
			cache[n, 0] = 1;
			for( int i = 0; i < k; i++ )
			{
				if ( cache[n, i + 1] == 0 )	cache[n, i + 1] = cache[n, i] * (n - i) / (i + 1);
			}
			return cache[n, k];
		}
		long result = 1;
		for( int i = 0; i < k; i++ )
		{
			result = result * (n - i) / (i + 1);
		}
		return result;
	}
}

public class Chooses
{
	private BinominalCoefficient b = new BinominalCoefficient( true );
	private Factorial f = new Factorial( true );

	public long choose( int n, int k, bool isSorted, bool isUnique )
	{
		long result = 1;
		if ( !isSorted && !isUnique )
		{
			for( int i = 0; i < k; i++ )
			{
				result *= n;
			}
		}
		if ( !isSorted && isUnique )
		{
			result = b.binominal( n, k ) * f.fact( k );
		}
		if ( isSorted && isUnique )
		{
			result = b.binominal( n, k );
		}
		if ( isSorted && !isUnique )
		{
			result = b.binominal( n + k - 1, k );
		}
		return result;
	}
}

public class Data: IComparable
{
	public string name;
	public long odd;
	public Data( string name, long odd )
	{
		this.name = name; this.odd = odd;
	}
	
	public int CompareTo( object o )
	{
		Data d = (Data) o;
		if ( odd != d.odd ) return odd.CompareTo( d.odd );
		return name.CompareTo( d.name );
	}
}

public class Lottery
{
    public string[] sortByOdds( string[] rules )
    {
		int N = rules.Length;
		Chooses c = new Chooses();
		Data[] d = new Data[N];
		for( int i = 0; i < N; i++ )
		{
			string[] x = rules[i].Substring( rules[i].IndexOf( ':' ) + 2 ).Split();
			int n = int.Parse( x[0] );
			int k = int.Parse( x[1] );
			bool isSorted = x[2][0] == 'T';
			bool isUnique = x[3][0] == 'T';
			d[i] = new Data(rules[i].Substring( 0, rules[i].IndexOf( ':' ) ),
				c.choose( n, k, isSorted, isUnique ));
		}
		string[] result = new string[N];
		Array.Sort( d );
		for( int i = 0; i < N; i++ )
		{
			result[i] = d[i].name;
		}
        return result;
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    try
    {
		eq(1,(new Lottery()).sortByOdds(new String[] {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}),new String[] { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" });
		eq(2,(new Lottery()).sortByOdds(new String[] {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
),new String[] { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" });
		eq(3,(new Lottery()).sortByOdds(new String[] {}),new String[] { });
    }
    catch(Exception e)
    {
	Console.WriteLine(e.Message);
    }
  }
  private static void eq(int n, int a, int b)
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
