using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

enum Directions { SE, SW, NW, NE };

public class BrickByBrick
{
	private int hash( double x, double y, Directions d )
	{
		return (int) (x * 10000 + y * 100 + (int) d);
	}

	private int f( double x )
	{
		return (int) x;
	}

	private bool g( double x )
	{
		return (x - (int) x) < 0.1;
	}

    public int timeToClear( string[] map )
    {
		int result = 0;
		int m = map.Length;
		int n = map[0].Length;
		int[,] A = new int[m, n];
		double x = 0;
		double y = 0.5;
		Directions d = Directions.SE;
		double[] dx = new double[] {0.5, 0.5, -0.5, -0.5};
		double[] dy = new double[] {0.5, -0.5, -0.5, 0.5};
		double[] tx = new double[] {0, 0, -0.5, -0.5};
		double[] ty = new double[] {0, -0.5, -0.5, 0};
		Directions[] dirx = new Directions[] {Directions.NE, Directions.NW, Directions.SW, Directions.SE};
		Directions[] diry = new Directions[] {Directions.SW, Directions.SE, Directions.NE, Directions.NW};
		int count = 0;
		Hashtable h = new Hashtable( 10000 );
		for( int i = 0; i < m; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				if ( map[i][j] == 'B' ) 
				{
					A[i, j] = 2;
					count++;
				}
				if ( map[i][j] == '#' )
				{
					A[i, j] = 1;
				}
			}
		}
		while( count > 0 )
		{
			x += dx[(int) d];
			y += dy[(int) d];
			result++;
			if ( h.Contains( hash(x, y, d) ) )
			{
				return -1;
			}
			else
			{
				h.Add( hash(x, y, d), null );
			}
			switch( d )
			{
				case Directions.SE:
					if ( x == m || y == n ) 
					{
						d = g( x ) ? dirx[(int) d] : diry[(int) d];
						continue;
					}
					break;
				case Directions.SW:
					if ( x == m || y == 0 ) 
					{
						d = g( x ) ? dirx[(int) d] : diry[(int) d];
						continue;
					}
					break;
				case Directions.NW:
					if ( x == 0 || y == 0 ) 
					{
						d = g( x ) ? dirx[(int) d] : diry[(int) d];
						continue;
					}
					break;
				case Directions.NE:
					if ( x == 0 || y == n ) 
					{
						d = g( x ) ? dirx[(int) d] : diry[(int) d];
						continue;
					}
					break;
			}
			if ( A[f( x + tx[(int) d]), f( y + ty[(int) d] )] == 1 ) 
			{
				d = g ( x )? dirx[(int) d] : diry[(int) d];
				continue;
			}
			if ( A[f( x + tx[(int) d]), f( y + ty[(int) d] )] == 2 ) 
			{
				A[f( x + tx[(int) d]), f( y + ty[(int) d] )] = 0;
				d = g ( x )? dirx[(int) d] : diry[(int) d];
				count--;
				h.Clear();
			}
		}		
        return result;
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
//    try
    {
		eq(1,(new BrickByBrick()).timeToClear(new String[] { ".B",
  "BB" }),6);
		eq(2,(new BrickByBrick()).timeToClear(new String[] { ".BB",
  "BBB",
  "BBB" }),-1);
		eq(3,(new BrickByBrick()).timeToClear(new String[] { "......B",
  "###.###",
  "B.....B" }),35);
		eq(4,(new BrickByBrick()).timeToClear(new String[] { "..BBB...",
  ".#BB..#.",
  "B.#B.B..",
  "B.B.....",
  "##.B.B#.",
  "#BB.#.B.",
  "B..B.BB.",
  "#..BB..B",
  ".B....#." }),-1);
		eq(5,(new BrickByBrick()).timeToClear(new String[] { ".BB..BBB.B...",
  "B.B...B..BB..",
  "#B...B#B.....",
  "B#B.B##...##B",
  "BB.B#.B##B.B#",
  "B.B#.BBB.BB#B",
  "B#BBB##.#B#B.",
  "B#BB.BBB#BB.#" }),3912);
		eq(6,(new BrickByBrick()).timeToClear(new String[] { ".BBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB" }),31753);
    }
//    catch(Exception e)
    {
//	Console.WriteLine(e.Message);
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
