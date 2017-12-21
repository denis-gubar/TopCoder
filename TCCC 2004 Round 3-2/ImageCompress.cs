using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public struct Data
{
	public Data(string[] image)
	{
		this.image = image;
	}
	public string[] image;
	public override bool Equals(object obj)
	{
		Data D = (Data) obj;
		if ( image.Length != D.image.Length ) return false;
		for( int i = 0; i < image.Length; i++ )
			if ( image[i] != D.image[i] ) return false;
		return true;
	}
	public override int GetHashCode()
	{
		return ( string.Join( ":", image ) ).GetHashCode ();
	}
}

public class Comp: IComparer
{
	public int Compare(object x, object y)
	{
		string s1 = (string) x;
		string s2 = (string) y;
		if ( s1.Length == 0 ) return 1;
		if ( s1.Length != s2.Length ) return s1.Length - s2.Length;
		return s1.CompareTo( s2 );
	}
}
public class ImageCompress 
{
	Comp comp = new Comp();
	Hashtable H = new Hashtable( 10000 );

	string get( string a, string b, string oper )
	{
		if ( a != b || a.IndexOfAny( "URCL".ToCharArray() ) >= 0 )
			return oper + a + b;
		return a;
	}

	string calc( Data D )
	{
		if ( H.Contains( D ) ) return (string) H[D];
		string result = "";
		int m = D.image.Length;
		int n = D.image[0].Length;
		if ( m == 1 && D.image[0] == new string( D.image[0][0], n ) )
			result = D.image[0][0].ToString();
		else if ( n == 1 )
		{
			bool flag = true;
			for( int i = 1; flag && i < m; i++ )
				flag = D.image[i] == D.image[i - 1];
			if ( flag )
				result = D.image[0];
		}
		if ( result == "" )
		{
			string s = "";
			if ( m > 1 )
			{
				string[] x1 = new string[(m + 1) / 2];
				string[] x2 = new string[m / 2];
				for( int i = 0; i < m / 2; i++ )
				{
					x1[i] = D.image[i];
					x2[i] = D.image[(m + 1) / 2 + i];
				}
				if ( m % 2 > 0 )
					x1[(m - 1) / 2] = D.image[m / 2];
				s = get( calc( new Data( x1 ) ), calc( new Data( x2 ) ), "U" );
				if ( comp.Compare( result, s ) > 0 ) result = s;
				for( int i = 0; i < m / 2; i++ )
				{
					x1[i] = D.image[2 * i];
					x2[i] = D.image[2 * i + 1];
				}
				if ( m % 2 > 0 )
					x1[(m - 1) / 2] = D.image[m - 1];
				s = get( calc( new Data( x1 ) ), calc( new Data( x2 ) ), "R" );
				if ( comp.Compare( result, s ) > 0 ) result = s;
			}
			if ( n > 1 )
			{
				string[] x1 = new string[m];
				string[] x2 = new string[m];
				for( int i = 0; i < m; i++ )
				{
					for( int j = 0; j < n / 2; j++ )
					{
						x1[i] += D.image[i][j];
						x2[i] += D.image[i][(n + 1) / 2 + j];
					}
					if ( n % 2 > 0 )
						x1[i] += D.image[i][(n - 1) / 2];
				}
				s = get( calc( new Data( x1 ) ), calc( new Data( x2 ) ), "L" );
				if ( comp.Compare( result, s ) > 0 ) result = s;
				for( int i = 0; i < m; i++ )
				{
					x1[i] = "";
					x2[i] = "";
					for( int j = 0; j < n / 2; j++ )
					{
						x1[i] += D.image[i][2 * j];
						x2[i] += D.image[i][2 * j + 1];
					}
					if ( n % 2 > 0 )
						x1[i] += D.image[i][n - 1];
				}
				s = get( calc( new Data( x1 ) ), calc( new Data( x2 ) ), "C" );
				if ( comp.Compare( result, s ) > 0 ) result = s;
			}
		}
		H[D] = result;
		return result;
	}

	public string compress( string[] image ) 
	{
		return calc( new Data( image ) );
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new ImageCompress()).compress(new String[] { "BBBWWW",
															 "BBBWWW" }),"LBW");
		eq(2,(new ImageCompress()).compress(new String[] { "BWB",
															 "WWW" }),"CRBWW");
		eq(3,(new ImageCompress()).compress(new String[] { "BWBWBWBW",
															 "WBWBWBWB",
															 "BWBWBWBW",
															 "WBWBWBWB",
															 "BWBWBWBW" }),"CRBWRWB");
		eq(4,(new ImageCompress()).compress(new String[] { "WWBWBWBW",
															 "WBWBWBWB",
															 "BWBWBWBW",
															 "WBWBWBWB",
															 "BWBWBWBB" }),"CRCCRRWBBBBWRCWCWUWBB");
		eq(5,(new ImageCompress()).compress(new String[] { "WWWWWWWWWW",
															 "WWBBWWBBWW",
															 "WBBBBBBBBW",
															 "WBBBBBBBBW",
															 "WWBBBBBBWW",
															 "WWWBBBBWWW",
															 "WWWWBBWWWW",
															 "WWWWWWWWWW" }),"UURWCCWBCWBCCCCWBBBCLBWBRCCCWBRBWCCWBRBWRLLWBLLBWWW");
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
