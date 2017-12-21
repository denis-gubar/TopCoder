using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;
 
public class TupleLine
{
	public int quickLine( int size, string[] chosen )
	{
		int n = chosen[0].Length;
		Hashtable h = new Hashtable( 1000 );
		for( int i = 0; i < chosen.Length; i++ )
		{
			if ( !h.Contains( chosen[i] ) ) h.Add( chosen[i], null );
		}
		char[] s = new char[n];
		int result = size;
		int limit = 1;		
		for( int i = 0; i < n; i++ ) limit *= 3;
		foreach( DictionaryEntry d in h )
		{
			string point = (string) d.Key;
			for( int i = 1; i < limit; i++ )
			{
				int min = size;
				int count = size;
				int[] y = new int[n];
				int x = i;
				for( int j = 0; j < n; j++ )
				{
					switch( x % 3 )
					{
						case 1:
							y[j] = 1;
							break;
						case 2:
							y[j] = -1;
							break;
					}
					x /= 3;
				}				
				for( int k = 0; k < size; k++ )
				{
					bool flag = true;
					for( int j = 0; j < n; j++ )
					{
						s[j] = (char) ((int) point[j] + y[j] * k);
						flag &= (int) s[j] >= (int) '0' && (int) s[j] < (int) '0' + size;
						if ( !flag ) break;
					}
					if ( flag )
					{
						count--;
						if ( h.Contains( new string( s ) ) ) min--;
					}
				}
				for( int k = 1; k < size; k++ )
				{
					bool flag = true;
					for( int j = 0; j < n; j++ )
					{
						s[j] = (char) ((int) point[j] - y[j] * k);
						flag &= (int) s[j] >= (int) '0' && (int) s[j] < (int) '0' + size;
						if ( !flag ) break;
					}
					if ( flag )
					{
						count--;
						if ( h.Contains( new string( s ) ) ) min--;
					}
				}
				if ( count == 0 && result > min ) result = min;
			}
		}		
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new TupleLine()).quickLine(4, new String[] {"00","02","21"}),2);
		eq(2,(new TupleLine()).quickLine(4, new String[] {"00","32","21","32"}),3);
		eq(3,(new TupleLine()).quickLine(3, new String[] {"0022","0202","0112","0000","0112"}),0);
		eq(4,(new TupleLine()).quickLine(9, new String[] {"2355846","6355842","3355848"}),7);
		DateTime t2 = DateTime.Now;
		TimeSpan t = t2 - t1;
		Console.WriteLine( t.TotalMilliseconds / 1000 );
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
