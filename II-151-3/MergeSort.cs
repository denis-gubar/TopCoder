using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class MergeSort
{
	private int result = 0;

	private int[] mergeSort( int[] a )
	{
		if ( a.Length <= 1 ) return a;
		if ( a.Length % 2 == 0 )
		{
			int[] b = new int[a.Length / 2];
			int[] c = new int[a.Length / 2];
			for( int i = 0; i < a.Length / 2; i++ )
			{
				b[i] = a[i];
				c[i] = a[i + a.Length / 2];
			}
			int[] sb = mergeSort( b );
			int[] sc = mergeSort( c );
			return merge( sb, sc );
		}
		else
		{
			int[] b = new int[a.Length / 2];
			int[] c = new int[a.Length / 2 + 1];
			for( int i = 0; i < a.Length / 2; i++ )
			{
				b[i] = a[i];
				c[i] = a[i + a.Length / 2];
			}
			c[c.Length - 1] = a[a.Length - 1];
			int[] sb = mergeSort( b );
			int[] sc = mergeSort( c );
			return merge( sb, sc );
		}
	}

	private int[] merge( int[] b, int[] c )
	{
		int[] a = new int[b.Length + c.Length];
		int count = 0;
		int i = 0;
		int j = 0;
		while( i < b.Length && j < c.Length )
		{
			result++;
			if ( b[i] < c[j] )
			{
				a[count++] = b[i++];
				continue;
			}
			if ( b[i] > c[j] )
			{
				a[count++] = c[j++];
				continue;
			}
			if ( b[i] == c[j] )
			{
				a[count++] = b[i++];
				a[count++] = c[j++];
				continue;
			}
		}
		for( int k = i; k < b.Length; k++ )
		{
			a[count++] = b[k];
		}
		for( int k = j; k < c.Length; k++ )
		{
			a[count++] = c[k];
		}
		return a;
	}

    public int howManyComparisons( int[] numbers )
    {
		mergeSort( numbers );
        return result;
    }

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
