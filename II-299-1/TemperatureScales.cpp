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
struct TemperatureScales
{
	double convert( int f1, int b1, int f2, int b2, int t )
	{
		return 1.0 * (t - f1) * (b2 - f2) / (b1 - f1) + f2;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<int> A4; vector<double> A5;
	{ /*Test 0*/int f1 = 
	0
	; A0.push_back( f1 ); int b1 = 
	100
	; A1.push_back( b1 ); int f2 = 
	0
	; A2.push_back( f2 ); int b2 = 
	100
	; A3.push_back( b2 ); int t = 
	28
	; A4.push_back( t ); double result = 
	28.0
	; A5.push_back( result );  }
	{ /*Test 1*/int f1 = 
	0
	; A0.push_back( f1 ); int b1 = 
	100
	; A1.push_back( b1 ); int f2 = 
	1
	; A2.push_back( f2 ); int b2 = 
	101
	; A3.push_back( b2 ); int t = 
	28
	; A4.push_back( t ); double result = 
	29.0
	; A5.push_back( result );  }
	{ /*Test 2*/int f1 = 
	-1000
	; A0.push_back( f1 ); int b1 = 
	-999
	; A1.push_back( b1 ); int f2 = 
	-1000
	; A2.push_back( f2 ); int b2 = 
	1000
	; A3.push_back( b2 ); int t = 
	1000
	; A4.push_back( t ); double result = 
	3999000.0
	; A5.push_back( result );  }
	{ /*Test 3*/int f1 = 
	-10
	; A0.push_back( f1 ); int b1 = 
	0
	; A1.push_back( b1 ); int f2 = 
	1
	; A2.push_back( f2 ); int b2 = 
	2
	; A3.push_back( b2 ); int t = 
	17
	; A4.push_back( t ); double result = 
	3.7
	; A5.push_back( result );  }
	{ /*Test 4*/int f1 = 
	17
	; A0.push_back( f1 ); int b1 = 
	98
	; A1.push_back( b1 ); int f2 = 
	-123
	; A2.push_back( f2 ); int b2 = 
	12
	; A3.push_back( b2 ); int t = 
	22
	; A4.push_back( t ); double result = 
	-114.66666666666667
	; A5.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A5[i], convert( A0[i], A1[i], A2[i], A3[i], A4[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TemperatureScales ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
