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
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; --i)
struct Abacus
{
	vs add( vs original, int val )
	{
		int k = 0;
		fora(i, original)
			k = k * 10 + 9 - original[i].find( '-' );
		k += val;
		forad(i, original)
		{
			int z = k % 10;
			original[i] = string( 9 - z, 'o' ) + "---" + string( z, 'o' );
			k /= 10;
		}
		return original;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<vs> A2;
	{ /*Test 0*/string _original[] = 
	{"ooo---oooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "oo---ooooooo",
 "---ooooooooo"}
	; vs original(_original, _original + (sizeof(_original) / sizeof(_original[0]))); A0.push_back( original ); int val = 
	5
	; A1.push_back( val ); string _result[] = 
	{"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "o---oooooooo", "ooooo---oooo" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _original[] = 
	{"ooo---oooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "oo---ooooooo",
 "---ooooooooo"}
	; vs original(_original, _original + (sizeof(_original) / sizeof(_original[0]))); A0.push_back( original ); int val = 
	21
	; A1.push_back( val ); string _result[] = 
	{"oo---ooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _original[] = 
	{"ooooooooo---",
 "---ooooooooo",
 "ooooooooo---",
 "---ooooooooo",
 "oo---ooooooo",
 "---ooooooooo"}
	; vs original(_original, _original + (sizeof(_original) / sizeof(_original[0]))); A0.push_back( original ); int val = 
	100000
	; A1.push_back( val ); string _result[] = 
	{"oooooooo---o", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _original[] = 
	{"o---oooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo"
}
	; vs original(_original, _original + (sizeof(_original) / sizeof(_original[0]))); A0.push_back( original ); int val = 
	1
	; A1.push_back( val ); string _result[] = 
	{"---ooooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], add( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Abacus ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
