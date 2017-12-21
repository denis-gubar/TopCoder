using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Solid 
{
	public int surfaceArea( string[] solid ) 
	{
		int m = solid.Length;
		int n = solid[0].Length;
		int[,] M = new int[m + 2, n + 2];
		int result = 0;
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
			{
				M[i + 1, j + 1] = int.Parse( solid[i][j].ToString() );
				if ( M[i + 1, j + 1] > 0 )
					result += 2;
			}
		for( int i = 1; i < m + 2; i++ )
			for( int j = 1; j < n + 2; j++ )
				result += Math.Abs( M[i - 1, j] - M[i, j] ) + Math.Abs( M[i, j - 1] - M[i, j] );
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Solid()).surfaceArea(new String[] {"11"}),10);
		eq(2,(new Solid()).surfaceArea(new String[] {"4231",
 "2101",
 "0001"}),54);
		eq(3,(new Solid()).surfaceArea(new String[] {"0000000000000000000",
 "0000000111111111100",
 "0001111111111111100",
 "0111111222111110000",
 "0111111122111111000",
 "0111111111111111000",
 "0000000000000000000"}),190);
		eq(4,(new Solid()).surfaceArea(new String[] {"000000528711731016006000000000",
 "000005195794786382818000000000",
 "000000152759877615783700000000",
 "000000538691532646444720000000",
 "000448878233764358916526040000",
 "000957681868472329823514746000",
 "000468262265258953611195968000",
 "353414949614353741985971227000",
 "523414326739461146956185360000", 
 "883755114476244883219144444000",
 "382853216452287831155934152000",
 "582346653747546124514813113000",
 "872646187355968637442125842000",
 "488795678641528974985428554900",
 "184834779675978184943349141300",
 "466455559389179259181268463686",
 "577566824847934671312749443414",
 "879443115123574825441232482522",
 "813346335659785489878484611130",
 "913125858434291686688282682100",
 "276982916388781784196666212965",
 "171998843675177318752563287763",
 "639855577925843147586517873468",
 "527868897287142566166897778388",
 "513544481355194141741396768845",
 "148819842161491541656585512420",
 "014784988399688355411932978550",
 "008427963354683469419487790000",
 "007889062567387593411210000000",
 "000000005778849898967400000000"}),6280);
		eq(5,(new Solid()).surfaceArea(new String[] {"111",
 "101",
 "111"}),32);
		eq(6,(new Solid()).surfaceArea(new String[] {"5"}),22);
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
