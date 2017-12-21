using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class NENE
{
	string convert( int x )
	{
		char[] Dirs = "ENWS".ToCharArray();
		if ( x % 512 == 0 ) return Dirs[x / 512].ToString();
		if ( x > 3 * 512 ) Dirs = "XNWSE".ToCharArray();
		int c = x / 512;
		x %= 512;
		int a = 256;
		int n = 128;
		string result = Dirs[c].ToString() + Dirs[c + 1].ToString();
		result = result.Replace( "EN", "NE" ).Replace( "WS", "SW" );
		while( a != x )
		{
			if ( a > x )
			{
				result = Dirs[c].ToString() + result;
				a -= n;
			}
			else
			{
				result = Dirs[c + 1].ToString() + result;
				a += n;
			}
			n /= 2;
		}
		return result;
	}

	int convert( string s )
	{
		char[] Dirs = "ENWS".ToCharArray();
		if ( s.Length == 1 ) return Array.IndexOf( Dirs, s[0] ) * 512;
		if ( s.IndexOf( 'S' ) > -1 ) Dirs = "XNWSE".ToCharArray();
		int c = 0;		
		if ( s.IndexOf( "NW" ) > -1 ) c = 1;
		if ( s.IndexOf( "SW" ) > -1 ) c = 2;
		if ( s.IndexOf( "SE" ) > -1 ) c = 3;
		int result = 256 + c * 512;
		int n = 128;
		for( int k = s.Length - 3; k >= 0; k-- )
		{
			result += n * (2 * Math.Sign( Array.IndexOf( Dirs, s[k] ) - c ) - 1);
			n /= 2;
		}
		return result;		
	}

	public string vulnerable( string[] cw, string[] ccw )
	{
		bool[] flag = new bool[2048];
		for( int i = 0; i < cw.Length; i++ )
		{
			int a = convert( cw[i] );
			int b = convert( ccw[i] );
			for( int j = a; j <= b; j++ ) flag[j] = true;
			if ( a > b )
			{
				for( int j = a; j <= 2047; j++ ) flag[j] = true;
				for( int j = 0; j <= b; j++ ) flag[j] = true;
			}
		}
		for( int i = 1; i < 2048; i++ )
		{
			if ( !flag[i] ) return convert( i );
		}
		if ( !flag[0] ) return convert( 0 );
		return "SAFE";
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new NENE()).vulnerable(new String[] {"E"}, new String[] {"W"}),"WWWWWWWWSW");
		eq(2,(new NENE()).vulnerable(new String[] {"E","E","SE"}, new String[] {"W","N","S"}),"SSSSSSSSSE");
		eq(3,(new NENE()).vulnerable(new String[] {"E","WWWWWWWWSW"}, new String[] {"W","NE"}),"SAFE");
		eq(4,(new NENE()).vulnerable(new String[] {"EEEENE","WNW","SSWWSW"}, new String[] {"NNNNENEENE","WWNW","EEENE"}),"NEENE");
		eq(5,(new NENE()).vulnerable(new String[] {"EEEEEEEENE","W"}	, new String[] {"WWWWWWWWNW","EEEEEEEESE"}),"E");
		eq(6,(new NENE()).vulnerable(new String[] {"W"}, new String[] {"S"}),"EEEEEEEENE");
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
