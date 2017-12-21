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
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
template<typename T> T gcd( T a, T b )
{
	while( a && b ) if ( a > b ) a %= b; else b %= a; return a + b;
}
template<typename T> T lcm( T a, T b )
{
	return a / gcd( a, b ) * b;
}
struct LeastMajorityMultiple
{
	int leastMajorityMultiple( int a, int b, int c, int d, int e )
	{
		int result = a * b * c;
		vi A;
		A.push_back( a );
		A.push_back( b );
		A.push_back( c );
		A.push_back( d );
		A.push_back( e );
		sort( all(A) );
		do
		{
			result = min( result, lcm( lcm( A[0], A[1] ), A[2] ) );
		} while( next_permutation( all(A) ) );
		return result;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<int> A4; vector<int> A5;
	{ /*Test 0*/int a = 
	1
	; A0.push_back( a ); int b = 
	2
	; A1.push_back( b ); int c = 
	3
	; A2.push_back( c ); int d = 
	4
	; A3.push_back( d ); int e = 
	5
	; A4.push_back( e ); int result = 
	4
	; A5.push_back( result );  }
	{ /*Test 1*/int a = 
	30
	; A0.push_back( a ); int b = 
	42
	; A1.push_back( b ); int c = 
	70
	; A2.push_back( c ); int d = 
	35
	; A3.push_back( d ); int e = 
	90
	; A4.push_back( e ); int result = 
	210
	; A5.push_back( result );  }
	{ /*Test 2*/int a = 
	30
	; A0.push_back( a ); int b = 
	45
	; A1.push_back( b ); int c = 
	23
	; A2.push_back( c ); int d = 
	26
	; A3.push_back( d ); int e = 
	56
	; A4.push_back( e ); int result = 
	1170
	; A5.push_back( result );  }
	{ /*Test 3*/int a = 
	3
	; A0.push_back( a ); int b = 
	14
	; A1.push_back( b ); int c = 
	15
	; A2.push_back( c ); int d = 
	92
	; A3.push_back( d ); int e = 
	65
	; A4.push_back( e ); int result = 
	195
	; A5.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A5[i], leastMajorityMultiple( A0[i], A1[i], A2[i], A3[i], A4[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	LeastMajorityMultiple ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
