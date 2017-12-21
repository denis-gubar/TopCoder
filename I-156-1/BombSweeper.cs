using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class BombSweeper 
{
	int m;
	int n;
	string[] board;

	private int probe( int x, int y )
	{
		if ( x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '.' ) return 0;
		return 1;
	}

	public double winPercentage( string[] board ) 
	{
		this.board = board;
		m = board.Length;
		n = board[0].Length;
		int empty = 0;
		int bombs = 0;
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
				if ( probe( i, j ) == 1 )
					bombs++;
				else
				{
					int count = 0;
					for( int x = -1; x <= 1; x++ )
						for( int y = -1; y <= 1; y++ )
							count += probe( i + x, j + y );
					if ( count == 0 ) empty++;
				}
		return 100.0 * empty / (empty + bombs);
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new BombSweeper()).winPercentage(new String[] {".....",
 ".....",
 "..B..",
 ".....",
 "....."}),94.11764705882354);
		eq(2,(new BombSweeper()).winPercentage(new String[] {"BBBBB",
 "B...B",
 "B...B",
 "B...B",
 "BBBBB"}),5.882352941176471);
		eq(3,(new BombSweeper()).winPercentage(new String[] {".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 "........."}),0.0);
		eq(4,(new BombSweeper()).winPercentage(new String[] {".........................",
 ".........................",
 ".........................",
 "........................."}),100.0);
		eq(5,(new BombSweeper()).winPercentage(new String[] {"......B.......B..B...........................B....",
 "..............B..................BB..B............",
 "B.B.B.............B.....B..............B..........",
 "...................B...B....................BB....",
 "...B.....B.........................B.......B.....B",
 "B.B.........B.....B.......B..B......B.B...B.BB....",
 "..B...................BB...............B..........",
 ".........B...B................B..B................",
 ".......BB.......B....B................B.....BBB...",
 ".......BB..........B..............B......BB.......",
 "...................BB.....................B.......",
 "...B.B.B......B..............B...B......B.........",
 "B................B................................",
 "....B..........B.....B..BB....B...............BB..",
 "..B....B.....B.............B.....B............B...",
 "...................B.B........B..B.........B.B....",
 ".....B.....B......................................",
 "...........BB......BB...B.B........B...B..........",
 ".....BBB..........................................",
 ".B...........B....B...BB......B......B...B.B......",
 "..................B........BB................B....",
 "...............................B..B....BBB.B....B.",
 "..........B.......................................",
 ".....B..........B....BB......B.B......B......B....",
 ".....B..................B........B................",
 "............B.....B..B....BB...B....BB........B...",
 "..B.................B.........B...................",
 ".BB..............B................................",
 "...B....B..................B.................B....",
 "......B...B......B......................B.B.......",
 "..............B..................B.......B........",
 ".....B........BB...B.....B........................",
 ".......B......B.B..B..........B...........B....B..",
 "B...B...........B...B...B......B.B...B..B......B..",
 "....B..B.....B.B.......BB..B............B.B....B..",
 "B.......B..........B.........B...B.BB......B......",
 "....B...............................B.............",
 ".....B.B..........................................",
 "..........B............B......B.B..B....B.........",
 "....B...B.......................B.................",
 "B.................B...........B..B....B...........",
 "...B.....B........................................",
 "...B..B......................................BBB..",
 ".B...B....................................B....B..",
 "...B...B..........B...B.B.........................",
 ".....B.............B...BB..........B..BBB.BB......",
 "....................B.....B.......................",
 "........B..BB..........B.B....B...........B......B",
 ".........B.....BB..B.............B....BB..........",
 "....B..B..............B...B..B..........B........."}),77.67558528428094);
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
