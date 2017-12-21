using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

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
		{
			i--;
		}
		if ( i < 0 )
		{
			return false;
		}
		for( int k = i + 1; k < size; k++ )
		{
			Directions[k] = !Directions[k];
		}
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

public class MNS
{
	public int combos( int[] numbers )
	{
		int total = 0;
		int sum = 0;
		for( int i = 0; i < numbers.Length; i++ )
		{
			sum += numbers[i];
		}
		if ( sum % 3 > 0 )
		{
			return 0;
		}
		sum /= 3;
		Hashtable h = new Hashtable( 10000 );
		Permutations p = new Permutations( 9 );
		while( p.Next() )
		{
			if ( numbers[p.Permutation[0]] + numbers[p.Permutation[1]] + numbers[p.Permutation[2]] == sum &&
			    numbers[p.Permutation[3]] + numbers[p.Permutation[4]] + numbers[p.Permutation[5]] == sum &&
			    numbers[p.Permutation[6]] + numbers[p.Permutation[7]] + numbers[p.Permutation[8]] == sum &&
			    numbers[p.Permutation[0]] + numbers[p.Permutation[3]] + numbers[p.Permutation[6]] == sum &&
			    numbers[p.Permutation[1]] + numbers[p.Permutation[4]] + numbers[p.Permutation[7]] == sum &&
			    numbers[p.Permutation[2]] + numbers[p.Permutation[5]] + numbers[p.Permutation[8]] == sum )
		    {
		    	int x = 0;
		    	for( int i = 0; i < 9; i++ )
		    	{
		    		x = x * 10 + numbers[p.Permutation[i]];
		    	}
		    	if ( !h.Contains( x ) )
		    	{
		    		total++; h.Add( x, null );
		    	}
		    }
			    
		}
		return total;
	}

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
