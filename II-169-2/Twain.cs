using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Twain
{
	public string getNewSpelling( int year, string phrase )
	{
		phrase = " " + phrase;
		if ( year >= 1 )
		{
			phrase = phrase.Replace( " x", " z" ).Replace( "x", "ks" );
			
		}
		if ( year >= 2 )
		{
			phrase = phrase.Replace( "y", "i" );
		}
		if ( year >= 3 )
		{
			phrase = phrase.Replace( "ce", "se" ).Replace( "ci", "si" );
		}
		if ( year >= 4 )
		{
			int l = 0;
			while( l != phrase.Length )
			{
				l = phrase.Length;
				phrase = phrase.Replace( "ck", "k" );
			}
		}
		if ( year >= 5 )
		{
			phrase = phrase.Replace( " sch", " sk" ).Replace( "chr", "kr" ).Replace( "ch", "!h" ).Replace( "c", "k" ).Replace( "!", "c" );
		}
		if ( year >= 6 )
		{
			phrase = phrase.Replace( " kn", " n" );
		}
		if ( year >= 7 )
		{
			int l = 0;
			while( l != phrase.Length )
			{
				l = phrase.Length;
				phrase = phrase.Replace( "qq", "q" );
				phrase = phrase.Replace( "ww", "w" );
				phrase = phrase.Replace( "rr", "r" );
				phrase = phrase.Replace( "tt", "t" );
				phrase = phrase.Replace( "pp", "p" );
				phrase = phrase.Replace( "ss", "s" );
				phrase = phrase.Replace( "dd", "d" );
				phrase = phrase.Replace( "ff", "f" );
				phrase = phrase.Replace( "gg", "g" );
				phrase = phrase.Replace( "hh", "h" );
				phrase = phrase.Replace( "jj", "j" );
				phrase = phrase.Replace( "kk", "k" );
				phrase = phrase.Replace( "ll", "l" );
				phrase = phrase.Replace( "zz", "z" );
				phrase = phrase.Replace( "xx", "x" );
				phrase = phrase.Replace( "cc", "c" );
				phrase = phrase.Replace( "vv", "v" );
				phrase = phrase.Replace( "bb", "b" );
				phrase = phrase.Replace( "nn", "n" );
				phrase = phrase.Replace( "mm", "m" );
			}
		}
		phrase = phrase.Substring( 1 );
		return phrase;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Twain()).getNewSpelling(1, "i fixed the chrome xerox by the cyclical church"),"i fiksed the chrome zeroks by the cyclical church");
		eq(2,(new Twain()).getNewSpelling(2, "i fixed the chrome xerox by the cyclical church"),"i fiksed the chrome zeroks bi the ciclical church");
		eq(3,(new Twain()).getNewSpelling(0, "this is unchanged"),"this is unchanged");
		eq(4,(new Twain()).getNewSpelling(7, "sch kn x xschrx cknnchc cyck xxceci"),"sk n z zskrks nchk sik zksesi");
		eq(5,(new Twain()).getNewSpelling(7, "  concoction   convalescence   cyclical   cello   "),"  konkoktion   konvalesense   siklikal   selo   ");
		eq(6,(new Twain()).getNewSpelling(7, ""),"");
		eq(7,(new Twain()).getNewSpelling(7, "cck xzz aaaaa"),"k z aaaaa");
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
