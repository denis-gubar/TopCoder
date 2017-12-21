using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class CeyKaps
{
  public string decipher( string typed, string[] switches )
  {
  	string result = "";
  	for( int i = 0; i < typed.Length; i++ )
  	{
  		char c = typed[i];
  		for( int j = 0; j < switches.Length; j++ )
  		{
  			if ( c == switches[j][0] )
  			{
  				c = switches[j][2];
  			} else if ( c == switches[j][2] )
  			{
  				c = switches[j][0];
  			}
  		}
  		result += c;
  	}
	return result;
  }

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
