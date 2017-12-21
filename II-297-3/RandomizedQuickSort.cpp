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
typedef vector<double> vd;
struct RandomizedQuickSort
{
    vd M;
    double calc( int A, int S, int a, int b )
    {
        if ( M[A] >= 0 )
            return M[A];
        if ( A <= S )
            return M[A] = b * A * A;
        double total = 0;
        for( int k = 0; k < A; ++k )
            total += a * A + calc( k, S, a, b ) + calc( A - k - 1, S, a, b );
        return M[A] = total / A;
    }
	double getExpectedTime( int listSize, int S, int a, int b )
	{
		M = vd( 1001, -1 );
		return calc( listSize, S, a, b );
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
	{ /*Test 0*/int listSize = 
	1
	; A0.push_back( listSize ); int S = 
	1
	; A1.push_back( S ); int a = 
	1
	; A2.push_back( a ); int b = 
	1
	; A3.push_back( b ); double result = 
	1.0
	; A4.push_back( result );  }
	{ /*Test 1*/int listSize = 
	2
	; A0.push_back( listSize ); int S = 
	1
	; A1.push_back( S ); int a = 
	1
	; A2.push_back( a ); int b = 
	1
	; A3.push_back( b ); double result = 
	3.0
	; A4.push_back( result );  }
	{ /*Test 2*/int listSize = 
	3
	; A0.push_back( listSize ); int S = 
	1
	; A1.push_back( S ); int a = 
	1
	; A2.push_back( a ); int b = 
	1
	; A3.push_back( b ); double result = 
	5.666666666666667
	; A4.push_back( result );  }
	{ /*Test 3*/int listSize = 
	3
	; A0.push_back( listSize ); int S = 
	1
	; A1.push_back( S ); int a = 
	1
	; A2.push_back( a ); int b = 
	10
	; A3.push_back( b ); double result = 
	17.666666666666668
	; A4.push_back( result );  }
	{ /*Test 4*/int listSize = 
	10
	; A0.push_back( listSize ); int S = 
	5
	; A1.push_back( S ); int a = 
	3
	; A2.push_back( a ); int b = 
	2
	; A3.push_back( b ); double result = 
	112.37380952380951
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], getExpectedTime( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RandomizedQuickSort ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
