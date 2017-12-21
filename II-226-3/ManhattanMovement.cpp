// BEGIN CUT HERE
#include "precompiled.h"
/*
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
// BEGIN CUT HERE
*/
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
struct ManhattanMovement
{
	double getDistance( int a, int b, int x0, int y0 )
	{
		if ( !a )
			return abs(1.0 / b - y0);
		if ( !b )
			return abs(1.0 / a - x0);
		return min( abs((1.0 - 1.0 * b * y0) / a - x0), abs((1.0 - 1.0 * a * x0) / b - y0) );
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const long long& expected, const long long& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<double> A4;
	{ /*Test 0*/int a = 
	1
	; A0.push_back( a ); int b = 
	2
	; A1.push_back( b ); int x0 = 
	-2
	; A2.push_back( x0 ); int y0 = 
	3
	; A3.push_back( y0 ); double result = 
	1.5
	; A4.push_back( result );  }
	{ /*Test 1*/int a = 
	37
	; A0.push_back( a ); int b = 
	37
	; A1.push_back( b ); int x0 = 
	42
	; A2.push_back( x0 ); int y0 = 
	19
	; A3.push_back( y0 ); double result = 
	60.97297297297297
	; A4.push_back( result );  }
	{ /*Test 2*/int a = 
	-100
	; A0.push_back( a ); int b = 
	0
	; A1.push_back( b ); int x0 = 
	-999999
	; A2.push_back( x0 ); int y0 = 
	314159
	; A3.push_back( y0 ); double result = 
	999998.99
	; A4.push_back( result );  }
	{ /*Test 3*/int a = 
	0
	; A0.push_back( a ); int b = 
	-2147483648
	; A1.push_back( b ); int x0 = 
	1
	; A2.push_back( x0 ); int y0 = 
	100000
	; A3.push_back( y0 ); double result = 
	100000.00000000047
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], getDistance( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ManhattanMovement ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
