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
typedef long long lint;
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct StepperMotor
{
	struct comp: binary_function<int, int, bool>
	{
		bool operator() ( int a, int b ) const
		{
			if ( abs(a) != abs(b) )
				return abs(a) < abs(b);
			return a > 0;
		}
	};
	int rotateToNearest( int n, int current, vi target )
	{
		vi result;
		fora(i, target)
		{
			lint z = (static_cast<lint>( target[i] ) - current) % n;
			if ( z > n / 2 )
				z -= n;
			if ( z < -(n - 1) / 2 )
				z += n;
			result.push_back( z );
		}
		return *min_element( all(result), comp() );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int n = 
	10
	; A0.push_back( n ); int current = 
	0
	; A1.push_back( current ); int _target[] = 
	{-2, -3, 4, 5, 6, 9999999}
	; vi target(_target, _target + (sizeof(_target) / sizeof(_target[0]))); A2.push_back( target ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 1*/int n = 
	2
	; A0.push_back( n ); int current = 
	314159
	; A1.push_back( current ); int _target[] = 
	{10, 8, 6, 4, 2}
	; vi target(_target, _target + (sizeof(_target) / sizeof(_target[0]))); A2.push_back( target ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 2*/int n = 
	1
	; A0.push_back( n ); int current = 
	-2147483648
	; A1.push_back( current ); int _target[] = 
	{-2147483648, -2147483648, 2147483647, 2147483647}
	; vi target(_target, _target + (sizeof(_target) / sizeof(_target[0]))); A2.push_back( target ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 3*/int n = 
	23
	; A0.push_back( n ); int current = 
	10
	; A1.push_back( current ); int _target[] = 
	{64077, -567273, 105845, -279980, 35557,
-286190, -652879, -431665, -634870, -454044}
	; vi target(_target, _target + (sizeof(_target) / sizeof(_target[0]))); A2.push_back( target ); int result = 
	-11
	; A3.push_back( result );  }
	{ /*Test 4*/int n = 
	1000000000
	; A0.push_back( n ); int current = 
	1403466951
	; A1.push_back( current ); int _target[] = 
	{1233321992, 11423750, 1356595134, 1130863021, 1183514764,
1943494859, 1714480374, 1529875954, 1738756510, 1190153525}
	; vi target(_target, _target + (sizeof(_target) / sizeof(_target[0]))); A2.push_back( target ); int result = 
	-46871817
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], rotateToNearest( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	StepperMotor ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
