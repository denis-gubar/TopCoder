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
struct ComputerExpert
{
	vs operate( vs facts, vs rules )
	{
		vs result;
		sort( all(facts) );
		facts.erase( unique( all(facts) ), facts.end() );
		int n;
		do
		{
			n = result.size();
			fora(i, rules)
			{
				vs a(split( rules[i], " ->" ));
				if ( !binary_search( all(facts), a[1] ) )
				{
					bool flag = true;
					vs b(split( a[0], "," ));
					fora(j, b)
					{
						bool f = false;
						vs c(split( b[j], "/" ));
						fora(k, c)
							f |= binary_search( all(facts), c[k] );
						flag &= f;
					}
					if ( flag )
					{
						result.push_back( a[1] );
						facts.push_back( a[1] );
						sort( all(facts) );
					}
				}
			}
		} while ( n < result.size() );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vs> A2;
	{ /*Test 0*/string _facts[] = 
	{"SKY_IS_CLOUDY","HAVE_MONEY"}
	; vs facts(_facts, _facts + (sizeof(_facts) / sizeof(_facts[0]))); A0.push_back( facts ); string _rules[] = 
	{"HAVE_MONEY,BAD_WEATHER -> WATCH_MOVIE","SKY_IS_CLOUDY -> BAD_WEATHER",
"GOOD_WEATHER -> PLAY_SOCCER"}
	; vs rules(_rules, _rules + (sizeof(_rules) / sizeof(_rules[0]))); A1.push_back( rules ); string _result[] = 
	{"BAD_WEATHER", "WATCH_MOVIE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _facts[] = 
	{"NEEDLE_LEAF","KEEPS_LEAVES"}
	; vs facts(_facts, _facts + (sizeof(_facts) / sizeof(_facts[0]))); A0.push_back( facts ); string _rules[] = 
	{"KEEPS_LEAVES -> EVERGREEN","NEEDLE_LEAF -> GYMNOSPERM",
"EVERGREEN,GYMNOSPERM -> PINE_TREE"}
	; vs rules(_rules, _rules + (sizeof(_rules) / sizeof(_rules[0]))); A1.push_back( rules ); string _result[] = 
	{"EVERGREEN", "GYMNOSPERM", "PINE_TREE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _facts[] = 
	{"I"}
	; vs facts(_facts, _facts + (sizeof(_facts) / sizeof(_facts[0]))); A0.push_back( facts ); string _rules[] = 
	{"I -> I","P -> CONSONANT", "Z -> CONSONANT", "A/E/I/O/U -> VOWEL"}
	; vs rules(_rules, _rules + (sizeof(_rules) / sizeof(_rules[0]))); A1.push_back( rules ); string _result[] = 
	{"VOWEL" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _facts[] = 
	{"Y","W","L","T","H","J","G","T","F","P","T","P","P","N"}
	; vs facts(_facts, _facts + (sizeof(_facts) / sizeof(_facts[0]))); A0.push_back( facts ); string _rules[] = 
	{"C/V,J,F/T,N,W,L -> M","N/L,F,B/N/E,Y -> C",
"M,G,G,S/F/Q,G,S/G,H/Z,W,F,C,Q/F,M -> E"}
	; vs rules(_rules, _rules + (sizeof(_rules) / sizeof(_rules[0]))); A1.push_back( rules ); string _result[] = 
	{"C", "E", "M" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 4*/string _facts[] = 
	{"G","H"}
	; vs facts(_facts, _facts + (sizeof(_facts) / sizeof(_facts[0]))); A0.push_back( facts ); string _rules[] = 
	{"A/B/C/D/E/F,G/Z -> Y", "H,H,H,H,H,H,H,H -> Z"}
	; vs rules(_rules, _rules + (sizeof(_rules) / sizeof(_rules[0]))); A1.push_back( rules ); string _result[] = 
	{"Z" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 5*/string _facts[] = 
	{"A","B","_X", "X_"}
	; vs facts(_facts, _facts + (sizeof(_facts) / sizeof(_facts[0]))); A0.push_back( facts ); string _rules[] = 
	{"A/B,C -> D","A,B,C -> D","X -> Y","_X_ -> Y"}
	; vs rules(_rules, _rules + (sizeof(_rules) / sizeof(_rules[0]))); A1.push_back( rules ); vs result; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], operate( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ComputerExpert ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
