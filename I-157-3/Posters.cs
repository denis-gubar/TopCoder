using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

#region class Permutations
public class Permutations
{
	private static long[] factorial;
	static Permutations()
	{
		factorial = new long[21];
		factorial[0] = 1;
		for( int i = 1; i < 21; i++ )
			factorial[i] = factorial[i - 1] * i;
	}
	public static int[] Permutation( long size, long M )
	{
		int[] result = new int[size];
		long factorial = Permutations.factorial[size];
		for( int i = 0; i < size; i++ )
			result[i] = i;
		for( int i = 1; i < size; i++ )
		{
			factorial /= size - i + 1;
			int x = (int) (i + M / factorial - 1);
			long temp = result[x];
			for( int j = x; j >= i; j-- )
				result[j] = result[j - 1];
			result[i - 1] = (int) temp;
			M %= factorial;
		}
		return result;
	}
	public static long Number( int[] A )
	{
		long result = 0;
		long factorial = Permutations.factorial[A.Length];
		for( int i = 0; i < A.Length - 1; i++ )
		{
			factorial /= A.Length - i;
			int count = A[i];
			for( int j = 0; j < i; j++ )
				if ( A[j] < A[i] ) count--;
			result += factorial * count;
		}
		return result;			
	}
	public static bool Next( int[] A )
	{
		int k = A.Length - 1;
		while( k > 0 && A[k - 1] > A[k] )
			k--;
		if ( k == 0 ) return false;
		k--;
		int t = k + 1;
		while( t < A.Length - 1 && A[t + 1] > A[k] )
			t++;
		int temp = A[k];
		A[k] = A[t];
		A[t] = temp;
		t = 0;
		while( t < (A.Length - 1 - k) / 2 )
		{
			temp = A[A.Length - t - 1];
			A[A.Length - t - 1] = A[t + k + 1];
			A[t + k + 1] = temp;
			t++;
		}
		return true;
	}
}
#endregion
public class Rect
{
	public Rect(int x, int y, int width, int height):
		this(x, y, width, height, 1, 0)	{}

	private Rect(int x, int y, int width, int height, int sign, int label)
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.sign = sign;
		this.label = label;
	}

	public int x;
	public int y;
	public int width;
	public int height;
	private int sign;
	private int label;
	public int area
	{
		get
		{
			return Math.Max( width, 0 ) * Math.Max( height, 0 ) * sign;
		}
	}

	public void intersect( Rect R )
	{
		if ( area != 0 )
		{
			int ax = Math.Max( R.x, x );
			int ay = Math.Max( R.y, y );
			width = Math.Min( R.x + R.width, x + width ) - ax;
			height = Math.Min( R.y + R.height, y + height ) - ay;
			x = ax;
			y = ay;
		}
	}

	static public int unionArea( Rect[] R )
	{
		int result = 0;
		int n = R.Length;
		Queue Q = new Queue();
		for( int i = 0; i < n; i++ )
			Q.Enqueue( new Rect( R[i].x, R[i].y, R[i].width, R[i].height, 1, i ) );
		while( Q.Count > 0 )
		{
			Rect A = (Rect) Q.Dequeue();
			if ( A.area == 0 ) continue;
			result += A.area;
			for( int i = A.label + 1; i < n; i++ )
			{
				int ax = Math.Max( R[i].x, A.x );
				int ay = Math.Max( R[i].y, A.y );
				Q.Enqueue( new Rect( ax, ay, Math.Min( R[i].x + R[i].width, A.x + A.width ) - ax,
					Math.Min( R[i].y + R[i].height, A.y + A.height ) - ay, -A.sign, i ) );
			}
		}
		return result;
	}
}

public class Point
{
	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	public int x;
	public int y;
}

public class Posters 
{
	private int width;
	private int height;
	private int[] X;
	private int[] Y;
	private Rect border;
	private int result;
	int n;
	private void calc( ArrayList Points, int i, Rect[] R )
	{
		if ( i == n )
		{
			result = Math.Max( result, Rect.unionArea( R ) );
			return;
		}
		Rect[] M = new Rect[i];
		Array.Copy( R, M, i );
		int restArea = 0;
		for( int j = i; j < n; j++ )
			restArea += X[j] * Y[j];
		if ( Rect.unionArea( M ) + restArea < result ) return;
		for( int j = 0; j < Points.Count; j++ )
		{
			ArrayList newPoints = (ArrayList) Points.Clone();
			Point P = (Point) Points[j];
			R[i] = new Rect(P.x, P.y, X[i], Y[i]);
			R[i].intersect( border );
			if ( R[i].area != 0 )
			{
				newPoints.RemoveAt( j );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x, R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y ) );
				calc( newPoints, i + 1, R );
			}
			R[i] = new Rect(P.x - X[i], P.y, X[i], Y[i]);
			R[i].intersect( border );
			if ( R[i].area != 0 )
			{
				newPoints.RemoveAt( j );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x, R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y ) );
				calc( newPoints, i + 1, R );
			}
			R[i] = new Rect(P.x, P.y - Y[i], X[i], Y[i]);
			R[i].intersect( border );
			if ( R[i].area != 0 )
			{
				newPoints.RemoveAt( j );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x, R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y ) );
				calc( newPoints, i + 1, R );
			}
			R[i] = new Rect(P.x - X[i], P.y - Y[i], X[i], Y[i]);
			R[i].intersect( border );
			if ( R[i].area != 0 )
			{
				newPoints.RemoveAt( j );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x, R[i].y + Y[i] ) );
				newPoints.Add( new Point(R[i].x + X[i], R[i].y ) );
				calc( newPoints, i + 1, R );
			}
		}
	}

	public int maxCover( int width, int height, int[] pWidth, int[] pHeight ) 
	{
		this.width = width;
		this.height = height;
		n = pWidth.Length;
		if ( n == 1 ) return (new Rect( 0, 0, pWidth[0], pHeight[0] )).area;
		if ( n == 2 ) return Rect.unionArea( new Rect[] 
			{
				new Rect(0, 0, pWidth[0], pHeight[0]),
				new Rect(width - pWidth[1], height - pHeight[1], pWidth[1], pHeight[1] )} );
		border = new Rect(0, 0, width, height);
		X = new int[n];
		Y = new int[n];
		Rect[] R = new Rect[n];
		result = 0;
		int[] P = Permutations.Permutation( n, 0 );
		do
		{
			for( int i = 0; i < n; i++ )
			{
				X[i] = pWidth[P[i]];
				Y[i] = pHeight[P[i]];
			}
			R[0] = new Rect(0, 0, X[0], Y[0]);
			R[1] = new Rect(width - X[1], height - Y[1], X[1], Y[1] );
			ArrayList A = new ArrayList();
			A.Add( new Point( R[0].width, 0) );
			A.Add( new Point( 0, R[0].height) );
			A.Add( new Point( width - R[1].width, height ) );
			A.Add( new Point( width, height - R[1].height ) );
			calc( A, 2, R );
		} while( Permutations.Next( P ) );
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		DateTime t1 = DateTime.Now;
		eq(1,(new Posters()).maxCover(10, 10, new int[] {7,4,1,8}, new int[] {3,5,3,4}),74);
		eq(2,(new Posters()).maxCover(90, 80, new int[] {64,51}, new int[] {42,51}),4964);
		eq(3,(new Posters()).maxCover(8, 6, new int[] {6,6,2,4,2}, new int[] {2,2,4,2,4}),48);
		eq(4,(new Posters()).maxCover(100, 93, new int[] {68,50,18,52,62}, new int[] {27,15,37,45,50}),8256);
		eq(5,(new Posters()).maxCover(19, 20, new int[] {1,2,4,8,16}, new int[] {1,2,4,8,16}),321);
		eq(6,(new Posters()).maxCover(40, 30, new int[] {35}, new int[] {25}),875);
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
