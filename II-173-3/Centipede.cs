using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

public class Centipede 
{
	public string[] simulate( string[] screenLayout, int timeUnits ) 
	{
		string[] result = (string[]) screenLayout.Clone();
		int n = screenLayout.Length;
		int m = screenLayout[0].Length;
		int x = 10;
		int y = 0;
		int dir = 1;
		int k = 9;
		while( y < n )
		{
			k++;
			if ( screenLayout[y][x + dir] == ' ' ) x += dir;
			else if ( y < n - 1 && screenLayout[y + 1][x] == ' ' )
			{
				dir = -dir;	y++;
			}
			else if ( y < n - 1 ) dir = -dir;
			else y++;
		}
		timeUnits %= k;
		x = 10;
		y = 0;
		dir = 1;
		k = 0;
		while( k < timeUnits - 10 )
		{
			k++;
			if ( screenLayout[y][x + dir] == ' ' ) x += dir;
			else if ( y < n - 1 && screenLayout[y + 1][x] == ' ' )
			{
				dir = -dir;	y++;
			}
			else if ( y < n - 1 ) dir = -dir;
			else y++;
		}		
		if ( timeUnits < 10 )
		{
			x = timeUnits;
			k = timeUnits - 10;
		}
		while( k < timeUnits )
		{
			k++;
			if ( y == n ) continue;
			if ( screenLayout[y][x + dir] == ' ' ) x += dir;
			else if ( y < n - 1 && screenLayout[y + 1][x] == ' ' )
			{
				dir = -dir;	y++;
			}
			else if ( y < n - 1 ) dir = -dir;
			else y++;
			if ( y < n ) result[y] = result[y].Remove( x, 1 ).Insert( x, "x" );
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Centipede()).simulate(new String[] {"#                #",
 "# #      #       #",
 "#   #    #   #   #",
 "#           #    #",
 "#   ##         # #",
 "# #      ##      #",
 "#    #           #",
 "#                #"}, 24),new String[] { "#                #",  "# #      #       #",  "#   #    #xxx#   #",  "#         xx#    #",  "#   ##   xxx   # #",  "# #      ##      #",  "#    #           #",  "#                #" });
		eq(2,(new Centipede()).simulate(new String[] {"#          #",
 "#          #"}, 16),new String[] { "#          #",  "#xxxx      #" });
		eq(3,(new Centipede()).simulate(new String[] {"#            #",
 "#     #      #",
 "#            #"}, 24),new String[] { "#xxxxxxxxxx  #",  "#     #      #",  "#            #" });
		eq(4,(new Centipede()).simulate(new String[] {"#                        #",
 "#      #                 #",
 "#                 #      #",
 "#  ##    #               #",
 "#              #    #    #",
 "#     #                  #",
 "#       #          #     #",
 "#          #             #",
 "#              #         #"}, 74607),new String[] { "#                        #",  "#      #                 #",  "#                 #      #",  "#  ##    #               #",  "#              #    #    #",  "#     #xxxxxxx           #",  "#      x#          #     #",  "#     xx   #             #",  "#              #         #" });
		eq(5,(new Centipede()).simulate(new String[] {"#                            #",
 "#   #     # # #           # ##",
 "#   #       #                #",
 "#                          # #",
 "#                   #        #",
 "##    #           #        # #",
 "#    #    #   #              #",
 "#  #    #  #          #      #",
 "#     #   #       #          #",
 "#                            #",
 "#     #        #         #   #",
 "#   ###          #        #  #",
 "#           ##             # #",
 "#                     #      #",
 "##           #               #",
 "#     #     #   #     # #    #",
 "#          #  ##   #         #",
 "#                    #       #",
 "#                    #  #    #"}, 598273167),new String[] { "#                            #",  "#   #     # # #           # ##",  "#   #       #                #",  "#                          # #",  "#                   #        #",  "##    #           #        # #",  "#    #    #   #              #",  "#  #    #  #          #      #",  "#     #   #       #          #",  "#                         xxx#",  "#     #        #         #xxx#",  "#   ###          #        # x#",  "#           ##             # #",  "#                     #      #",  "##           #               #",  "#     #     #   #     # #    #",  "#          #  ##   #         #",  "#                    #       #",  "#                    #  #    #" });
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
