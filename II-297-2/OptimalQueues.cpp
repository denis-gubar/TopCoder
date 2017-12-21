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
#define all(v) (v).begin(), (v).end()
struct OptimalQueues
{
	int minWaitingTime( vi clientArrivals, int tellerCount, int serviceTime )
	{
        sort( all(clientArrivals), greater<int>() );
        vi A(clientArrivals);
        for( int n = 0; n < clientArrivals.size(); n += tellerCount )
            for( int k = n; k < clientArrivals.size(); ++k )
                A[k] += serviceTime;            
		return *max_element( all(A) );
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
	{ /*Test 0*/int _clientArrivals[] = 
	{1,2}
	; vi clientArrivals(_clientArrivals, _clientArrivals + (sizeof(_clientArrivals) / sizeof(_clientArrivals[0]))); A0.push_back( clientArrivals ); int tellerCount = 
	1
	; A1.push_back( tellerCount ); int serviceTime = 
	10
	; A2.push_back( serviceTime ); int result = 
	21
	; A3.push_back( result );  }
	{ /*Test 1*/int _clientArrivals[] = 
	{10}
	; vi clientArrivals(_clientArrivals, _clientArrivals + (sizeof(_clientArrivals) / sizeof(_clientArrivals[0]))); A0.push_back( clientArrivals ); int tellerCount = 
	50
	; A1.push_back( tellerCount ); int serviceTime = 
	50
	; A2.push_back( serviceTime ); int result = 
	60
	; A3.push_back( result );  }
	{ /*Test 2*/int _clientArrivals[] = 
	{10,10,10}
	; vi clientArrivals(_clientArrivals, _clientArrivals + (sizeof(_clientArrivals) / sizeof(_clientArrivals[0]))); A0.push_back( clientArrivals ); int tellerCount = 
	2
	; A1.push_back( tellerCount ); int serviceTime = 
	20
	; A2.push_back( serviceTime ); int result = 
	50
	; A3.push_back( result );  }
	{ /*Test 3*/int _clientArrivals[] = 
	{2,4,6,3,5}
	; vi clientArrivals(_clientArrivals, _clientArrivals + (sizeof(_clientArrivals) / sizeof(_clientArrivals[0]))); A0.push_back( clientArrivals ); int tellerCount = 
	3
	; A1.push_back( tellerCount ); int serviceTime = 
	10
	; A2.push_back( serviceTime ); int result = 
	23
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], minWaitingTime( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	OptimalQueues ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
