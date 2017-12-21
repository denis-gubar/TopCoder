using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class DotNotation 
{
	Hashtable cache = new Hashtable();

	Hashtable calc( string dotForm )
	{
		if ( cache.Contains( dotForm ) ) return (Hashtable) cache[dotForm];
		Hashtable A = new Hashtable();
		int i = dotForm.IndexOfAny( "/*-+".ToCharArray() );
		if ( i == -1 )
		{
			A[int.Parse( dotForm )] = null;
		}
		while( i > -1 )
		{
			string left = dotForm.Substring( 0, i );
			string right = dotForm.Substring( i + 1 );
			int l = 0; int r = 0;
			for( l = 0; l < left.Length && left[left.Length - l - 1] == '.'; l++ );			
			if ( left.IndexOf( '+' + new string( '.', l + 1 )) == -1 &&
				left.IndexOf( '-' + new string( '.', l + 1 )) == -1 &&
				left.IndexOf( '/' + new string( '.', l + 1 )) == -1 &&
				left.IndexOf( '*' + new string( '.', l + 1 )) == -1 )
			{
				left = left.TrimEnd( '.' );
				for( r = 0; r < right.Length && right[r] == '.'; r++ );
				if ( right.IndexOf( new string( '.', r + 1 ) + '+' ) == -1 &&
					right.IndexOf( new string( '.', r + 1 ) + '-' ) == -1 &&
					right.IndexOf( new string( '.', r + 1 ) + '/' ) == -1 &&
					right.IndexOf( new string( '.', r + 1 ) + '*' ) == -1 )
				{
					right = right.TrimStart( '.' );
					Hashtable L = calc( left );
					Hashtable R = calc( right );
					foreach( DictionaryEntry ld in L )
					{
						long a = (int) ld.Key;
						foreach( DictionaryEntry rd in R )
						{
							long b = (int) rd.Key;
							long x = 0;
							switch( dotForm[i] )
							{
								case '+':
									x = a + b;
									break;
								case '-':
									x = a - b;
									break;
								case '*':
									x = a * b;
									break;
								case '/':
									x = b == 0 ? int.MaxValue : a / b;
									break;
							}
							if ( x >= -2000000000 && x <= 2000000000 ) A[(int) x] = null;
						}
					}
				}
			}
			i = dotForm.IndexOfAny( "/*-+".ToCharArray(), i + 1 );
		}

		cache[dotForm] = A;
		return A;
	}

	public int countAmbiguity( string dotForm ) 
	{
       	return calc( dotForm ).Count;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new DotNotation()).countAmbiguity("2"),1);
		eq(2,(new DotNotation()).countAmbiguity("9+5*3"),2);
		eq(3,(new DotNotation()).countAmbiguity("9+5.*3"),1);
		eq(4,(new DotNotation()).countAmbiguity("1+2.*.3+4"),1);
		eq(5,(new DotNotation()).countAmbiguity("9*8+7*6-5+4*3/2./9"),99);
		eq(6,(new DotNotation()).countAmbiguity("1+...2....*.8..+7"),0);
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
