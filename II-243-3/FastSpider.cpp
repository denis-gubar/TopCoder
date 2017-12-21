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
struct FastSpider
{
	int findTime( double spiderSpeed, double manSpeed )
	{
        double t = (exp( manSpeed / spiderSpeed ) - 1) / manSpeed;
        if ( t < 0 )
		    return -1;
        return t + 0.5;
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
	void run_test( int Case = -1 ) { vector<double> A0; vector<double> A1; vector<int> A2;
	{ /*Test 0*/double spiderSpeed = 
	0.25
	; A0.push_back( spiderSpeed ); double manSpeed = 
	1
	; A1.push_back( manSpeed ); int result = 
	54
	; A2.push_back( result );  }
	{ /*Test 1*/double spiderSpeed = 
	0.5
	; A0.push_back( spiderSpeed ); double manSpeed = 
	1
	; A1.push_back( manSpeed ); int result = 
	6
	; A2.push_back( result );  }
	{ /*Test 2*/double spiderSpeed = 
	0.5
	; A0.push_back( spiderSpeed ); double manSpeed = 
	4.8877377
	; A1.push_back( manSpeed ); int result = 
	3600
	; A2.push_back( result );  }
	{ /*Test 3*/double spiderSpeed = 
	0.2
	; A0.push_back( spiderSpeed ); double manSpeed = 
	1
	; A1.push_back( manSpeed ); int result = 
	147
	; A2.push_back( result );  }
	{ /*Test 4*/double spiderSpeed = 
	0.47
	; A0.push_back( spiderSpeed ); double manSpeed = 
	2.78
	; A1.push_back( manSpeed ); int result = 
	133
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], findTime( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FastSpider ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
