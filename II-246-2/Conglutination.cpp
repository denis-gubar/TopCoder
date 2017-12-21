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
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
template<typename T> T FromString( const string& s, const T default_value = T() )
{
	istringstream S( s ); T result(default_value); S >> result; return result;
}
struct Conglutination
{
	string normalize( const string& s )
	{
		string result("0");
		int i = s.find_first_not_of('0');
		if ( i != string::npos )
			result = s.substr( i );
		return result;
	}
	string split( string conglutination, int expectation )
	{
		string result;
		string sum( ToString( expectation ) );
		for( int i = 1; i < conglutination.size(); ++i )
		{
			string a( conglutination.substr( 0, i ) ), b( conglutination.substr( i ) );
			string x( normalize( a ) ), y( normalize( b ) );
			if ( x.size() <= sum.size() && y.size() <= sum.size() && FromString<int>( x ) + FromString<int>( y ) == expectation )
				return a + "+" + b;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<int> A1; vector<string> A2;
	{ /*Test 0*/string conglutination = 
	"22"
	; A0.push_back( conglutination ); int expectation = 
	4
	; A1.push_back( expectation ); string result = 
	"2+2"
	; A2.push_back( result );  }
	{ /*Test 1*/string conglutination = 
	"536"
	; A0.push_back( conglutination ); int expectation = 
	41
	; A1.push_back( expectation ); string result = 
	"5+36"
	; A2.push_back( result );  }
	{ /*Test 2*/string conglutination = 
	"123456000789"
	; A0.push_back( conglutination ); int expectation = 
	1235349
	; A1.push_back( expectation ); string result = 
	"1234560+00789"
	; A2.push_back( result );  }
	{ /*Test 3*/string conglutination = 
	"123456789"
	; A0.push_back( conglutination ); int expectation = 
	4245
	; A1.push_back( expectation ); string result = 
	""
	; A2.push_back( result );  }
	{ /*Test 4*/string conglutination = 
	"112"
	; A0.push_back( conglutination ); int expectation = 
	13
	; A1.push_back( expectation ); string result = 
	"1+12"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], split( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Conglutination ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
