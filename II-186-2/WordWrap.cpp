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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
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
struct split_helper: unary_function<int, bool>
{
	explicit split_helper( string delimeter ): delimeter(delimeter) {};
	bool operator() ( int c ) const
	{
		return delimeter.find( c ) == string::npos;
	}
private: string delimeter;
};
vs split( const string& s, const string& delimeter = " ", bool skipEmpty = true )
{
	return parse( s, split_helper( delimeter ), skipEmpty );
}
struct WordWrap
{
	vs justify( vs lines, int columnWidth )
	{
		vs result;
		string text;
		fora(i, lines)
			text += lines[i] + ' ';
		vs z( split(text) );
		string s;
		fora(i, z)
			if ( s.size() + z[i].size() + !s.empty() <= columnWidth )
				s += (!s.empty() ? string(1, ' ') : string()) + z[i];
			else
			{
				result.push_back( s );
				s = z[i];
			}
		if ( !s.empty() )
			result.push_back( s );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<vs> A2;
	{ /*Test 0*/string _lines[] = 
	{"now is the time for all good men",
 "to come to the aid of their country"}
	; vs lines(_lines, _lines + (sizeof(_lines) / sizeof(_lines[0]))); A0.push_back( lines ); int columnWidth = 
	20
	; A1.push_back( columnWidth ); string _result[] = 
	{ "now is the time for",  "all good men to come",  "to the aid of their",  "country" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _lines[] = 
	{"now",
 "is the time for",
 "all",
 "good",
 "men",
 "to",
 "come to the aid",
 "of",
 "their",
 "country"}
	; vs lines(_lines, _lines + (sizeof(_lines) / sizeof(_lines[0]))); A0.push_back( lines ); int columnWidth = 
	20
	; A1.push_back( columnWidth ); string _result[] = 
	{ "now is the time for",  "all good men to come",  "to the aid of their",  "country" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _lines[] = 
	{"four score and seven years ago", 
 "our fathers brought forth",
 "upon this continent",
 "a new nation",
 "conceived in liberty", 
 "and dedicated to the proposition", 
 "that all men are created",
 "equal"}
	; vs lines(_lines, _lines + (sizeof(_lines) / sizeof(_lines[0]))); A0.push_back( lines ); int columnWidth = 
	50
	; A1.push_back( columnWidth ); string _result[] = 
	{ "four score and seven years ago our fathers brought",  "forth upon this continent a new nation conceived",  "in liberty and dedicated to the proposition that",  "all men are created equal" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _lines[] = 
	{"th e ow l an d th e pu ss yc at",
 "we nt to se a",
 "on a be au ti fu l pe a gr ee n bo at"}
	; vs lines(_lines, _lines + (sizeof(_lines) / sizeof(_lines[0]))); A0.push_back( lines ); int columnWidth = 
	4
	; A1.push_back( columnWidth ); string _result[] = 
	{ "th e",  "ow l",  "an d",  "th e",  "pu",  "ss",  "yc",  "at",  "we",  "nt",  "to",  "se a",  "on a",  "be",  "au",  "ti",  "fu l",  "pe a",  "gr",  "ee n",  "bo",  "at" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], justify( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WordWrap ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
