using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

class Pair:IComparable
{
	public string name;
	public int i;

	public Pair( string name, int i )
	{
		this.name = name; this.i = i;
	}

	#region IComparable Members

	public int CompareTo(object obj)
	{
		Pair p = (Pair) obj;
		string[] x1 = name.Split();
		string[] x2 = p.name.Split();
		string s1 = x1[x1.Length - 1].ToUpper();
		string s2 = x2[x2.Length - 1].ToUpper();
		if ( s1.CompareTo( s2 ) != 0 ) return s1.CompareTo( s2 );
		return -i.CompareTo( p.i );
	}

	#endregion

}


public class NameSort
{
	public string[] newList( string[] list )
	{
		Pair[] sortedList = new Pair[list.Length];
		for( int i = 0; i < list.Length; i++ )
		{
			sortedList[i] = new Pair( list[i], i );
		}
		Array.Sort( sortedList );
		for( int i = 0; i < list.Length; i++ )
		{
			list[i] = sortedList[i].name;
		}
		return list;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new NameSort()).newList(new String[] {"Tom Jones","ADAMS","BOB ADAMS",
"Tom Jones","STEVE jONeS"}
),new String[] { "BOB ADAMS",  "ADAMS",  "STEVE jONeS",  "Tom Jones",  "Tom Jones" });
		eq(2,(new NameSort()).newList(new String[] {"C A R Hoare","Kenny G",
"A DeForest Hoar","Kenny Gee"}),new String[] { "Kenny G",  "Kenny Gee",  "A DeForest Hoar",  "C A R Hoare" });
		eq(3,(new NameSort()).newList(new String[] {"Trudy","Trudy","TRUDY"}),new String[] { "TRUDY",  "Trudy",  "Trudy" });
		eq(4,(new NameSort()).newList(new String[] {"tIm JoNeS", "Tim Jones", "tom JoNes", "tim joness", "tiM joneS"}),new String[] { "tiM joneS",  "tom JoNes",  "Tim Jones",  "tIm JoNeS",  "tim joness" });
		eq(5,(new NameSort()).newList(new String[] {"Alan","aLan","alAn","alaN","ALan","AlAn","AlaN","aLAn","aLaN","alAN"}),new String[] { "alAN",  "aLaN",  "aLAn",  "AlaN",  "AlAn",  "ALan",  "alaN",  "alAn",  "aLan",  "Alan" });
		eq(6,(new NameSort()).newList(new String[] {"Al Thompson","Bob Johnson", "John Thompson", "John D Thompson","Bob D Johnson"}),new String[] { "Bob D Johnson",  "Bob Johnson",  "John D Thompson",  "John Thompson",  "Al Thompson" });
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
