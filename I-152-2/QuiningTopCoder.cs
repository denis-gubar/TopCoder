using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class QuiningTopCoder 
{
	Stack S = new Stack();
	bool isOverflow = false;

	void push( int x )
	{
		if ( x > 1000000000 || x < -1000000000 ) isOverflow = true;
		S.Push( x );
	}

	int pop()
	{
		return S.Count > 0 ? (int) S.Pop() : 0;
	}

	public string testCode( string source ) 
	{
		int N = source.Length;
		int IP = 0;
		int D = 1;
		bool change_IP = false;
		bool change_D = true;
		string result = "";
		for( int i = 0; i < 80000; i++ )
		{
			int x, a, b;
			if ( change_IP ) IP = (3 * N + IP + D) % N;
			else change_IP = true;
			if ( !change_D ) D /= 2;
			change_D = true;
			switch( source[IP] )
			{
				case '$':
					pop();
					break;
				case ':':
					x = pop(); push( x ); push( x );
					break;
				case 'W':
					a = pop(); b = pop(); push( a ); push( b );
					break;
				case ',':
					x = pop(); char c = source[Math.Abs( x ) % N];
					if ( c != source[result.Length] )
						return "MISMATCH " + i.ToString();
					result += c;
					if ( result == source ) 
						return "QUINES " + i.ToString();
					break;
				case '+':
					a = pop(); b = pop(); push( a + b );
					break;
				case '-':
					a = pop(); b = pop(); push( a - b );
					break;
				case '#':
					D *= 2; change_D = false;
					break;
				case 'R':
					D = -D;
					break;
				case 'S':
					x = pop(); if ( x > 0 ) push( 1 ); else push( -1 );
					break;
				case '_':
					x = pop(); D = x % N;
					break;
				case 'J':
					x = pop(); IP = Math.Abs(x) % N; change_IP = false;
					break;
				case '@':
					return "BADEND " + i.ToString();
				default:
					push( int.Parse( source[IP].ToString() ) );
					break;
			}
			if ( isOverflow )  return "OVERFLOW " + i.ToString();
		}
		return "TIMEOUT";
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new QuiningTopCoder()).testCode(","),"QUINES 0");
		eq(2,(new QuiningTopCoder()).testCode("_"),"TIMEOUT");
		eq(3,(new QuiningTopCoder()).testCode("1:+:1J"),"OVERFLOW 147");
		eq(4,(new QuiningTopCoder()).testCode("0,1+:#@:$1J"),"QUINES 91");
		eq(5,(new QuiningTopCoder()).testCode("0,1+::9W-9W-S1W1W:+2_J_@_@"),"BADEND 437");
		eq(6,(new QuiningTopCoder()).testCode("#R,#:+1+:#,R#"),"QUINES 97");
		eq(7,(new QuiningTopCoder()).testCode("R,#1+1:"),"MISMATCH 7");
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
