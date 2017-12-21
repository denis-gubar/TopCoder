using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class IsHomomorphism 
{
	public string[] numBad( string[] source, string[] target, int[] mapping ) 
	{
		ArrayList A = new ArrayList();
		int n = source.Length;
		for( int a = 0; a < n; a++ )
			for( int b = 0; b < n; b++ )
				if ( mapping[int.Parse( source[a][b].ToString() )] !=
					int.Parse( target[mapping[a]][mapping[b]].ToString() ) )
					A.Add( "(" + a.ToString() + "," + b.ToString() + ")" );
		return (string[]) A.ToArray( "".GetType() );
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new IsHomomorphism()).numBad(new String[] {"0000",
 "0123",
 "0202",
 "0321"}, new String[] {"0000",
 "0123",
 "0202",
 "0321"}, new int[] {0,1,2,3}),new String[] { });
		eq(2,(new IsHomomorphism()).numBad(new String[] {"0123456",
 "1234560",
 "2345601",
 "3456012",
 "4560123",
 "5601234",
 "6012345"}, new String[] {"0123456",
 "1234560",
 "2345601",
 "3456012",
 "4560123",
 "5601234",
 "6012345"}, new int[] {1,3,2,1,2,1,1}),new String[] { "(0,0)",  "(0,1)",  "(0,2)",  "(0,3)",  "(0,4)",  "(0,5)",  "(0,6)",  "(1,0)",  "(1,1)",  "(1,2)",  "(1,3)",  "(1,4)",  "(1,5)",  "(1,6)",  "(2,0)",  "(2,1)",  "(2,2)",  "(2,3)",  "(2,4)",  "(2,5)",  "(3,0)",  "(3,1)",  "(3,2)",  "(3,3)",  "(3,4)",  "(3,5)",  "(4,0)",  "(4,1)",  "(4,2)",  "(4,3)",  "(4,4)",  "(4,5)",  "(4,6)",  "(5,0)",  "(5,1)",  "(5,2)",  "(5,3)",  "(5,4)",  "(5,5)",  "(6,0)",  "(6,1)",  "(6,4)",  "(6,6)" });
		eq(3,(new IsHomomorphism()).numBad(new String[] {"012",
 "120",
 "210"}, new String[] {"012",
 "120",
 "110"}, new int[] {0,1,2}),new String[] { "(2,0)" });
		eq(4,(new IsHomomorphism()).numBad(new String[] {"012",
 "120",
 "210"}, new String[] {"012",
 "120",
 "210"}, new int[] {1,2,0}),new String[] { "(0,0)",  "(0,1)",  "(0,2)",  "(1,0)",  "(1,2)",  "(2,0)",  "(2,2)" });
		eq(5,(new IsHomomorphism()).numBad(new String[] {"01","10"}, new String[] {"10","01"}, new int[] {1,0}),new String[] { });
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
