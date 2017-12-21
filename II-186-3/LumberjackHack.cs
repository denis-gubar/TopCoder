using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public struct State: IComparable
{
	public State(int step, int x, int y, int isWet)
	{
		this.step = step;
		this.x = x;
		this.y = y;
		this.isWet = isWet;
	}
	public int CompareTo( object o )
	{
		State a = (State) o;
		return -step.CompareTo( a.step );		
	}

	public int step;
	public int x;
	public int y;
	public int isWet;
}
public class PriorityQueue
{
	private IComparable[] items;
	private int N = 0;
	private int size;
	private void fixUp( int k )
	{
		while( k > 1 && items[k / 2].CompareTo( items[k] ) < 0 )
		{
			IComparable temp = items[k];
			items[k] = items[k / 2];
			items[k / 2] = temp;
			k /= 2;
		}
	}
	private void fixDown( int k )
	{
		while( k + k <= N )
		{
			int i = k + k;
			if ( i < N && items[i].CompareTo( items[i + 1] ) < 0 ) i++;
			if ( items[k].CompareTo( items[i] ) >= 0 ) break;
			IComparable temp = items[k];
			items[k] = items[i];
			items[i] = temp;
			k = i;
		}
	}
	public int Capacity
	{
		get
		{
			return items.Length - 1;
		}
		set
		{
			IComparable[] newItems = new IComparable[value];
			Array.Copy( items, 1, newItems, 1, N );
			items = newItems;
		}
	}
	public int Count
	{
		get
		{
			return N;
		}
	}
	public PriorityQueue( int MaxSize )
	{
		size = MaxSize; items = new IComparable[size + 1];
	}
	public PriorityQueue(): this( 32 ) {}
	public bool isEmpty
	{
		get
		{
			return N == 0;
		}
	}

	public void Enqueue( IComparable newItem )
	{
		N++;
		if ( N >= items.Length ) Capacity *= 2;
		items[N] = newItem; 
		fixUp( N );
	}    
	public IComparable Dequeue()
	{
		IComparable temp = items[1];
		items[1] = items[N];
		items[N] = temp;
		N--;
		fixDown( 1 );
		return items[N + 1];
	}
}

public class LumberjackHack 
{
	PriorityQueue Q = new PriorityQueue( 10000 );
	int[,,] M;
	void calc( int step, int x, int y, int isWet, bool isVertical, string[] riverMap )
	{
		if ( x < 0 || x == riverMap.Length || (riverMap[x][y] == '.' && isWet == 1) ) return;
		if ( riverMap[x][y] == '.' )
		{
			isWet = 1;
			step += 3;
		}
		else
			step += isVertical ? 1 : 2;
		if ( M[x, y, isWet] > 0 && M[x, y, isWet] <= step ) return;
		M[x, y, isWet] = step;
		Q.Enqueue( new State( step, x, y, isWet ) );
	}
	public int timeToShore( string[] riverMap ) 
	{
		int m = riverMap.Length;
		int n = riverMap[0].Length;
		int x = 0;
		int y = 0;
		for( int i = 0; i < m; i++ )
		{
			int j = riverMap[i].IndexOf( '+' );
			if ( j >= 0 )
			{
				x = i;
				y = j;
			}
		}
		M = new int[m, n, 2];
		Q.Enqueue( new State( 0, x, y, 0 ) );
		while( Q.Count > 0 )
		{
			State S = (State) Q.Dequeue();
			M[S.x, S.y, S.isWet] = S.step;
			if ( S.y == 0 || S.y == n - 1 ) return S.step;
			calc( S.step, S.x - 1, S.y, S.isWet, true, riverMap );
			calc( S.step, S.x + 1, S.y, S.isWet, true, riverMap );
			calc( S.step, S.x, S.y - 1, S.isWet, false, riverMap );
			calc( S.step, S.x, S.y + 1, S.isWet, false, riverMap );
		}
		return -1;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new LumberjackHack()).timeToShore(new String[] {".+.",
																 "||."}),3);
		eq(2,(new LumberjackHack()).timeToShore(new String[] {"..+",
																 "||."}),0);
		eq(3,(new LumberjackHack()).timeToShore(new String[] {"....|||",
																 "....|..",
																 "...||..",
																 "||.+...",
																 "...|...",
																 "...||||"}),7);
		eq(4,(new LumberjackHack()).timeToShore(new String[] {"||.|....",
																 "........",
																 ".|.+|..|",
																 "...|....",
																 "|..|.|.|"}),-1);
		eq(5,(new LumberjackHack()).timeToShore(new String[] {".........|.|.|.|.|..||...||.|..|.||...|.|.|||...||",
																 ".||.||...||..|||.....|.||||...|.|.|.|.|..|...|.|||",
																 "||.|.|..||.||....|.....|.||.|||||.|.|.||.|||||.|..",
																 "|.....|.|.||||.||..|.|..|..|.|||||.....||.|.||....",
																 "..|..||...||.|.......|||+||.||||....||||.....|..||",
																 "...||..||||.|......||..|.|||||.|.|||||.||..|||...|",
																 "|||...|..|..|.|||.||.|..|...||.|||..|..||.|.||....",
																 "|..|||||||||.||.....|..|.|.|||||...||...|.|.|||||.",
																 ".|..||...|||............|.|..|||.||.|||.||..||.|||",
																 ".|.|||...||..|..|...||.||..|..|||||.|.|...||..||.|",
																 "||||.|||.|..||||..|..||...|..||.|.||||...|...|.|..",
																 ".||..||...|.....|||.|||||..||......|.||.||.|..||..",
																 "|.|||....|||||.|..|..|.|||..|.||.||.|.|.|.|..||...",
																 ".||.||||||...||||||..||....|..||.|||..||...|.|||||",
																 ".||||.|....|...|.||..||..|||.|||||....|...||.|.||.",
																 ".|...|..||....||...|.||||.....||||.||.|||||||..|||",
																 ".||||...|...|..||...|...|...|.|..|.|.|..|..|||.||.",
																 ".|.|||..||||||||........|||||||||.|.|........|||||",
																 ".....|...||.||...|||...||||..|||...||....||..||.||",
																 "||...||..||.||...||...||||..|.|..|...|||..||..|||.",
																 "|..||||.||..|...|....||||||...|||.|.|||||..|||...|",
																 ".....|||..||.|||.....||..||||...|||||.||.|.||..|||",
																 "|..|.||..|..||..||..|...|..|.||..||||..|...||..|..",
																 "||.|..|.|||||...|...|.|..|||||...|.......|.||.||||",
																 ".|.....|.|||||.....|||...|..|||||...|.||..||.|||.|",
																 ".|...||....|||...|||.||.|.|......|........|.||||||",
																 "..|.|.|.|||||..|||..|.........|...|.|.|...||.....|",
																 ".|.|.|.|..|.|||||||||||.|.|||....|||||...|.||||.|.",
																 "|.|||....|.||||..||......|..|||||.....||.|..||..|.",
																 "||.||.|||.|......|..|.|...|..||.|||..||.....|.|..|",
																 ".||||..|.|.||||.|||.||.||.....|....|....||...|..||",
																 ".....|||...||.||.||....|.||..||....|....|||||.|..|",
																 "|.|.|||||...|.||..|..|..|.|..|.|........||..|.|.||",
																 "....|..|.|..|.||||||....||||.|.||||||.|.|.|.......",
																 "||||....|..|...||..||||||||...|.|||||.|.|||.|...||",
																 "|...|.|..|..|..|....|..||..|||....||..||..|..|..|.",
																 "|||||....|.||.|..|.||..|||..|.|.|..||.|...|.|..||.",
																 "..|.|||.|.||..|...|||.|..|||..||...||...||||.....|",
																 "..||||.|.|.....|||..||||..|.||||..|..|||.....||.||",
																 "|..|||||....|........|.||||.||..||||.|....|||||||.",
																 ".|...||.|.||..|.|....|.||..|.|....|.|.||.||.||.|..",
																 ".|..|..|.||||.||||....|||.....|.|...|.|...|...||..",
																 "|..|||..|.||.|||..||.....|.|..|.|.|...|.....|.....",
																 "||..||.|...|.||...|..|..||.|||.||.|.||...|....|||.",
																 ".|....|.|||.|..|||..|.....|.||.||...|...||.......|",
																 ".||..|||.|.|....|||...|..|.||.||.|.|...|||||.|.|.|",
																 "|.|.||.||.|.|.||.|||.||....||.|||||.||.|.|||......",
																 "|...|||...|.||||....|.||.||.|.........|..||.|..||.",
																 ".|.....|.|.|....||.||...|||.|..||...||.|||.||.|.|.",
																 "||.||.|||.|||..||......|......||..||||.|..||.||||."}),63);
		eq(6,(new LumberjackHack()).timeToShore(new String[] {".+."}),3);
		eq(7,(new LumberjackHack()).timeToShore(new String[] {"..+.."}),-1);
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
