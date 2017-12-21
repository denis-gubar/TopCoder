using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

#region class Permutations
public class Permutations
{
	public int size;
	public int[] Permutation;
	public int[] Pointers;
	public bool[] Directions;
	public int[] Inversions;
	private bool isBegin = true;
	public int a;
	public int b;

	public Permutations( int size )
	{
		this.size = size;
		Permutation = new int[size];
		Pointers = new int[size];
		Directions = new bool[size];
		Inversions = new int[size];
		for( int i = 0; i < size; i++ )
		{
			Permutation[i] = i;
			Inversions[i] = 0;
			Directions[i] = true;
			Pointers[i] = i;
		}
	}
	private void swap( ref int a, ref int b )
	{
		int temp = a; a = b; b = temp;
	}
	public bool Next()
	{
		if ( isBegin )
		{
			isBegin = false; return true;
		}
		int i = size - 1;
		while( (i >= 0) && ((Directions[i] && (Inversions[i] == i)) || (!Directions[i] && (Inversions[i] == 0))) )
			i--;
		if ( i < 0 ) return false;
		for( int k = i + 1; k < size; k++ )
			Directions[k] = !Directions[k];
		if ( Directions[i] )
		{
			Inversions[i]++;
			a = Pointers[i]; b = Pointers[Permutation[Pointers[i] - 1]];
			swap( ref Pointers[Permutation[Pointers[i] - 1]], ref Pointers[i] );
			swap( ref Permutation[a], ref Permutation[b] );
			a = Permutation[a]; b = Permutation[b];
		}
		else
		{
			Inversions[i]--;
			a = Pointers[i]; b = Pointers[Permutation[Pointers[i] + 1]];
			swap( ref Pointers[Permutation[Pointers[i] + 1]], ref Pointers[i] );
			swap( ref Permutation[a], ref Permutation[b] );
			a = Permutation[a]; b = Permutation[b];
		}
		return true;
	}
}
#endregion

public class SmartElevator 
{
	public int timeWaiting( int[] arrivalTime, int[] startingFloor, int[] destinationFloor ) 
	{
		int n = arrivalTime.Length;
		int bestTime = int.MaxValue;
		Permutations P = new Permutations( 2 * n );
		while( P.Next() )
		{
			bool flag = true;
			for( int i = 0; flag && i < n; i++ )
				flag = Array.IndexOf( P.Permutation, i ) < Array.IndexOf( P.Permutation, i + n );
			if ( !flag ) continue;
			int curTime = 0;
			int curFloor = 1;
			for( int i = 0; bestTime > curTime && i < 2 * n; i++ )
			{
				int k = P.Permutation[i] % n;
				int nextFloor = startingFloor[k];
				if ( P.Permutation[i] >= n )
					nextFloor = destinationFloor[k];
				int delta = Math.Abs( curFloor - nextFloor );
				if ( curTime < arrivalTime[k] )
				{
					if ( delta < arrivalTime[k] - curTime )
						delta = 0;
					else
						delta -= arrivalTime[k] - curTime;
					curTime = arrivalTime[k];
				}
				curTime += delta;
				curFloor = nextFloor;
			}
			if ( bestTime > curTime ) bestTime = curTime;
		}
		return bestTime;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new SmartElevator()).timeWaiting(new int[] {5}, new int[] {30}, new int[] {50}),49);
		eq(2,(new SmartElevator()).timeWaiting(new int[] {100}, new int[] {30}, new int[] {50}),120);
		eq(3,(new SmartElevator()).timeWaiting(new int[] {10,120}, new int[] {1,100}, new int[] {210,200}),230);
		eq(4,(new SmartElevator()).timeWaiting(new int[] {10,500}, new int[] {1,100}, new int[] {210,200}),600);
		eq(5,(new SmartElevator()).timeWaiting(new int[] {1000,1200,1600,2000,2400}, new int[] {500,500,500,500,500}, new int[] {700,300,700,300,700}),2600);
		eq(6,(new SmartElevator()).timeWaiting(new int[] {775397,261225,870141,287698,884334}, new int[] {82225,958610,998971,413596,21922}, new int[] {769962,78706,477861,237168,258488}),2724059);
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
