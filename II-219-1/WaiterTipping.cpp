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
struct WaiterTipping
{
	int maxPercent( int total, int taxPercent, int money )
	{
		int result = -1;
		while( total + total * taxPercent / 100 + total * (result + 1) / 100 <= money )
			++result;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int total = 
	500
	; A0.push_back( total ); int taxPercent = 
	10
	; A1.push_back( taxPercent ); int money = 
	600
	; A2.push_back( money ); int result = 
	10
	; A3.push_back( result );  }
	{ /*Test 1*/int total = 
	500
	; A0.push_back( total ); int taxPercent = 
	10
	; A1.push_back( taxPercent ); int money = 
	604
	; A2.push_back( money ); int result = 
	10
	; A3.push_back( result );  }
	{ /*Test 2*/int total = 
	850
	; A0.push_back( total ); int taxPercent = 
	8
	; A1.push_back( taxPercent ); int money = 
	870
	; A2.push_back( money ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 3*/int total = 
	226
	; A0.push_back( total ); int taxPercent = 
	48
	; A1.push_back( taxPercent ); int money = 
	584
	; A2.push_back( money ); int result = 
	111
	; A3.push_back( result );  }
	{ /*Test 4*/int total = 
	123
	; A0.push_back( total ); int taxPercent = 
	52
	; A1.push_back( taxPercent ); int money = 
	696
	; A2.push_back( money ); int result = 
	415
	; A3.push_back( result );  }
	{ /*Test 5*/int total = 
	500
	; A0.push_back( total ); int taxPercent = 
	10
	; A1.push_back( taxPercent ); int money = 
	550
	; A2.push_back( money ); int result = 
	0
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], maxPercent( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WaiterTipping ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
