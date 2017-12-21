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
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
struct BirthdayOdds
{
	int minPeople( int minOdds, int daysInYear )
	{
		for( int i = 2; ;i++ )
		{
			double p = 1;
			for( int j = 0; j < i; j++ )
				p *= 1.0 * (daysInYear - j) / daysInYear;
			if ( 100 * (1 - p) >= minOdds )
				return i;
		}
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/int Arg0 = 
	75
	; A0.push_back( Arg0 ); int Arg1 = 
	5
	; A1.push_back( Arg1 ); int Arg2 = 
	4
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/int Arg0 = 
	50
	; A0.push_back( Arg0 ); int Arg1 = 
	365
	; A1.push_back( Arg1 ); int Arg2 = 
	23
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/int Arg0 = 
	1
	; A0.push_back( Arg0 ); int Arg1 = 
	365
	; A1.push_back( Arg1 ); int Arg2 = 
	4
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/int Arg0 = 
	84
	; A0.push_back( Arg0 ); int Arg1 = 
	9227
	; A1.push_back( Arg1 ); int Arg2 = 
	184
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], minPeople( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BirthdayOdds ___test;
	___test.run_test();
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
