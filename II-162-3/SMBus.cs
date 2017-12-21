using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

class Pair: IComparable
{
	public string message;
	public int time;

	public Pair( string m, int t )
	{
		message = m; time = t;
	}

	public int CompareTo( object o )
	{
		Pair p = (Pair) o;
		return message.CompareTo( p.message );
	}
}
 
public class SMBus
{
	public int transmitTime( string[] messages, int[] times )
	{
		int n = messages.Length;
		Pair[] p = new Pair[n];
		for( int i = 0; i < n; i++ )
		{
			p[i] = new Pair( messages[i], times[i] );
		}
		Array.Sort( p );
		int result = 0;
		for( int i = 0; i < n; i++ )
		{
			int speed = 0;
			int initialspeed = 0;
			int last = n - 1;
			for( int j = 0; j < p[i].message.Length; j++ )
			{
				int newspeed = 0;
				int t = last;
				for( int k = i; k <= last; k++ )
				{
					if ( p[k].message.Length > j )
					{
						if ( speed == 0 && initialspeed < p[k].time ) initialspeed = p[k].time;
						if ( p[k].message[j] == p[i].message[j] && newspeed < p[k].time ) newspeed = p[k].time;
						if ( p[k].message[j] != p[i].message[j] ) t = t < k - 1 ? t : k - 1;
					}
				}
				last = t;
				if ( speed == 0 ) speed = initialspeed;
				result += speed;
				speed = newspeed;
			}
		}		
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		try
		{
			DateTime t1 = DateTime.Now;
		eq(1,(new SMBus()).transmitTime(new String[] {"123","124","134"}, new int[] {1,2,3}),25);
		eq(2,(new SMBus()).transmitTime(new String[] {"012", "1234", "1233", "1223", "1123"}, new int[] {4,1,5,2,9}),94);
		eq(3,(new SMBus()).transmitTime(new String[] {"0002019289019101039663222896280025447",
 "00201873554718989597528841094293294387326",
 "010699029378761", "0110118", "011143279122561420",
 "001046384966198", "00200570375817801109530240012",
 "0003163277589822", "01100240744590150136673219652442108",
 "012033596872642679096489479354", "0121059494098",
 "00001002303019117948961792176", "00216399923558", "02014",
 "00224999120803846121427603894967637446889670369",
 "01101009414735635151893037596051740080475886",
 "0000101211809647472761605153430927981533514",
 "176845042961739039392207791589",
 "02000047506929386333221966659552927385017901842706",
 "021001117450487502127241076595509511",
 "021010776262723557108100899515",
 "0210114830738951774606917781619656",
 "0211798433083855430", "00000005842153604632996228135814",
 "0001000766929248550736138555144997170272757787",
 "0001010247593342056062432721557",
 "01100004828618452515832113396660046634951",
 "0132559984733529872911444204991646138116334788",
 "0224149857349431864906523152249992",
 "00001142929552573133212195441932219",
 "0011090498947092002457447355036811372647896489218",
 "000001275414757476198997466", "00010014",
 "00111025861963467834393486017602553072649743",
 "000102085", "00120882661783539",
 "01100018938145727291185020",
 "01100191373790478446634214244459341793", "0001129060",
 "001111287431066271555393813846448",
 "011010160778408696098486370196313", "0002125146381515395"}, new int[] {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64}),71048);
			DateTime t2 = DateTime.Now;
			TimeSpan t = t2 - t1;
			Console.WriteLine( t.TotalMilliseconds / 1000 );
		}
		catch(Exception e)
		{
			Console.WriteLine(e.Message);
		}
	}
	private static void eq(int n, int a, int b)
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
