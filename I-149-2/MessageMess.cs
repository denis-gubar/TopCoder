using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class MessageMess
{
    public string restore( string[] dictionary, string message )
    {
        int[] M = new int[message.Length];
		int i = 0;
		for( i = 0; i < message.Length; i++ )
		{
			for( int j = 0; j < dictionary.Length; j++ )
			{
				if ( message.Substring( 0, i + 1 ) == dictionary[j] )
				{
					M[i] += 1;
					M[i] = M[i] > 1 ? 2 : M[i];
				} else if ( message.Substring( 0, i + 1 ).EndsWith( dictionary[j] ) )
				{
					M[i] += M[i - dictionary[j].Length];
					M[i] = M[i] > 1 ? 2 : M[i];
				}				
			}
		}
		i = message.Length - 1;
		if ( M[i] > 1 ) return "AMBIGUOUS!";
		if ( M[i] == 0 ) return "IMPOSSIBLE!";
		string result = "";
		while( i >= 0 )
		{
			for( int j = 0; j < dictionary.Length; j++ )
			{
				if ( message.Substring( 0, i + 1 ) == dictionary[j] )
				{
					if ( result != "" ) result = " " + result;
					result = dictionary[j] + result;
					i = -1;
				} else if (message.Substring( 0, i + 1 ).EndsWith( dictionary[j] ) && M[i - dictionary[j].Length] == 1 )
				{
					if ( result != "" ) result = " " + result;
					result = dictionary[j] + result;
					i -= dictionary[j].Length;
				}
			}
		}
		return result;
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
//    try
    {
		eq(1,(new MessageMess()).restore(new String[] {"HI", "YOU", "SAY"}, "HIYOUSAYHI"),"HI YOU SAY HI");
		eq(2,(new MessageMess()).restore(new String[] {"ABC", "BCD", "CD", "ABCB"}, "ABCBCD"),"AMBIGUOUS!");
		eq(3,(new MessageMess()).restore(new String[] {"IMPOSS", "SIBLE", "S"}, "IMPOSSIBLE"),"IMPOSSIBLE!");
		eq(4,(new MessageMess()).restore(new String[] {"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"}, "IMPOSSIBLE"),"IMPOSSIBLE");
    }
//    catch(Exception e)
    {
//	Console.WriteLine(e.Message);
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
