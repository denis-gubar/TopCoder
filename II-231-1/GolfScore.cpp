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
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
#define ToVector(x, _x) x( _x, _x + sizeof(_x)/sizeof(_x[0]) )
struct GolfScore
{
	int tally( vi parValues, vs scoreSheet )
	{
		string x_[] = {"triple bogey", "double bogey", "bogey", "par", "birdie", "eagle", "albatross", "hole in one" };
		vs ToVector(x, x_);		
		int result = 0;
		fora(i, parValues)
		{
			int k = distance( x.begin(), find( all(x), scoreSheet[i] ) );
			if ( k == 7 )
				++result;
			else
				result += parValues[i] + 3 - k;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vs> A1; vector<int> A2;
	{ /*Test 0*/int _parValues[] = 
	{1, 1, 1, 1, 1, 1,
 1, 1, 1, 5, 5, 5,
 5, 5, 5, 5, 5, 5}
	; vi parValues(_parValues, _parValues + (sizeof(_parValues) / sizeof(_parValues[0]))); A0.push_back( parValues ); string _scoreSheet[] = 
	{"bogey", "bogey", "bogey", "bogey", "bogey", "bogey",
 "bogey", "bogey", "bogey", "eagle", "eagle", "eagle",
 "eagle", "eagle", "eagle", "eagle", "eagle", "eagle"}
	; vs scoreSheet(_scoreSheet, _scoreSheet + (sizeof(_scoreSheet) / sizeof(_scoreSheet[0]))); A1.push_back( scoreSheet ); int result = 
	45
	; A2.push_back( result );  }
	{ /*Test 1*/int _parValues[] = 
	{3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2}
	; vi parValues(_parValues, _parValues + (sizeof(_parValues) / sizeof(_parValues[0]))); A0.push_back( parValues ); string _scoreSheet[] = 
	{"bogey", "double bogey", "par", "double bogey", "double bogey", "triple bogey",
 "triple bogey", "triple bogey", "bogey", "double bogey", "par", "par",
 "par", "double bogey", "bogey", "triple bogey", "bogey", "double bogey"}
	; vs scoreSheet(_scoreSheet, _scoreSheet + (sizeof(_scoreSheet) / sizeof(_scoreSheet[0]))); A1.push_back( scoreSheet ); int result = 
	72
	; A2.push_back( result );  }
	{ /*Test 2*/int _parValues[] = 
	{3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2}
	; vi parValues(_parValues, _parValues + (sizeof(_parValues) / sizeof(_parValues[0]))); A0.push_back( parValues ); string _scoreSheet[] = 
	{"eagle", "birdie", "albatross", "birdie", "birdie", "par",
 "hole in one", "par", "eagle", "birdie", "albatross", "albatross",
 "albatross", "birdie", "eagle", "hole in one", "eagle", "birdie"}
	; vs scoreSheet(_scoreSheet, _scoreSheet + (sizeof(_scoreSheet) / sizeof(_scoreSheet[0]))); A1.push_back( scoreSheet ); int result = 
	18
	; A2.push_back( result );  }
	{ /*Test 3*/int _parValues[] = 
	{4, 1, 3, 3, 4, 4,
 1, 4, 2, 3, 3, 5,
 4, 1, 4, 4, 2, 1}
	; vi parValues(_parValues, _parValues + (sizeof(_parValues) / sizeof(_parValues[0]))); A0.push_back( parValues ); string _scoreSheet[] = 
	{"triple bogey", "triple bogey", "bogey", "par", "triple bogey", "double bogey",
 "triple bogey", "triple bogey", "par", "eagle", "bogey", "bogey",
 "birdie", "par", "triple bogey", "eagle", "triple bogey", "triple bogey"}
	; vs scoreSheet(_scoreSheet, _scoreSheet + (sizeof(_scoreSheet) / sizeof(_scoreSheet[0]))); A1.push_back( scoreSheet ); int result = 
	77
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], tally( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	GolfScore ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
