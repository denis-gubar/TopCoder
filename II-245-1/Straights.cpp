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
struct Straights
{
	int howMany( vi hand, int k )
	{
		int result = 0;
        for( int i = 0; i + k <= hand.size(); ++i )
        {
            int p = 1;
            for( int j = 0; j < k; ++j )
                p *= hand[i + j];
            result += p;
        }
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/int _hand[] = 
	{0,3,1,2,0,0,0,0,0,0,0,0,0}
	; vi hand(_hand, _hand + (sizeof(_hand) / sizeof(_hand[0]))); A0.push_back( hand ); int k = 
	2
	; A1.push_back( k ); int result = 
	5
	; A2.push_back( result );  }
	{ /*Test 1*/int _hand[] = 
	{1,1,1,1,1,1,1,1,1,1,1,1,1}
	; vi hand(_hand, _hand + (sizeof(_hand) / sizeof(_hand[0]))); A0.push_back( hand ); int k = 
	5
	; A1.push_back( k ); int result = 
	9
	; A2.push_back( result );  }
	{ /*Test 2*/int _hand[] = 
	{4,4,4,4,4,4,4,4,4,4,4,4,4}
	; vi hand(_hand, _hand + (sizeof(_hand) / sizeof(_hand[0]))); A0.push_back( hand ); int k = 
	13
	; A1.push_back( k ); int result = 
	67108864
	; A2.push_back( result );  }
	{ /*Test 3*/int _hand[] = 
	{4,0,4,0,4,0,4,0,4,0,4,0,4}
	; vi hand(_hand, _hand + (sizeof(_hand) / sizeof(_hand[0]))); A0.push_back( hand ); int k = 
	2
	; A1.push_back( k ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 4*/int _hand[] = 
	{1,2,3,4,1,2,3,4,1,2,3,4,1}
	; vi hand(_hand, _hand + (sizeof(_hand) / sizeof(_hand[0]))); A0.push_back( hand ); int k = 
	1
	; A1.push_back( k ); int result = 
	31
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], howMany( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Straights ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
