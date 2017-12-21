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
typedef vector<lint> vl;
typedef vector<vl> vvl;
#define all(v) (v).begin(), (v).end()
lint C( lint n, lint k )
{
	static const int N = 60;
	static bool isCached = false;
	static vvl cache = vvl(N + 1, vl(N + 1));
	if ( !isCached )
	{
		for( int i = 0; i <= N; ++i )
			cache[i][0] = cache[i][i] = 1;
		for( int i = 1; i <= N; ++i )
			for( int j = 1; j < i; ++j )
				cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
	}
	isCached = true;
	return n >= k && k >= 0 && n <= N ? cache[n][k] : 0;
}
struct Flush
{
	double size( vi suits, int number )
	{
		lint result = 0, total = C( accumulate( all(suits), 0 ), number );
        for( int a = 0; a <= suits[0]; ++a )
            for( int b = 0; b <= suits[1]; ++b )
                for( int c = 0; c <= suits[2]; ++c )
                    for( int d = 0; d <= suits[3]; ++d )
                        if ( a + b + c + d == number )
                            result += max( max( a, b ), max( c, d ) ) * C( suits[0], a ) * C( suits[1], b ) * C( suits[2], c ) * C( suits[3], d );
		return 1.0 * result / total;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<double> A2;
	{ /*Test 0*/int _suits[] = 
	{2,2,2,2}
	; vi suits(_suits, _suits + (sizeof(_suits) / sizeof(_suits[0]))); A0.push_back( suits ); int number = 
	2
	; A1.push_back( number ); double result = 
	1.1428571428571428
	; A2.push_back( result );  }
	{ /*Test 1*/int _suits[] = 
	{1,4,7,10}
	; vi suits(_suits, _suits + (sizeof(_suits) / sizeof(_suits[0]))); A0.push_back( suits ); int number = 
	22
	; A1.push_back( number ); double result = 
	10.0
	; A2.push_back( result );  }
	{ /*Test 2*/int _suits[] = 
	{13, 13, 13, 13}
	; vi suits(_suits, _suits + (sizeof(_suits) / sizeof(_suits[0]))); A0.push_back( suits ); int number = 
	49
	; A1.push_back( number ); double result = 
	13.0
	; A2.push_back( result );  }
	{ /*Test 3*/int _suits[] = 
	{13, 13, 13, 13}
	; vi suits(_suits, _suits + (sizeof(_suits) / sizeof(_suits[0]))); A0.push_back( suits ); int number = 
	26
	; A1.push_back( number ); double result = 
	8.351195960938014
	; A2.push_back( result );  }
	{ /*Test 4*/int _suits[] = 
	{13,13,13,13}
	; vi suits(_suits, _suits + (sizeof(_suits) / sizeof(_suits[0]))); A0.push_back( suits ); int number = 
	0
	; A1.push_back( number ); double result = 
	0.0
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], size( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Flush ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
