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
struct Embassy
{
	int visaApplication( vi forms, int dayLength, int openTime )
	{
		int result = 1000000000;
        for( int t = -dayLength; t <= openTime; ++t )
            if ( t + forms[0] % dayLength >= 0 && t + forms[0] % dayLength <= openTime )
            {
                int current = t + forms[0];
                for( int i = 1; i < forms.size(); ++i )
                {
                    current += forms[i];
                    if ( current % dayLength > openTime )
                        current = (current / dayLength + 1) * dayLength;
                }
                current -= t;
                if ( current < result )
                    result = current;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int _forms[] = 
	{4,4,4}
	; vi forms(_forms, _forms + (sizeof(_forms) / sizeof(_forms[0]))); A0.push_back( forms ); int dayLength = 
	24
	; A1.push_back( dayLength ); int openTime = 
	8
	; A2.push_back( openTime ); int result = 
	12
	; A3.push_back( result );  }
	{ /*Test 1*/int _forms[] = 
	{4,4,4,4}
	; vi forms(_forms, _forms + (sizeof(_forms) / sizeof(_forms[0]))); A0.push_back( forms ); int dayLength = 
	24
	; A1.push_back( dayLength ); int openTime = 
	8
	; A2.push_back( openTime ); int result = 
	28
	; A3.push_back( result );  }
	{ /*Test 2*/int _forms[] = 
	{2,2,2,2}
	; vi forms(_forms, _forms + (sizeof(_forms) / sizeof(_forms[0]))); A0.push_back( forms ); int dayLength = 
	24
	; A1.push_back( dayLength ); int openTime = 
	1
	; A2.push_back( openTime ); int result = 
	73
	; A3.push_back( result );  }
	{ /*Test 3*/int _forms[] = 
	{25,500,630,2500,1000,350,22,58,100,400,500,5000}
	; vi forms(_forms, _forms + (sizeof(_forms) / sizeof(_forms[0]))); A0.push_back( forms ); int dayLength = 
	1440
	; A1.push_back( dayLength ); int openTime = 
	360
	; A2.push_back( openTime ); int result = 
	16945
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], visaApplication( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Embassy ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
