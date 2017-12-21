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
#define all(v) (v).begin(), (v).end()
struct LeaguePicks
{
	vi returnPicks( int position, int friends, int picks )
	{
		vi result;
		for( int i = position; i <= picks; i += 2 * friends )
			result.push_back( i );
		for( int i = 2 * friends - position + 1; i <= picks; i += 2 * friends )
			result.push_back( i );
		sort( all(result) );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<vi> A3;
	{ /*Test 0*/int position = 
	3
	; A0.push_back( position ); int friends = 
	6
	; A1.push_back( friends ); int picks = 
	15
	; A2.push_back( picks ); int _result[] = 
	{ 3,  10,  15 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 1*/int position = 
	1
	; A0.push_back( position ); int friends = 
	1
	; A1.push_back( friends ); int picks = 
	10
	; A2.push_back( picks ); int _result[] = 
	{ 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 2*/int position = 
	1
	; A0.push_back( position ); int friends = 
	2
	; A1.push_back( friends ); int picks = 
	39
	; A2.push_back( picks ); int _result[] = 
	{ 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 3*/int position = 
	5
	; A0.push_back( position ); int friends = 
	11
	; A1.push_back( friends ); int picks = 
	100
	; A2.push_back( picks ); int _result[] = 
	{ 5,  18,  27,  40,  49,  62,  71,  84,  93 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], returnPicks( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	LeaguePicks ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
