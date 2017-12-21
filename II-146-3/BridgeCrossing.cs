using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class BridgeCrossing
{
	private Hashtable l = new Hashtable( 1000 );
	private Hashtable r = new Hashtable( 1000 );

	private int goRight( int[] left, int[] right )
	{
		if ( left.Length == 2 )
		{
			return left[0] > left[1] ? left[0] : left[1];
		}
		if ( l.Contains( left ) )
		{
			return (int) l[left];
		}
		int min = 6000;
		for( int i = 0; i < left.Length - 1; i++ )
		{
			for( int j = i + 1; j < left.Length; j++ )
			{
				int[] a = new int[left.Length - 2];
				int[] b = new int[right.Length + 2];
				int k = 0;
				for( int x = 0; x < left.Length; x++ )
				{
					if ( x != i && x != j )
					{
						a[k++] = left[x];
					}
				}				
				k = 0;
				for( int x = 0; x < right.Length; x++ )
				{
					b[k++] = right[x];
				}
				b[k++] = left[i];
				b[k++] = left[j];
				int result = goLeft( a, b ) + (left[i] > left[j] ? left[i] : left[j]);
				min = min < result ? min : result;
			}
		}
		l.Add( left, min );
		return min;
	}

	private int goLeft( int[] left, int[] right )
	{
		if ( r.Contains( right ) )
		{
			return (int) r[left];
		}
		int min = 6000;
		for( int i = 0; i < right.Length; i++ )
		{
			int[] a = new int[left.Length + 1];
			int[] b = new int[right.Length - 1];
			int k = 0;
			for( int x = 0; x < left.Length; x++ )
			{
				a[k++] = left[x];
			}
			a[k++] = right[i];
			k = 0;
			for( int x = 0; x < right.Length; x++ )
			{
				if ( x != i )
				{
					b[k++] = right[x];
				}				
			}
			int result = goRight( a, b ) + right[i];
			min = min < result ? min : result;
		}
		r.Add( right, min );
		return min;
	}

    public int minTime( int[] times )
    {
        if ( times.Length == 1 ) return times[0];
		return goRight( times, new int[] {} );
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    //try
    {
		eq(1,(new BridgeCrossing()).minTime(new int[] { 1, 2, 5, 10 }),17);
		eq(2,(new BridgeCrossing()).minTime(new int[] { 1, 2, 3, 4, 5 }),16);
		eq(3,(new BridgeCrossing()).minTime(new int[] { 100 }),100);
		eq(4,(new BridgeCrossing()).minTime(new int[] { 1, 2, 3, 50, 99, 100 }),162);
    }
/*    catch(Exception e)
    {
	Console.WriteLine(e.Message);
    }*/
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
