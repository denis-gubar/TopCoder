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
#define all(v) (v).begin(), (v).end()
struct Taxi
{
	double maxDis( int maxX, int maxY, int taxiDis )
	{
		vd result(1, -1);
        for( int x = 0; x <= maxX; ++x )
        {
            int y = taxiDis - x;
            if ( y >= 0 && y <= maxY )
                result.push_back( sqrt(1.0 * x * x + 1.0 * y * y) );
        }
		return *max_element( all(result) );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<double> A3;
	{ /*Test 0*/int maxX = 
	10
	; A0.push_back( maxX ); int maxY = 
	3
	; A1.push_back( maxY ); int taxiDis = 
	3
	; A2.push_back( taxiDis ); double result = 
	3.0
	; A3.push_back( result );  }
	{ /*Test 1*/int maxX = 
	10
	; A0.push_back( maxX ); int maxY = 
	3
	; A1.push_back( maxY ); int taxiDis = 
	24
	; A2.push_back( taxiDis ); double result = 
	-1.0
	; A3.push_back( result );  }
	{ /*Test 2*/int maxX = 
	7
	; A0.push_back( maxX ); int maxY = 
	10
	; A1.push_back( maxY ); int taxiDis = 
	13
	; A2.push_back( taxiDis ); double result = 
	10.44030650891055
	; A3.push_back( result );  }
	{ /*Test 3*/int maxX = 
	4
	; A0.push_back( maxX ); int maxY = 
	4
	; A1.push_back( maxY ); int taxiDis = 
	7
	; A2.push_back( taxiDis ); double result = 
	5.0
	; A3.push_back( result );  }
	{ /*Test 4*/int maxX = 
	976421
	; A0.push_back( maxX ); int maxY = 
	976421
	; A1.push_back( maxY ); int taxiDis = 
	1000000
	; A2.push_back( taxiDis ); double result = 
	976705.6560100387
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], maxDis( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Taxi ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
