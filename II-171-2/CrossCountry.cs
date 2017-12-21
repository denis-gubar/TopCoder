using System;
using System.Collections;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

class Pair: IComparable
{
	public int x5;
	public int x6;
	public string name;

	public Pair( int a, int b, string s )
	{
		x5 = a; x6 = b; name = s;
	}

	public int CompareTo(object obj)
	{
		Pair p = (Pair) obj;
		if ( x5.CompareTo( p.x5 ) != 0 ) return x5.CompareTo( p.x5 );
		if ( x6.CompareTo( p.x6 ) != 0 ) return x6.CompareTo( p.x6 );
		return name.CompareTo( p.name );
	}
}


public class CrossCountry 
{
	public string scoreMeet( int numTeams, string finishOrder ) 
	{
		string result = "";
		int[] count = new int[256];
		int[] s5 = new int[256];
		int[] s6 = new int[256];
		for( int i = 0; i < finishOrder.Length; i++ )
		{
			count[finishOrder[i]]++;
			if ( count[finishOrder[i]] < 6 ) s5[finishOrder[i]] += i + 1;
			if ( count[finishOrder[i]] == 6 ) s6[finishOrder[i]] = s5[finishOrder[i]] + i + 1;
		}
		ArrayList A = new ArrayList();
		for( char c = 'A'; c <= 'Z'; c++ )
		{
			if ( count[c] == 5 ) A.Add( new Pair( s5[c], int.MaxValue, c.ToString() ) );
			if ( count[c] > 5 ) A.Add( new Pair( s5[c], s6[c], c.ToString() ) );
		}
		A.Sort();
		for( int i = 0; i < A.Count; i++ )
		{
			result += ((Pair) A[i]).name;
		}
		return result;
	}

	NumberFormatInfo nfi = new CultureInfo( "en-US", false ).NumberFormat;

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
