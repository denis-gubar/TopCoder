using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class DivDigits
{
  public int howMany( int number )
  {
	int total = 0;
  	int x = number;
  	while( x > 0 )
  	{
  		if ( x % 10 > 0 && number % (x % 10) == 0 )
  		{
  			total++;
  		}  			
  		x /= 10;
  	}
	return total;
  }

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
