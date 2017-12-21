using System;

public class Bonuses
{
	private int[] m;
	private int max()
	{
		int x = m[0];
		int y = 0;
		for( int i = 1; i < m.Length; i++ )
		{
			if ( x < m[i] )
			{
				x = m[i]; y = i;
			}
		}
		m[y] = 0;
		return y;
	}
	public int[] getDivision(int[] points)
	{
		int[] result = new int[points.Length];
		m = new int[points.Length];
		points.CopyTo( m, 0 );
		int total = 0;
		for( int i = 0; i < points.Length; i++ )
		{
			total += points[i];
		}
		int bonus = 100;
		for( int i = 0; i < points.Length; i++ )
		{
			result[i] = points[i] * 100 / total;
			bonus -= points[i] * 100 / total;
		}
		for( int i = 0; i < bonus; i++ )
		{
			result[max()]++;
		}
		return result;
	}
}
