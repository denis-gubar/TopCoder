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
struct Palindromist
{
    string calc( string s, const vs& words )
    {
        vs A(s.size());
        fora(i, A)
            for( int k = 0; k <= i; ++k )
                if ( (!k || A[k - 1] != "") && find( all(words), s.substr( k, i - k + 1 ) ) != words.end() )
                {
                    string t;
                    if ( !k )
                        t = s.substr( k, i - k + 1 );
                    else
                        t = A[k - 1] + " " + s.substr( k, i - k + 1 );
                    if ( A[i] == "" || A[i] > t )
                        A[i] = t;
                }
        return A.back();
    }
	string palindrome( string text, vs words )
	{
		string s(text);
        reverse( all(s) );
        string a = calc( text + s.substr( 1 ), words ), b = calc( text + s, words );
        if ( a == "" ) return b;
        if ( b == "" ) return a;
		return min( a, b );
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<vs> A1; vector<string> A2;
	{ /*Test 0*/string text = 
	"AMANAPLANAC"
	; A0.push_back( text ); string _words[] = 
	{ "A", "CANAL", "MAN", "PANAMA", "PLAN" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"A MAN A PLAN A CANAL PANAMA"
	; A2.push_back( result );  }
	{ /*Test 1*/string text = 
	"AAAAA"
	; A0.push_back( text ); string _words[] = 
	{ "AA", "A", "AAA" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"A A A A A A A A A"
	; A2.push_back( result );  }
	{ /*Test 2*/string text = 
	"CBA"
	; A0.push_back( text ); string _words[] = 
	{ "CBABC", "CBAABC" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"CBAABC"
	; A2.push_back( result );  }
	{ /*Test 3*/string text = 
	"RACEFAST"
	; A0.push_back( text ); string _words[] = 
	{ "AR", "CAR", "FAST", "RACE", "SAFE", "CEFA", "ACE", "STTS", "AFEC" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"RACE FAST SAFE CAR"
	; A2.push_back( result );  }
	{ /*Test 4*/string text = 
	"AABAABA"
	; A0.push_back( text ); string _words[] = 
	{ "AA", "AAB", "BAA", "BAB" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"AA BAA BAA BAA BAA"
	; A2.push_back( result );  }
	{ /*Test 5*/string text = 
	"STRAWNOTOOSTUPIDAF"
	; A0.push_back( text ); string _words[] = 
	{ "WARTS", "I", "TOO", "A", "FAD", "STUPID", "STRAW", "PUT", "NO", "ON", "SOOT" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"STRAW NO TOO STUPID A FAD I PUT SOOT ON WARTS"
	; A2.push_back( result );  }
	{ /*Test 6*/string text = 
	"AAAAA"
	; A0.push_back( text ); string _words[] = 
	{ "AAAA" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	""
	; A2.push_back( result );  }
	{ /*Test 7*/string text = 
	"A"
	; A0.push_back( text ); string _words[] = 
	{ "A", "AA" }
	; vs words(_words, _words + (sizeof(_words) / sizeof(_words[0]))); A1.push_back( words ); string result = 
	"A"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], palindrome( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Palindromist ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
