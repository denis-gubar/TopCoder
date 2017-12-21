using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class Dragons
{
    private long[] x = new long[6];
	private long[] y = new long[6];
	
	private long cgd( long[] a )
	{
		long result = 1;
		while( true )
		{
			bool flag = true;
			for( int i = 0; i < a.Length; i++ )
			{
				flag &= a[i] % (2 * result) == 0;
			}
			if ( flag ) 
			{
				result *= 2;
			}
			else
			{
				break;
			}
		}
		return result;
	}

	private void round()
	{
		long[] a = new long[6];
		long[] b = new long[6];
		for( int i = 0; i < 6; i++ )
		{
			b[i] = y[i] * 4;
		}
		a[0] = x[2] + x[3] + x[4] + x[5];
		a[1] = x[2] + x[3] + x[4] + x[5];
		a[2] = x[0] + x[1] + x[4] + x[5];
		a[3] = x[0] + x[1] + x[4] + x[5];
		a[4] = x[0] + x[1] + x[2] + x[3];
		a[5] = x[0] + x[1] + x[2] + x[3];
		long[] c = new long[12];
		a.CopyTo( c, 0 );
		b.CopyTo( c, 6 );
		long n = cgd( c );
		for( int i = 0; i < 6; i++ )
		{
			x[i] = a[i] / n;
			y[i] = b[i] / n;
		}
	}

	public string snaug( int[] initialFood, int rounds )
    {
		for( int i = 0; i < 6; i++ )
		{
			x[i] = initialFood[i];
			y[i] = 1;
		}
		for( int i = 0; i < rounds; i++ )
		{
			round();
		}
		long n = cgd( new long[] {x[2], y[2]} );
		x[2] /= n;
		y[2] /= n;
		if ( y[2] == 1 ) return x[2].ToString();
		return x[2].ToString() + @"/" + y[2].ToString();
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
//    try
    {
		eq(1,(new Dragons()).snaug(new int[] {0, 0, 4, 0, 0, 0}, 2),"1");
		eq(2,(new Dragons()).snaug(new int[] {0, 0, 4, 0, 0, 0}, 3),"1/2");
		eq(3,(new Dragons()).snaug(new int[] {1000, 1000, 1000, 1000, 1000, 1000}, 45),"1000");
		eq(4,(new Dragons()).snaug(new int[] {1, 2, 3, 4, 5, 6}, 45),"7/2");
    }
    //catch(Exception e)
    {
	//Console.WriteLine(e.Message);
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
