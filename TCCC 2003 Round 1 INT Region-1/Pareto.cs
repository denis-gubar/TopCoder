using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Pareto
{
	public int optima( string[] policy )
	{
		int result = 0;
		int n = policy.Length;
		int m = policy[0].Split().Length;
		string[] M = new string[] {"awful", "bad", "fair", "fairly-happy", "happy", "ecstatic"};
		for( int i = 0; i < n; i++ )
		{
			bool flag = true;
			string[] x = policy[i].Split();
			for( int j = 0; j < n; j++ )
			{
				if ( i != j )
				{
					string[] y = policy[j].Split();
					bool f = false;
					bool t = true;
					for( int k = 0; k < m; k++ )
					{
						f |= Array.IndexOf( M, x[k] ) > Array.IndexOf( M, y[k] );
						t &= Array.IndexOf( M, x[k] ) == Array.IndexOf( M, y[k] );
					}
					flag &= t || f;
				}				
			}
			if ( flag ) result++;
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Pareto()).optima(new String[] {"bad bad fairly-happy awful",
"bad bad bad awful",
"ecstatic awful ecstatic ecstatic"}),2);
		eq(2,(new Pareto()).optima(new String[] {"bad ecstatic","bad bad", "awful ecstatic",
 "fair happy", "fairly-happy fair",
"fairly-happy fairly-happy", "fair happy"}),4);
		eq(3,(new Pareto()).optima(new String[] {"happy","bad","fairly-happy","bad","happy"}),2);
		eq(4,(new Pareto()).optima(new String[] {"bad bad bad bad bad happy fairly-happy"}),1);
		eq(5,(new Pareto()).optima(new String[] {"fair fair fair fair fair fair fair fair",
"bad fair fair fair fair fair fair fair",
"fairly-happy fair fair fair fair fair fair fair",
"happy bad bad bad bad bad bad bad",
"bad happy happy happy happy happy happy happy"}),3);
		eq(6,(new Pareto()).optima(new String[] { "happy bad awful ecstatic fair bad fair awful",
 "fair awful bad awful ecstatic awful bad awful",
 "awful awful happy awful ecstatic awful bad fair",
 "bad bad bad happy happy ecstatic awful ecstatic",
 "bad bad awful awful fairly-happy fair fair happy",
 "fair bad bad fair happy bad ecstatic fair"}),6);
		eq(7,(new Pareto()).optima(new String[] { "fair happy fair fairly-happy happy happy happy",
 "happy fair fairly-happy fair fair fair happy",
 "happy happy fair fair fairly-happy fair happy",
 "happy fair fair fairly-happy happy happy happy",
 "happy fair happy fairly-happy happy happy happy",
 "fair fair happy fair fair fair fairly-happy"}),3);
		eq(8,(new Pareto()).optima(new String[] { "ecstatic bad fair fair fair ecstatic ecstatic",
 "ecstatic happy ecstatic awful awful fair awful",
 "happy fairly-happy bad happy fair fair ecstatic",
 "awful happy fair fairly-happy fair fair bad",
 "awful fairly-happy fair bad happy happy happy",
 "happy happy bad fair happy ecstatic fairly-happy",
 "fair happy ecstatic bad fairly-happy fair fair",
 "fairly-happy bad awful bad awful bad ecstatic",
 "fairly-happy awful bad fair ecstatic bad awful",
 "fairly-happy bad bad bad awful awful fair",
 "awful bad bad ecstatic ecstatic fair bad",
 "fair bad bad fair ecstatic fair ecstatic",
 "bad awful happy happy fairly-happy happy happy",
 "ecstatic fair fair awful happy fair happy",
 "fairly-happy fair awful awful happy awful fair",
 "bad fair fair fairly-happy bad happy happy",
 "bad bad fair ecstatic fairly-happy ecstatic bad",
 "bad fair happy fair awful fair ecstatic",
 "awful bad bad awful bad awful fairly-happy",
 "fair fair ecstatic bad bad happy awful",
 "awful bad ecstatic awful fair fairly-happy happy",
 "happy bad fair awful awful ecstatic bad",
 "happy bad bad ecstatic fair fair bad",
 "bad fairly-happy bad awful fair happy ecstatic",
 "awful awful happy bad happy ecstatic bad",
 "awful fair awful awful ecstatic fair fair",
 "bad fairly-happy awful happy awful bad ecstatic",
 "ecstatic happy happy fair fairly-happy fair bad",
 "happy awful happy bad bad fairly-happy fair",
 "ecstatic fair awful awful awful bad fairly-happy",
 "fair fair bad fairly-happy awful fair fair",
 "fair fairly-happy bad happy happy awful fair",
 "happy ecstatic awful fair fair awful ecstatic",
 "ecstatic awful fair ecstatic ecstatic happy bad",
 "awful bad fair ecstatic happy awful fair",
 "ecstatic happy fair happy happy bad ecstatic",
 "bad awful awful awful happy ecstatic bad",
 "ecstatic fair fair bad awful ecstatic bad",
 "bad happy bad ecstatic bad awful happy",
 "fairly-happy bad ecstatic awful fair fair awful",
 "fairly-happy fair awful awful ecstatic bad fair",
 "fairly-happy bad happy bad fair happy happy",
 "happy ecstatic fair fairly-happy fair bad bad",
 "bad bad fairly-happy happy bad bad bad",
 "happy happy fair fair bad fair awful",
 "awful fair bad bad happy fair fair",
 "fair ecstatic happy happy awful fair bad",
 "awful fairly-happy happy fair happy awful bad",
 "awful fair bad happy happy ecstatic ecstatic",
 "bad bad fair ecstatic happy ecstatic ecstatic"}
),35);
		eq(9,(new Pareto()).optima(new String[] {"fair happy fairly-happy",
 "fair happy fair",
 "awful ecstatic fair",
 "awful ecstatic fair",
 "fair happy fair",
 "fair happy fair"
}),3);
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
