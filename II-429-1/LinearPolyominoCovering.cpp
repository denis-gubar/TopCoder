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
#define all(v) (v).begin(), (v).end()
string replace_all( const string& s, const string& oldValue, const string& newValue )
{
	string result; size_t j = 0;
	for( size_t i = s.find( oldValue ), n = oldValue.size(); i != string::npos; i = s.find( oldValue, j ) )
		result += s.substr( j, i - j ) + newValue, j = i + n;
	return result + s.substr( j );
}
struct LinearPolyominoCovering
{
	string findCovering( string region )
	{
        string result = replace_all(replace_all(region, "XXXX", "AAAA"), "XX", "BB");
        if ( find(all(result), 'X') != result.end() )
            return "impossible";
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string region = 
	"XXXXXX"
	; A0.push_back( region ); string result = 
	"AAAABB"
	; A1.push_back( result );  }
	{ /*Test 1*/string region = 
	"XX.XX"
	; A0.push_back( region ); string result = 
	"BB.BB"
	; A1.push_back( result );  }
	{ /*Test 2*/string region = 
	"XXXX....XXX.....XX"
	; A0.push_back( region ); string result = 
	"impossible"
	; A1.push_back( result );  }
	{ /*Test 3*/string region = 
	"X"
	; A0.push_back( region ); string result = 
	"impossible"
	; A1.push_back( result );  }
	{ /*Test 4*/string region = 
	"XX.XXXXXXXXXX..XXXXXXXX...XXXXXX"
	; A0.push_back( region ); string result = 
	"BB.AAAAAAAABB..AAAAAAAA...AAAABB"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], findCovering( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	LinearPolyominoCovering ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
