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
struct NumberMagicEasy
{
	int theNumber( string answer )
	{
		vvi M;
		vi A;
		A.push_back( 1 );
		A.push_back( 2 );
		A.push_back( 3 );
		A.push_back( 4 );
		A.push_back( 5 );
		A.push_back( 6 );
		A.push_back( 7 );
		A.push_back( 8 );
		M.push_back( A );
		A.clear();
		A.push_back( 1 );
		A.push_back( 2 );
		A.push_back( 3 );
		A.push_back( 4 );
		A.push_back( 9 );
		A.push_back( 10 );
		A.push_back( 11 );
		A.push_back( 12 );
		M.push_back( A );
		A.clear();
		A.push_back( 1 );
		A.push_back( 2 );
		A.push_back( 5 );
		A.push_back( 6 );
		A.push_back( 9 );
		A.push_back( 10 );
		A.push_back( 13 );
		A.push_back( 14 );
		M.push_back( A );
		A.clear();
		A.push_back( 1 );
		A.push_back( 3 );
		A.push_back( 5 );
		A.push_back( 7 );
		A.push_back( 9 );
		A.push_back( 11 );
		A.push_back( 13 );
		A.push_back( 15 );
		M.push_back( A );
		for( int result = 1; result <= 16; ++result )
		{
			bool flag = true;
			for( int i = 0; i < 4; ++i )
				flag &= find( all(M[i]), result ) == M[i].end() ^ answer[i] == 'Y';
			if ( flag )
				return result;
		}
		return -1;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<int> A1;
	{ /*Test 0*/string answer = 
	"YNYY"
	; A0.push_back( answer ); int result = 
	5
	; A1.push_back( result );  }
	{ /*Test 1*/string answer = 
	"YNNN"
	; A0.push_back( answer ); int result = 
	8
	; A1.push_back( result );  }
	{ /*Test 2*/string answer = 
	"NNNN"
	; A0.push_back( answer ); int result = 
	16
	; A1.push_back( result );  }
	{ /*Test 3*/string answer = 
	"YYYY"
	; A0.push_back( answer ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 4*/string answer = 
	"NYNY"
	; A0.push_back( answer ); int result = 
	11
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], theNumber( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NumberMagicEasy ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
