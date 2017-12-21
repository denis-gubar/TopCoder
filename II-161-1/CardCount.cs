using System;
using System.Text;
using System.Collections;
 
public class CardCount
{
    public string[] dealHands( int numPlayers, string deck )
    {
		string[] result = new string[numPlayers];
		for( int i = 0; i < numPlayers; i++ )
		{
			result[i] = "";
		}
		for( int i = 0; i < deck.Length / numPlayers * numPlayers; i++ )
		{
			result[i % numPlayers] += deck[i];
		}                                     		
        return result;
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    try
    {
		eq(1,(new CardCount()).dealHands(6, "012345012345012345"),new String[] { "000",  "111",  "222",  "333",  "444",  "555" });
		eq(2,(new CardCount()).dealHands(4, "111122223333"),new String[] { "123",  "123",  "123",  "123" });
		eq(3,(new CardCount()).dealHands(1, "012345012345012345"),new String[] { "012345012345012345" });
		eq(4,(new CardCount()).dealHands(6, "01234"),new String[] { "",  "",  "",  "",  "",  "" });
		eq(5,(new CardCount()).dealHands(2, ""),new String[] { "",  "" });
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
 
