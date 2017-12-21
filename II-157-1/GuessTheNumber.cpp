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
struct GuessTheNumber
{
	int noGuesses( int upper, int answer )
	{
		int result = 0, x = 0, a = 1, b = upper;
		do
		{
			++result;
			x = (a + b) / 2;
			if ( x < answer ) a = x + 1;
			if ( x > answer ) b = x - 1;
		} while ( x != answer );
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
	{ /*Test 0*/int upper = 
	9
	; A0.push_back( upper ); int answer = 
	6
	; A1.push_back( answer ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 1*/int upper = 
	1000
	; A0.push_back( upper ); int answer = 
	750
	; A1.push_back( answer ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 2*/int upper = 
	643
	; A0.push_back( upper ); int answer = 
	327
	; A1.push_back( answer ); int result = 
	7
	; A2.push_back( result );  }
	{ /*Test 3*/int upper = 
	157
	; A0.push_back( upper ); int answer = 
	157
	; A1.push_back( answer ); int result = 
	8
	; A2.push_back( result );  }
	{ /*Test 4*/int upper = 
	128
	; A0.push_back( upper ); int answer = 
	64
	; A1.push_back( answer ); int result = 
	1
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], noGuesses( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	GuessTheNumber ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
