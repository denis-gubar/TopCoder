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
struct ParallelSpeedup
{
	int numProcessors( int k, int overhead )
	{
		int result = -1, best = 1 << 30;
		for( int i = 1; i < 1000; ++i )
			if ( best > overhead * i * (i - 1) / 2 + (k + i - 1) / i )
			{
				best = overhead * i * (i - 1) / 2 + (k + i - 1) / i;
				result = i;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/int k = 
	12
	; A0.push_back( k ); int overhead = 
	1
	; A1.push_back( overhead ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/int k = 
	50
	; A0.push_back( k ); int overhead = 
	3
	; A1.push_back( overhead ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 2*/int k = 
	9
	; A0.push_back( k ); int overhead = 
	10
	; A1.push_back( overhead ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 3*/int k = 
	3333
	; A0.push_back( k ); int overhead = 
	2
	; A1.push_back( overhead ); int result = 
	12
	; A2.push_back( result );  }
	{ /*Test 4*/int k = 
	1000000
	; A0.push_back( k ); int overhead = 
	4
	; A1.push_back( overhead ); int result = 
	63
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], numProcessors( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ParallelSpeedup ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
