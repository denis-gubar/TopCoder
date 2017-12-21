using System;
using System.Globalization;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

public class FormatAmt
{
  public string amount( int dollars, int cents )
  {
  	double x = dollars + cents / 100d;
  	NumberFormatInfo nfi =  new CultureInfo( "en-US", false ).NumberFormat;  	
	return x.ToString( "C", nfi );
  }

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
