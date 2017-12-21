using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Gems
{
	int m;
	int n;
	char[,] M;

	void swap( ref char x, ref char y )
	{
		char t = x; x = y; y = t;
	}

	bool probe( int x, int y, char c )
	{
		return !(x < 0 || y < 0 || x >= m || y >= n || M[x, y] != c);
	}

	bool scan( int x, int y )
	{
		char c = M[x, y];
		int count = 0;
		int i = x - 1;
		while( probe( i, y, c ) )
		{
			count++; i--;
		}
		i = x + 1;
		while( probe( i, y, c ) )
		{
			count++; i++;
		}
		if ( count >= 2 ) return true;
		count = 0;
		i = y - 1;
		while( probe( x, i, c ) )
		{
			count++; i--;
		}
		i = y + 1;
		while( probe( x, i, c ) )
		{
			count++; i++;
		}
		return count >= 2;
	}

	public int numMoves( string[] board )
	{
		m = board.Length;
		n = board[0].Length;
		M = new char[m, n];
		int result = 0;
		for(int i = 0; i < m; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				M[i, j] = board[i][j];
			}
		}
		for(int i = 0; i < m; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				if ( i < m - 1 )
				{
					swap( ref M[i, j], ref M[i + 1, j] );
					if ( scan(i, j) || scan(i + 1, j) ) result++;
					swap( ref M[i, j], ref M[i + 1, j] );
				}
				if ( j < n - 1 )
				{
					swap( ref M[i, j], ref M[i, j + 1] );
					if ( scan(i, j) || scan(i, j + 1) ) result++;
					swap( ref M[i, j], ref M[i, j + 1] );
				}
			}
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Gems()).numMoves(new String[] {"ABC",
 "ABC",
 "BAD"}),1);
		eq(2,(new Gems()).numMoves(new String[] {"ABB",
 "BAA",
 "ABB"}),3);
		eq(3,(new Gems()).numMoves(new String[] {"ABA",
 "BAB",
 "ABA"}),4);
		eq(4,(new Gems()).numMoves(new String[] {"ABC",
 "DEF",
 "GHI"}),0);
		eq(5,(new Gems()).numMoves(new String[] {"SUMEEMEEPGPPG",
 "USPMIPSUSIISG",
 "UPSPGEGGPKEII",
 "KEMGISMKKIUIG",
 "MGSIIKMSISGKM",
 "SPGMSMIGMSMGM",
 "SSIIUKMPEPPUI",
 "UKUIUEMEEIGKE",
 "IPUPGUSEGSSUS",
 "EUPMKGGUKKEMI",
 "PEPSMUUEUSSIP",
 "SUMEEUSESUEKG",
 "EPSKUISGMSKGI",
 "IUGGUGGSIGUUP",
 "IUPIKKSGPPEEP",
 "KGEESGISPGGEM",
 "UEIUSSKPSSGPE",
 "KSUMKGEIMKPSE",
 "ESKEUEMMPPIGG",
 "UUIEUGGIGMEMK",
 "GPGMPPIUMEPMU",
 "IKIGGPIUEMIGS",
 "IPUSGUMKPKIPP",
 "UEEMUUEEGIPUS",
 "PPEKIKEMGGMSS",
 "EMKPMPUUMKEPU",
 "UKPGPKSUIEUPM",
 "PSUUMUKGIIPMS",
 "ESMGSKUEPGGEM",
 "SMEEIKGKGGPEG",
 "UEIEKPMESMEPP",
 "IPUIMGGMIPKMG",
 "ISSEKPKGKIUGU",
 "SSESKUGKISPUK"}),83);
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
