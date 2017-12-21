using System;

public class PowerOutage
{
	public int estimateTimeOut( int[] from, int[] to, int[] len )
	{
		int[,] M = new int[50, 50];
		int[] r = new int[50];
		int x = 0;
		for( int i = 0; i < len.Length; i++ )
		{
			M[from[i], to[i]] = M[to[i], from[i]] = len[i];
			x += 2 * len[i];
		}
		int max = 0;
		for( int i = 0; i < 50; i++ )
			for( int j = i + 1; j < 50; j++ )
			{
				if ( M[i, j] > 0 )
				{
					r[j] = r[i] + M[i, j];					
				}
			}
		for( int i = 0; i < 50; i++ )
		{
			max = max > r[i] ? max : r[i];
		}
		return x - max;
	}
}
