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
struct NounReform
{
    string calc( string s, int k )
    {
        return (string( k, ' ' ) + s).substr( s.size() );
    }
	vs makePlural( vs nouns )
	{
		vs result( nouns.size() );
        fora(i, nouns)
        {
            string s = nouns[i];
            if ( calc( s, 1 ) == "s" || calc( s, 1 ) == "x" || calc( s, 1 ) == "z" ||
                calc( s, 2 ) == "sh" || calc( s, 2 ) == "ch" )
                result[i] = nouns[i] + "es";
            else if ( calc( s, 2 ) == "ay" || calc( s, 2 ) == "oy" || calc( s, 2 ) == "iy" ||
                calc( s, 2 ) == "ey" || calc( s, 2 ) == "uy" )
                result[i] = nouns[i] + "s";
            else if ( calc( s, 1 ) == "y" )
                result[i] = nouns[i].substr( 0, nouns[i].size() - 1 ) + "ies";
            else
                result[i] = nouns[i] + "s";
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _nouns[] = 
	{"box", "church", "elephant", "stereo"}
	; vs nouns(_nouns, _nouns + (sizeof(_nouns) / sizeof(_nouns[0]))); A0.push_back( nouns ); string _result[] = 
	{"boxes", "churches", "elephants", "stereos" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _nouns[] = 
	{"tray", "key", "enemy", "baby"}
	; vs nouns(_nouns, _nouns + (sizeof(_nouns) / sizeof(_nouns[0]))); A0.push_back( nouns ); string _result[] = 
	{"trays", "keys", "enemies", "babies" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _nouns[] = 
	{"a", "s", "oy", "y", "yy"}
	; vs nouns(_nouns, _nouns + (sizeof(_nouns) / sizeof(_nouns[0]))); A0.push_back( nouns ); string _result[] = 
	{"as", "ses", "oys", "ies", "yies" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], makePlural( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NounReform ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
