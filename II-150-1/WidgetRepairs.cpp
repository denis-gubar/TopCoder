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
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef vector<int> vi;
struct WidgetRepairs
{
	int days( vi arrivals, int numPerDay )
	{
		int result = 0;
		int left = 0;
		for( int i = 0; i < 20000; ++i )
		{
			if ( i < arrivals.size()  )
				left += arrivals[i];
			if ( left )
			{
				++result; left = max( 0, left - numPerDay );
			}
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
	{ /*Test 0*/int _arrivals[] = 
	{ 10, 0, 0, 4, 20 }
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A0.push_back( arrivals ); int numPerDay = 
	8
	; A1.push_back( numPerDay ); int result = 
	6
	; A2.push_back( result );  }
	{ /*Test 1*/int _arrivals[] = 
	{ 0, 0, 0 }
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A0.push_back( arrivals ); int numPerDay = 
	10
	; A1.push_back( numPerDay ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 2*/int _arrivals[] = 
	{ 100, 100 }
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A0.push_back( arrivals ); int numPerDay = 
	10
	; A1.push_back( numPerDay ); int result = 
	20
	; A2.push_back( result );  }
	{ /*Test 3*/int _arrivals[] = 
	{ 27, 0, 0, 0, 0, 9 }
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A0.push_back( arrivals ); int numPerDay = 
	9
	; A1.push_back( numPerDay ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 4*/int _arrivals[] = 
	{ 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 }
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A0.push_back( arrivals ); int numPerDay = 
	3
	; A1.push_back( numPerDay ); int result = 
	15
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], days( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WidgetRepairs ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
