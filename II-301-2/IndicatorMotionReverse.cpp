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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct IndicatorMotionReverse
{
	string getMinProgram( vs actions )
	{
		string result, s( accumulate( all(actions), string() ) );
        string alphabet( "|N-/" ), commands( "LRSF" );
        vs M;
        M.push_back( "N-/|" );
        M.push_back( "/|N-" );
        M.push_back( "|N-/" );
        M.push_back( "-/|N" );
        vpii A;
        for( int i = 1; i < s.size(); ++i )
        {
            int k = alphabet.find( s[i - 1] );
            fora(j, M)
                if ( M[j][k] == s[i] )
                    if ( A.empty() || A.back().first != commands[j] )
                        A.push_back( make_pair( commands[j], 1 ) );
                    else
                        ++A.back().second;
        }
        fora(i, A)
        {
            string t;
            while( A[i].second > 99 )
            {
                t += string( 1, A[i].first ) + "99";
                A[i].second -= 99;
            }
            result += string( 1, A[i].first ) + ToString( 100 + A[i].second ).substr( 1 ) + t;
        }
        if ( result.size() > 100 )
            result = result.substr( 0, 97 ) + "...";
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _actions[] = 
	{"-|-|/-/|//////-/"}
	; vs actions(_actions, _actions + (sizeof(_actions) / sizeof(_actions[0]))); A0.push_back( actions ); string result = 
	"F03R02L02R01S05R01L01"
	; A1.push_back( result );  }
	{ /*Test 1*/string _actions[] = 
	{"N"}
	; vs actions(_actions, _actions + (sizeof(_actions) / sizeof(_actions[0]))); A0.push_back( actions ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 2*/string _actions[] = 
	{"||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||"}
	; vs actions(_actions, _actions + (sizeof(_actions) / sizeof(_actions[0]))); A0.push_back( actions ); string result = 
	"S50S99"
	; A1.push_back( result );  }
	{ /*Test 3*/string _actions[] = 
	{"N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N"}
	; vs actions(_actions, _actions + (sizeof(_actions) / sizeof(_actions[0]))); A0.push_back( actions ); string result = 
	"L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L..."
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], getMinProgram( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	IndicatorMotionReverse ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
