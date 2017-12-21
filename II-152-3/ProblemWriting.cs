using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

enum States { s0, s1, s2, s3 };

public class ProblemWriting
{
    public string myCheckData( string dotForm )
    {
		if ( dotForm.Length == 0 || dotForm.Length > 25 )
		{
			return "dotForm must contain between 1 and 25 characters, inclusive.";
		}
		States s = States.s0;
		int i = 0;
		while( i < dotForm.Length )
		{
			switch( s )
			{
				case States.s0:
					if ( dotForm[i] >= '0' && dotForm[i] <= '9' )
					{
						s = States.s1;
					}
					else
					{
						return "dotForm is not in dot notation, check character " + i.ToString() + ".";
					}
					break;
				case States.s1:
					if ( dotForm[i] == '.' )
					{
						s = States.s2;
					}
					else if ( dotForm[i] == '+' || dotForm[i] == '/' || dotForm[i] == '*' || dotForm[i] == '-' )
					{
						s = States.s3;
					}
					else
					{
						return "dotForm is not in dot notation, check character " + i.ToString() + ".";
					}
					break;
				case States.s2:
					if ( dotForm[i] == '.' )
					{
						s = States.s2;
					}
					else if ( dotForm[i] == '+' || dotForm[i] == '/' || dotForm[i] == '*' || dotForm[i] == '-' )
					{
						s = States.s3;
					}
					else
					{
						return "dotForm is not in dot notation, check character " + i.ToString() + ".";
					}
					break;
				case States.s3:
					if ( dotForm[i] >= '0' && dotForm[i] <= '9' )
					{
						s = States.s1;
					}
					else if ( dotForm[i] == '.' )
					{
						s = States.s3;
					}
					else
					{
						return "dotForm is not in dot notation, check character " + i.ToString() + ".";
					}
					break;
			}
			i++;
		}
		if ( s != States.s1 )
		{
			return "dotForm is not in dot notation, check character " + i.ToString() + ".";
		}
        return "";
    }

// BEGIN CUT HERE
  public static void Main(string[] args)
  {
    try
    {
		eq(1,(new ProblemWriting()).myCheckData("3+5"),"");
		eq(2,(new ProblemWriting()).myCheckData("9..+.5...*....3"),"");
		eq(3,(new ProblemWriting()).myCheckData("5.3+4"),"dotForm is not in dot notation, check character 2.");
		eq(4,(new ProblemWriting()).myCheckData("9*9*9*9*9*9*9*9*9*9*9*9*9*9"),"dotForm must contain between 1 and 25 characters, inclusive.");
		eq(5,(new ProblemWriting()).myCheckData("3.........../...........4"),"");
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
