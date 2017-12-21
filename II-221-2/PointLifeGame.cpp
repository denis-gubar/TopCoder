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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct PointLifeGame
{
	string calc( lint x, int n )
	{
		int a = (2 * x + 1) / (2 * n) + 10000;
		int b = (20000 * x + 1) / (2 * n) % 10000 + 10000;
		return ToString( a ).substr( 1 ) + "." + ToString( b ).substr( 1 );
	}
	string simulate( vi xs, vi ys, int rnds )
	{
		string result;
		vpii A;
		int n = 1;
		for( int k = 0; k < rnds; ++k, n <<= 1 )
		{
			A.clear();
			fora(i, xs)
				fora(j, xs)
					if ( i != j )
						A.push_back( make_pair( -ys[i] - ys[j], -xs[i] - xs[j] ) );
			sort( all(A) );
			A.erase( unique( all(A) ), A.end() );
			xs.clear(); ys.clear();
			for( int i = 0; i < 10 && i < A.size(); ++i )
			{
				xs.push_back( -A[i].second );
				ys.push_back( -A[i].first );
			}
		}
		return calc( -A[0].second, n ) + " " + calc( -A[0].first, n );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2; vector<string> A3;
	{ /*Test 0*/int _xs[] = 
	{0,0,10,10}
	; vi xs(_xs, _xs + (sizeof(_xs) / sizeof(_xs[0]))); A0.push_back( xs ); int _ys[] = 
	{0,10,0,10}
	; vi ys(_ys, _ys + (sizeof(_ys) / sizeof(_ys[0]))); A1.push_back( ys ); int rnds = 
	1
	; A2.push_back( rnds ); string result = 
	"0005.0000 0010.0000"
	; A3.push_back( result );  }
	{ /*Test 1*/int _xs[] = 
	{0,0,10,10}
	; vi xs(_xs, _xs + (sizeof(_xs) / sizeof(_xs[0]))); A0.push_back( xs ); int _ys[] = 
	{0,10,0,10}
	; vi ys(_ys, _ys + (sizeof(_ys) / sizeof(_ys[0]))); A1.push_back( ys ); int rnds = 
	10
	; A2.push_back( rnds ); string result = 
	"0005.0097 0007.5000"
	; A3.push_back( result );  }
	{ /*Test 2*/int _xs[] = 
	{0,10,20}
	; vi xs(_xs, _xs + (sizeof(_xs) / sizeof(_xs[0]))); A0.push_back( xs ); int _ys[] = 
	{0,10,0}
	; vi ys(_ys, _ys + (sizeof(_ys) / sizeof(_ys[0]))); A1.push_back( ys ); int rnds = 
	1
	; A2.push_back( rnds ); string result = 
	"0015.0000 0005.0000"
	; A3.push_back( result );  }
	{ /*Test 3*/int _xs[] = 
	{1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10, 
 1,2,3,4,5,6,7,8,9,10}
	; vi xs(_xs, _xs + (sizeof(_xs) / sizeof(_xs[0]))); A0.push_back( xs ); int _ys[] = 
	{1,1,1,1,1,1,1,1,1,1, 
 2,2,2,2,2,2,2,2,2,2,
 3,3,3,3,3,3,3,3,3,3,
 4,4,4,4,4,4,4,4,4,4,
 5,5,5,5,5,5,5,5,5,5}
	; vi ys(_ys, _ys + (sizeof(_ys) / sizeof(_ys[0]))); A1.push_back( ys ); int rnds = 
	10
	; A2.push_back( rnds ); string result = 
	"0009.0009 0005.0000"
	; A3.push_back( result );  }
	{ /*Test 4*/int _xs[] = 
	{3,3,8,0}
	; vi xs(_xs, _xs + (sizeof(_xs) / sizeof(_xs[0]))); A0.push_back( xs ); int _ys[] = 
	{2,1,1,3}
	; vi ys(_ys, _ys + (sizeof(_ys) / sizeof(_ys[0]))); A1.push_back( ys ); int rnds = 
	10
	; A2.push_back( rnds ); string result = 
	"0002.4658 0002.1875"
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], simulate( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PointLifeGame ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
