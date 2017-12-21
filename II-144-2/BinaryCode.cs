using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class BinaryCode
{
	private int getDigit( string s, int i )
	{
		if ( i < 0 ) return 0;
		if ( i >= s.Length ) return 0;
		return int.Parse( s[i].ToString() );
	}
    public string[] decode( string message )
    {
		string a = "0";
		string b = "1";
		for( int i = 0; i < message.Length - 1; i++ )
		{
			int x = getDigit( message, i ) - getDigit( a, i - 1 ) - getDigit( a, i );			
			if ( x != 0 && x != 1 )
			{
				a = "NONE";
				break;
			}
			a += x.ToString();
		}
		if ( a != "NONE" && getDigit( message, message.Length - 1 ) != 
			getDigit( a, message.Length - 1 ) + getDigit( a, message.Length - 2 ) )
		{
			a = "NONE";
		}
		for( int i = 0; i < message.Length - 1; i++ )
		{
			int x = getDigit( message, i ) - getDigit( b, i - 1 ) - getDigit( b, i );			
			if ( x != 0 && x != 1 )
			{
				b = "NONE";
				break;
			}
			b += x.ToString();
		}
		if ( b != "NONE" && getDigit( message, message.Length - 1 ) != 
			getDigit( b, message.Length - 1 ) + getDigit( b, message.Length - 2 ) )
		{
			b = "NONE";
		}
		return new string[] {a, b};
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    try
    {
		eq(1,(new BinaryCode()).decode("123210122"),new String[] { "011100011",  "NONE" });
		eq(2,(new BinaryCode()).decode("11"),new String[] { "01",  "10" });
		eq(3,(new BinaryCode()).decode("22111"),new String[] { "NONE",  "11001" });
		eq(4,(new BinaryCode()).decode("123210120"),new String[] { "NONE",  "NONE" });
		eq(5,(new BinaryCode()).decode("3"),new String[] { "NONE",  "NONE" });
		eq(6,(new BinaryCode()).decode("12221112222221112221111111112221111"),new String[] { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" });
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
