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
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct TeamSplit
{
	int difference( vi strengths )
	{
        int result = 0;
        sort( all(strengths), greater<int>() );
        fora(i, strengths)
            if ( i % 2 )
                result += strengths[i];
            else
                result -= strengths[i];
        return abs( result );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1;
	{ /*Test 0*/int _strengths[] = 
	{5,7,8,4,2}
	; vi strengths(_strengths, _strengths + (sizeof(_strengths) / sizeof(_strengths[0]))); A0.push_back( strengths ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 1*/int _strengths[] = 
	{100}
	; vi strengths(_strengths, _strengths + (sizeof(_strengths) / sizeof(_strengths[0]))); A0.push_back( strengths ); int result = 
	100
	; A1.push_back( result );  }
	{ /*Test 2*/int _strengths[] = 
	{1000,1000}
	; vi strengths(_strengths, _strengths + (sizeof(_strengths) / sizeof(_strengths[0]))); A0.push_back( strengths ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 3*/int _strengths[] = 
	{9,8,7,6}
	; vi strengths(_strengths, _strengths + (sizeof(_strengths) / sizeof(_strengths[0]))); A0.push_back( strengths ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 4*/int _strengths[] = 
	{1,5,10,1,5,10}
	; vi strengths(_strengths, _strengths + (sizeof(_strengths) / sizeof(_strengths[0]))); A0.push_back( strengths ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 5*/int _strengths[] = 
	{824, 581,   9, 776, 149, 493, 531, 558, 995, 637,
 394, 526, 986, 548, 344, 509, 319,  37, 790, 491,
 479,  34, 776, 321, 258, 851, 711, 365, 763, 355,
 386, 877, 596,  96, 151, 166, 558, 109, 874, 959,
 845, 181, 976, 335, 930,  22,  78, 120, 907, 584}
	; vi strengths(_strengths, _strengths + (sizeof(_strengths) / sizeof(_strengths[0]))); A0.push_back( strengths ); int result = 
	478
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], difference( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TeamSplit ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
