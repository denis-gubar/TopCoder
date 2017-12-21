using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class Birthday
{
    public string getNext( string date, string[] birthdays )
    {
		string[] dates = new string[birthdays.Length];
		int i = 0;
		for( i = 0; i < birthdays.Length; i++ )
		{
			string[] x = birthdays[i].Split();
			dates[i] = x[0];
		}
		Array.Sort( dates );
		i = 0;
		while( i < birthdays.Length && dates[i].CompareTo( date ) < 0 )
		{
			i++;
		}
		if ( i == birthdays.Length ) return dates[0];
        return dates[i];
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    try
    {
		eq(1,(new Birthday()).getNext("06/17", new String[] {"02/17 Wernie", "10/12 Stefan"}),"10/12");
		eq(2,(new Birthday()).getNext("06/17", new String[] {"10/12 Stefan"}),"10/12");
		eq(3,(new Birthday()).getNext("02/17", new String[] {"02/17 Wernie", "10/12 Stefan"}),"02/17");
		eq(4,(new Birthday()).getNext("12/24", new String[] {"10/12 Stefan"}),"10/12");
		eq(5,(new Birthday()).getNext("01/02", new String[] {"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"}),"02/17");
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
