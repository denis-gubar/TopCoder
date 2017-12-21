using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class Pricing
{
	private int calc( int[] groups, int[] price )
	{
		int total = 0;
		for( int i = 0; i < price.Length; i++ )
		{
			int x = 0;
			for( int j = 0; j < 4 && price[groups[j]] <= price[i]; j++ )
			{
				x = price[groups[j]];
			}
			total += x;			
		}
		return total;
	}
	
	public int maxSales( int[] price )
	{
		int total = 0;
		Array.Sort( price );
		if ( price.Length < 5 )
		{
			for( int i = 0; i < price.Length; i++ )
			{
				total += price[i];
			}
			return total;
		}
		for( int i1 = price.Length - 1; i1 >= 3; i1-- )
		{
			for( int i2 = i1 - 1; i2 >= 2; i2-- )
			{
				for( int i3 = i2 - 1; i3 >= 1; i3-- )
				{
					for( int i4 = i3 - 1; i4 >= 0; i4-- )
					{
						int x = calc( new int[] {i4, i3, i2, i1}, price );
						total = total > x ? total : x;
					}
				}
			}
		}
		return total;
		
	}

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
