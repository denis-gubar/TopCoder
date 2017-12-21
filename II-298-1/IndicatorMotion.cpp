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
template<typename T> T FromString( const string& s, const T default_value = T() )
{
	istringstream S( s ); T result(default_value); S >> result; return result;
}
struct IndicatorMotion
{
	string getMotion( string program, char startState )
	{
		string result( 1, startState );
        for( int i = 0; i < program.size(); i += 3 )
        {
            int k = FromString<int>( program.substr( i + 1, 2 ) );
            for( int s = 0; s < k; ++ s )
            {
                switch( program[i] )
                {
                    case 'L':
                        switch( startState )
                        {
                            case '|':
                                startState = '\\';
                                break;
                            case '\\':
                                startState = '-';
                                break;
                            case '-':
                                startState = '/';
                                break;
                            case '/':
                                startState = '|';
                                break;
                        }
                        result += startState;
                        break;
                    case 'R':
                        switch( startState )
                        {
                            case '\\':
                                startState = '|';
                                break;
                            case '-':
                                startState = '\\';
                                break;
                            case '/':
                                startState = '-';
                                break;
                            case '|':
                                startState = '/';
                                break;
                        }
                        result += startState;
                        break;
                    case 'F':
                        switch( startState )
                        {
                            case '\\':
                                startState = '/';
                                break;
                            case '/':
                                startState = '\\';
                                break;
                            case '|':
                                startState = '-';
                                break;
                            case '-':
                                startState = '|';
                                break;
                        }
                        result += startState;
                        break;
                    case 'S':
                        result += startState;
                        break;
                }
            }
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<char> A1; vector<string> A2;
	{ /*Test 0*/string program = 
	"F03L02R03S02F04"
	; A0.push_back( program ); char startState = 
	'-'
	; A1.push_back( startState ); string result = 
	"-|-|\\-\\|///\\/\\/"
	; A2.push_back( result );  }
	{ /*Test 1*/string program = 
	"F10R01F10"
	; A0.push_back( program ); char startState = 
	'/'
	; A1.push_back( startState ); string result = 
	"/\\/\\/\\/\\/\\/-|-|-|-|-|-"
	; A2.push_back( result );  }
	{ /*Test 2*/string program = 
	""
	; A0.push_back( program ); char startState = 
	'/'
	; A1.push_back( startState ); string result = 
	"/"
	; A2.push_back( result );  }
	{ /*Test 3*/string program = 
	"F00R00L00S00"
	; A0.push_back( program ); char startState = 
	'\\'
	; A1.push_back( startState ); string result = 
	"\\"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getMotion( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	IndicatorMotion ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
