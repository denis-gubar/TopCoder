using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

class Pair:IComparable
{
	public Pair(int rank, int i)
	{
		this.rank = rank;
		this.i = i;
	}
	public int CompareTo( object o )
	{
		Pair a = (Pair) o;
		if ( rank.CompareTo( a.rank ) != 0 ) return rank.CompareTo( a.rank );
		return i.CompareTo( a.i );
	}

	public int rank;
	public int i;
}

class Mark:IComparable
{
	public Mark(int totalRank, int totalScore, string name)
	{
		this.totalRank = totalRank;
		this.totalScore = totalScore;
		this.name = name;
	}
	public int CompareTo( object o )
	{
		Mark a = (Mark) o;
		if ( totalRank.CompareTo( a.totalRank ) != 0 ) return totalRank.CompareTo( a.totalRank );
		if ( totalScore.CompareTo( a.totalScore ) != 0 ) return -totalScore.CompareTo( a.totalScore );
		return name.CompareTo( a.name );
	}

	public int totalRank;
	public int totalScore;
	public string name;
}
public class ContestScore 
{
	public string[] sortResults( string[] data ) 
	{
		int m = data.Length;
		if ( m == 0 ) return new string[] {};
		int n = data[0].Split().Length - 1;
		Mark[] M = new Mark[m];
		int[,] score = new int[m, n];
		for( int i = 0; i < m; i++ )
		{
			string[] x = data[i].Replace( ".", "" ).Split();
			M[i] = new Mark( 0, 0, x[0] );
			for( int j = 1; j <= n; j++ )
			{
				score[i, j - 1] = int.Parse( x[j] );
				M[i].totalScore += score[i, j - 1];
			}
		}
		for( int j = 0; j < n; j++ )
		{
			Pair[] ranks = new Pair[m];
			for( int i = 0; i < m; i++ )
				ranks[i] = new Pair( score[i, j], i );
			Array.Sort( ranks );
			Array.Reverse( ranks );
			int k = 1;
			M[ranks[0].i].totalRank += k;
			for( int i = 1; i < m; i++ )
			{
				if ( ranks[i - 1].rank != ranks[i].rank )
					k = i + 1;
				M[ranks[i].i].totalRank += k;
			}
		}
		Array.Sort( M );
		for( int i = 0; i < m; i++ )
			data[i] = M[i].name + " " + M[i].totalRank.ToString() + " " + (M[i].totalScore / 10).ToString() +
				"." + (M[i].totalScore % 10).ToString();
		return data;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new ContestScore()).sortResults(new String[] {"A 90.7 92.9 87.4",
															   "B 90.5 96.6 88.0",
															   "C 92.2 91.0 95.3"}),new String[] { "C 5 278.5",  "B 6 275.1",  "A 7 271.0" });
		eq(2,(new ContestScore()).sortResults(new String[] {"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3",
															   "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7",
															   "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6",
															   "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0",
															   "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6",
															   "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6",
															   "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4",
															   "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8",
															   "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"}),new String[] { "PRINCETON 34 717.6",  "MIT 36 721.7",  "HARVARD 38 719.9",  "COLUMBIA 39 720.0",  "STANFORD 39 711.3",  "YALE 40 712.4",  "BROWN 41 720.0",  "CORNELL 42 712.3",  "PENN 51 699.5" });
		eq(3,(new ContestScore()).sortResults(new String[] {}),new String[] { });
		eq(4,(new ContestScore()).sortResults(new String[] {"AA 90.0 80.0 70.0 60.0 50.0 40.0",
															   "BBB 80.0 70.0 60.0 50.0 40.0 90.0",
															   "EEE 70.0 60.0 50.0 40.0 90.0 80.0",
															   "AAA 60.0 50.0 40.0 90.0 80.0 70.0",
															   "DDD 50.0 40.0 90.0 80.0 70.0 60.0",
															   "CCC 40.0 90.0 80.0 70.0 60.0 50.0"}),new String[] { "AA 21 390.0",  "AAA 21 390.0",  "BBB 21 390.0",  "CCC 21 390.0",  "DDD 21 390.0",  "EEE 21 390.0" });
		eq(5,(new ContestScore()).sortResults(new String[] {"A 00.1", "B 05.2", "C 29.0","D 00.0"}),new String[] { "C 1 29.0",  "B 2 5.2",  "A 3 0.1",  "D 4 0.0" });
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
