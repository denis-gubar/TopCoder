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
typedef vector<double> vd;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
struct FallingPoints
{
	vd getHeights( vi X, int R )
	{
        int n = X.size(); double r = R;
        vd result(n), x(n);
        fora(i, x)
            x[i] = X[i];
        for( int i = 1; i < n; ++i )
            if ( r * r + 1e-9 > (x[i] - x[i - 1]) * (x[i] - x[i - 1]) )
                result[i] = result[i - 1] + sqrt(r * r - (x[i] - x[i - 1]) * (x[i] - x[i - 1]));
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<vd> A2;
	{ /*Test 0*/int _X[] = 
	{0}
	; vi X(_X, _X + (sizeof(_X) / sizeof(_X[0]))); A0.push_back( X ); int R = 
	10
	; A1.push_back( R ); double _result[] = 
	{0.0 }
	; vd result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/int _X[] = 
	{1,100}
	; vi X(_X, _X + (sizeof(_X) / sizeof(_X[0]))); A0.push_back( X ); int R = 
	10
	; A1.push_back( R ); double _result[] = 
	{0.0, 0.0 }
	; vd result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/int _X[] = 
	{0,9}
	; vi X(_X, _X + (sizeof(_X) / sizeof(_X[0]))); A0.push_back( X ); int R = 
	10
	; A1.push_back( R ); double _result[] = 
	{0.0, 4.358898943540674 }
	; vd result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/int _X[] = 
	{0,9,19}
	; vi X(_X, _X + (sizeof(_X) / sizeof(_X[0]))); A0.push_back( X ); int R = 
	10
	; A1.push_back( R ); double _result[] = 
	{0.0, 4.358898943540674, 4.358898943540674 }
	; vd result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getHeights( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FallingPoints ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
