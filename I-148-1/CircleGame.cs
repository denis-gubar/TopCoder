using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class CircleGame
{
	private string names = "A23456789TJQ";

	private bool check( char a, char b )
	{
		int x = 0;
		int y = 0;
		for( int i = 0; i < names.Length; i++ )
		{
			if ( names[i] == a ) x = i;
			if ( names[i] == b ) y = i;
		}
		return x + y == 11;
	}

    public int cardsLeft( string deck )
    {
		int result = 0;
		deck = deck.Replace( "K", "" );
		if ( deck.Length < 2 ) return deck.Length;
		while( result != deck.Length )
		{
			result = deck.Length;
			int i = 1;
			while( i < deck.Length )
			{
				if ( check( deck[i - 1], deck[i] ) )
				{
					deck = deck.Remove( i - 1, 2 ); i = 0;
				}
				i++;
			}
			if ( deck.Length > 1 && check( deck[0], deck[deck.Length - 1] ) )
			{
				deck = deck.Substring( 1 );
				deck = deck.Substring( 0, deck.Length - 1 );
			}
		}
		result = deck.Length;
        return result;
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    try
    {
		eq(1,(new CircleGame()).cardsLeft("KKKKKKKKKK"),0);
		eq(2,(new CircleGame()).cardsLeft("KKKKKAQT23"),1);
		eq(3,(new CircleGame()).cardsLeft("KKKKATQ23J"),6);
		eq(4,(new CircleGame()).cardsLeft("AT68482AK6875QJ5K9573Q"),4);
		eq(5,(new CircleGame()).cardsLeft("AQK262362TKKAQ6262437892KTTJA332"),24);
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
