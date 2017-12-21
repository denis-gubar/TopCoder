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
typedef long long lint;
typedef vector<string> vs;
#define all(v) (v).begin(), (v).end()
template<typename T> T FromString( string s )
{
	istringstream S( s ); T result; S >> result; return result;
}
template<typename Predicate> vs parse( string s, Predicate predicate, bool skipEmpty = true )
{
	vs result; bool isWord = false; int j = 0;
	for( int i = 0; i < s.size(); i++ )
		if ( isWord )
		{
			if ( !predicate( s[i] ) )
			{
				result.push_back( s.substr( j, i - j ) ); isWord = false;
			}
		}
		else
		{
			if ( predicate( s[i] ) )
			{
				j = i; isWord = true;
			} else if ( !skipEmpty )
				result.push_back( "" );
		}
		if ( isWord )
			result.push_back( s.substr( j ) );
		else if ( !skipEmpty && !s.empty() )
			result.push_back( "" );
		return result;
}
struct HiddenNumbers
{
	struct comp: binary_function<string, string, bool>
	{
		bool operator() ( const string& a, const string& b ) const
		{
			lint A = FromString<lint>( a ), B = FromString<lint>( b );
			if ( A != B )
				return A < B;
			return a.size() < b.size();
		}
	};
	vs findAll( vs text )
	{
		vs result( parse( accumulate( all(text), string() ), ::isdigit) );
		sort( all(result), comp() );
		return vs( result.begin() + result.size() / 2, result.end() );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _text[] = 
	{"098m03r9f80239802389f0m9KDKLKLJDKLJm0983m890DMOm03",
 "dlkfj3hljf4h3klhl  4j4 444 44  rjhkrrkr34534539893",
 " 390804980498409480 dkldjkl djkl djkl d00000002998"}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); string _result[] = 
	{ "9",  "44",  "098",  "444",  "890",  "0983",  "00000002998",  "34534539893",  "80239802389",  "390804980498409480" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _text[] = 
	{"39 000220 30 skldjdije939939slkk 3090 2912kjdk3949",
 "dlkjd dkljsl098 dkd3 23kdkdkl 0000002222kdjdie9000"}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); string _result[] = 
	{ "0000002222",  "2912",  "3090",  "3949",  "9000",  "939939" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/vs text; A0.push_back( text ); vs result; A1.push_back( result );  }
	{ /*Test 3*/string _text[] = 
	{"0022 22k00022a022"}
	; vs text(_text, _text + (sizeof(_text) / sizeof(_text[0]))); A0.push_back( text ); string _result[] = 
	{ "0022",  "00022" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], findAll( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	HiddenNumbers ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
