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
struct HourGlass
{
	vi measurable( int glass1, int glass2 )
	{
		vi result(10), A(10000, 0);
		for( int i = 0; i < 10; ++i )
			for( int j = 0; j < 10; ++j )
			{
				A[i * glass1 + j * glass2] = 1;
				for( int k = 0; k < 10; ++k )
					A[i * glass1 + k * abs( i * glass1 - j * glass2 )] = 1;
			}
		for( int i = 0, j = 1; i < 10; ++j )
			if ( A[j] )
				result[i++] = j;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vi> A2;
	{ /*Test 0*/int glass1 = 
	5
	; A0.push_back( glass1 ); int glass2 = 
	7
	; A1.push_back( glass2 ); int _result[] = 
	{ 5,  7,  9,  10,  11,  12,  13,  14,  15,  16 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/int glass1 = 
	13
	; A0.push_back( glass1 ); int glass2 = 
	5
	; A1.push_back( glass2 ); int _result[] = 
	{ 5,  10,  13,  15,  16,  17,  18,  19,  20,  21 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/int glass1 = 
	23
	; A0.push_back( glass1 ); int glass2 = 
	23
	; A1.push_back( glass2 ); int _result[] = 
	{ 23,  46,  69,  92,  115,  138,  161,  184,  207,  230 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/int glass1 = 
	24
	; A0.push_back( glass1 ); int glass2 = 
	30
	; A1.push_back( glass2 ); int _result[] = 
	{ 24,  30,  36,  42,  48,  54,  60,  66,  72,  78 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 4*/int glass1 = 
	1
	; A0.push_back( glass1 ); int glass2 = 
	50
	; A1.push_back( glass2 ); int _result[] = 
	{ 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], measurable( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	HourGlass ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
