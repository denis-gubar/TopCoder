using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public struct State
{
	public State(int ax, int ay, int bx, int by, int turn)
	{
		this.ax = ax;
		this.ay = ay;
		this.bx = bx;
		this.by = by;
		this.turn = turn;
	}

	public int ax;
	public int ay;
	public int bx;
	public int by;
	public int turn;
}

public class PathFinding 
{
	int m, n;
	string[] board;

	bool probe( int x, int y )
	{
		return !(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == 'X');
	}

	public int minTurns( string[] board ) 
	{
		this.board = board;
		m = board.Length;
		n = board[0].Length;
		int AX = 0;
		int AY = 0;
		int BX = 0;
		int BY = 0;
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
				switch( board[i][j] )
				{
					case 'A': AX = i; AY = j; break;
					case 'B': BX = i; BY = j; break;
				}
		Queue Q = new Queue( m * n );
		Q.Enqueue( new State( AX, AY, BX, BY, 0 ) );
		bool[,,,] flag = new bool[m, n, m, n];
		flag[AX, AY, BX, BY] = true;
		while( Q.Count > 0 )
		{
			State S = (State) Q.Dequeue();
			for( int ax = S.ax - 1; ax <= S.ax + 1; ax++ )
				for( int ay = S.ay - 1; ay <= S.ay + 1; ay++ )
					if ( probe( ax, ay ) )
						for( int bx = S.bx - 1; bx <= S.bx + 1; bx++ )
							for( int by = S.by - 1; by <= S.by + 1; by++ )
								if ( probe( bx, by ) && !flag[ax, ay, bx, by] &&
									!(ax == bx && ay == by) &&
									!(ax == S.bx && ay == S.by && bx == S.ax && by == S.ay) )
								{
									Q.Enqueue( new State( ax, ay, bx, by, S.turn + 1 ) );
									flag[ax, ay, bx, by] = true;
									if ( ax == BX && ay == BY && bx == AX && by == AY )
										return S.turn + 1;
								}
		}
		return -1;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new PathFinding()).minTurns(new String[] {"....",
														   ".A..",
														   "..B.",
														   "...."}),2);
		eq(2,(new PathFinding()).minTurns(new String[] {"XXXXXXXXX",
														   "A...X...B",
														   "XXXXXXXXX"}),-1);
		eq(3,(new PathFinding()).minTurns(new String[] {"XXXXXXXXX",
														   "A.......B",
														   "XXXXXXXXX"}),-1);
		eq(4,(new PathFinding()).minTurns(new String[] {"XXXXXXXXX",
														   "A.......B",
														   "XXXX.XXXX"}),8);
		eq(5,(new PathFinding()).minTurns(new String[] {"...A.XXXXX.....",
														   ".....XXXXX.....",
														   "...............",
														   ".....XXXXX.B...",
														   ".....XXXXX....."}),13);
		eq(6,(new PathFinding()).minTurns(new String[] {"AB.................X",
														   "XXXXXXXXXXXXXXXXXXX.",
														   "X..................X",
														   ".XXXXXXXXXXXXXXXXXXX",
														   "X..................X",
														   "XXXXXXXXXXXXXXXXXXX.",
														   "X..................X",
														   ".XXXXXXXXXXXXXXXXXXX",
														   "X..................X",
														   "XXXXXXXXXXXXXXXXXXX.",
														   "X..................X",
														   ".XXXXXXXXXXXXXXXXXXX",
														   "X..................X",
														   "XXXXXXXXXXXXXXXXXXX.",
														   "X..................X",
														   ".XXXXXXXXXXXXXXXXXXX",
														   "X..................X",
														   "XXXXXXXXXXXXXXXXXXX.",
														   "...................X",
														   ".XXXXXXXXXXXXXXXXXXX"}),379);
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
