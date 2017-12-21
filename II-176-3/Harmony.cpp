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
typedef vector<vi> vvi;
#define all(v) (v).begin(), (v).end()
template<typename T> T gcd( T a, T b )
{
	while( a && b ) if ( a > b ) a %= b; else b %= a; return a + b;
}
struct Harmony
{
	struct comp: binary_function<vi, vi, bool>
	{
		vi norm( vi x ) const
		{
			vi result;
			result.push_back( x[0] / gcd( x[0], x[1] ) );
			result.push_back( x[1] / gcd( x[1], x[2] ) );
			result.push_back( x[0] / gcd( x[2], x[0] ) );
			sort( all(result), greater<int>() );
			return result;
		}
		bool operator() ( vi a, vi b ) const
		{
			vi A = norm( a ), B = norm( b );
			if ( A == B )
				return lexicographical_compare( all(a), all(b) );
			return lexicographical_compare( all(A), all(B) );
		}
	};
	vi mostHarmonious( vi frequencies )
	{
		vvi triads;
		int n = frequencies.size();
		sort( all(frequencies) );
		for( int i = 0; i < n; ++i )
			for( int j = i + 1; j < n; ++j )
				for( int k = j + 1; k < n; ++k )
				{
					vi temp;
					temp.push_back( frequencies[i] );
					temp.push_back( frequencies[j] );
					temp.push_back( frequencies[k] );
					triads.push_back( temp );
				}
		return *min_element( all(triads), comp() );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1;
	{ /*Test 0*/int _frequencies[] = 
	{200,250,400,320,350}
	; vi frequencies(_frequencies, _frequencies + (sizeof(_frequencies) / sizeof(_frequencies[0]))); A0.push_back( frequencies ); int _result[] = 
	{ 200,  250,  400 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/int _frequencies[] = 
	{440, 320, 750,660, 500,550}
	; vi frequencies(_frequencies, _frequencies + (sizeof(_frequencies) / sizeof(_frequencies[0]))); A0.push_back( frequencies ); int _result[] = 
	{ 440,  550,  660 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/int _frequencies[] = 
	{1960,1000,3050,2341,7253,7864,2000,2352,2940,1534,7234}
	; vi frequencies(_frequencies, _frequencies + (sizeof(_frequencies) / sizeof(_frequencies[0]))); A0.push_back( frequencies ); int _result[] = 
	{ 1960,  2352,  2940 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/int _frequencies[] = 
	{100,200,300,400,500,600,700,800,900,1000}
	; vi frequencies(_frequencies, _frequencies + (sizeof(_frequencies) / sizeof(_frequencies[0]))); A0.push_back( frequencies ); int _result[] = 
	{ 100,  200,  400 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], mostHarmonious( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Harmony ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
