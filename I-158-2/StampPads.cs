using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class StampPads 
{
	public int bestCombo( string[] pads, string[] wishlist ) 
	{
		int n = wishlist.Length;
		int m = pads.Length;
		int[] M = new int[m];
		for( int i = 0; i < m; i++ )
		{
			string[] x = pads[i].Split();
			for( int j = 0; j < x.Length; j++ )
			{
				int k = Array.IndexOf( wishlist, x[j] );
				if ( k > -1 )
					M[i] |= 1 << k;
			}
		}
		int result = int.MaxValue;
		for( int i = 1; i < 1 << m; i++ )
		{
			int goal = 0;
			int count = 0;
			for( int j = 0; count < result && j < m; j++ )
				if ( (i & (1 << j)) > 0 )
				{
					count++;
					goal |= M[j];
				}
			if ( goal == (1 << n) - 1 ) result = count;
		}
		return result == int.MaxValue ? -1 : result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new StampPads()).bestCombo(new String[] {"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}, new String[] {"orange", "yellow", "red", "blue", "magenta", "tan"}),3);
		eq(2,(new StampPads()).bestCombo(new String[] {"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}, new String[] {"orange", "yellow", "red", "blue", "tan"}),2);
		eq(3,(new StampPads()).bestCombo(new String[] {"yellow black blue green red",
 "yellow brown cyan magenta tan",
 "black grey fire maroon silver",
 "blue white neon tangerine rust",
 "green orange soot turquoise mint",
 "red cream opal chrome sky"}, new String[] {"yellow", "black", "blue", "green", "red",
 "brown", "grey", "white", "orange", "cream"}),5);
		eq(4,(new StampPads()).bestCombo(new String[] {"red green orange magenta yellow"}, new String[] {"silver"}),-1);
		eq(5,(new StampPads()).bestCombo(new String[] {"a i y d o", "t s k g e", "j u w i k", "u k l s j", "q s a c y",
 "q m d x a", "m s l h r", "s x q l n", "u r j s k", "e w v d p",
 "o l a b q", "f z g a m", "o g k b a", "c h g k t", "z v s n x",
 "z n b w c", "h p o u k", "t z o x m", "a w i v z", "u t v m y"}, new String[] {"x", "b", "u", "c", "h", "j", "t", "v", "d", "g",
 "k", "w", "y", "z", "a", "i", "m", "l", "n", "e"}),6);
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
