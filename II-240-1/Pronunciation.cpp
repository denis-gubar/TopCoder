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
#define all(v) (v).begin(), (v).end()
struct Pronunciation
{
	char convert( char c )
	{
		return string( "aeuio" ).find( c ) == string::npos ? 'C' : 'V';
	}
	bool calc( string s )
	{
		transform( all(s), s.begin(), ::tolower );
		string t;
		fora(i, s)
			t += convert( s[i] );
		if ( t.find( "CCC" ) != string::npos ) return true;
		s.erase( unique( all(s) ), s.end() );
		t.clear();
		fora(i, s)
			t += convert( s[i] );
		return t.find( "VV" ) != string::npos;
	}
	string canPronounce( vs words )
	{
		fora(i, words)
			if ( calc( words[i] ) )
				return words[i];
		return string();
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _words[] = 
	{"All","of","these","are","not","difficult"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 1*/string _words[] = 
	{"The","word","REALLY","is","really","hard"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"REALLY"
	; A1.push_back( result );  }
	{ /*Test 2*/string _words[] = 
	{"TRiCKy"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	"TRiCKy"
	; A1.push_back( result );  }
	{ /*Test 3*/string _words[] = 
	{"irresistable","prerogative","uttermost","importance"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 4*/string _words[] = 
	{"Aa"}
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A0.push_back( words ); string result = 
	""
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], canPronounce( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Pronunciation ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
