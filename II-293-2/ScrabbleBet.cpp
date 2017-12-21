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
struct ScrabbleBet
{
	double estimate( int trials, int games, int winsNeeded, int winChance )
	{
		double result = 0, a = 0.01 * winChance, b = 1 - a;
        for( int k = 0; k < (1 << games); ++k )
        {
            int w = 0; double p = 1;
            for( int i = 0; i < games; ++i )
                if ( k & (1 << i) )
                {
                    ++w; p *= a;
                }
                else
                    p *= b;
            if ( w < winsNeeded )
                result += p;
        }
		return 1 - pow(result, trials);
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<double> A4;
	{ /*Test 0*/int trials = 
	2
	; A0.push_back( trials ); int games = 
	2
	; A1.push_back( games ); int winsNeeded = 
	1
	; A2.push_back( winsNeeded ); int winChance = 
	50
	; A3.push_back( winChance ); double result = 
	0.9375
	; A4.push_back( result );  }
	{ /*Test 1*/int trials = 
	2
	; A0.push_back( trials ); int games = 
	2
	; A1.push_back( games ); int winsNeeded = 
	2
	; A2.push_back( winsNeeded ); int winChance = 
	50
	; A3.push_back( winChance ); double result = 
	0.4375
	; A4.push_back( result );  }
	{ /*Test 2*/int trials = 
	10
	; A0.push_back( trials ); int games = 
	10
	; A1.push_back( games ); int winsNeeded = 
	5
	; A2.push_back( winsNeeded ); int winChance = 
	25
	; A3.push_back( winChance ); double result = 
	0.5566860567603682
	; A4.push_back( result );  }
	{ /*Test 3*/int trials = 
	2
	; A0.push_back( trials ); int games = 
	20
	; A1.push_back( games ); int winsNeeded = 
	5
	; A2.push_back( winsNeeded ); int winChance = 
	10
	; A3.push_back( winChance ); double result = 
	0.08448495352665641
	; A4.push_back( result );  }
	{ /*Test 4*/int trials = 
	50
	; A0.push_back( trials ); int games = 
	15
	; A1.push_back( games ); int winsNeeded = 
	1
	; A2.push_back( winsNeeded ); int winChance = 
	0
	; A3.push_back( winChance ); double result = 
	0.0
	; A4.push_back( result );  }
	{ /*Test 5*/int trials = 
	50
	; A0.push_back( trials ); int games = 
	17
	; A1.push_back( games ); int winsNeeded = 
	16
	; A2.push_back( winsNeeded ); int winChance = 
	100
	; A3.push_back( winChance ); double result = 
	1.0
	; A4.push_back( result );  }
	{ /*Test 6*/int trials = 
	50
	; A0.push_back( trials ); int games = 
	10
	; A1.push_back( games ); int winsNeeded = 
	10
	; A2.push_back( winsNeeded ); int winChance = 
	75
	; A3.push_back( winChance ); double result = 
	0.9448701546682944
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], estimate( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ScrabbleBet ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
