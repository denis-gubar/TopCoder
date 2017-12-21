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
struct CircleOrder
{
	string firstOrder( string circle )
	{
		string result;
        for( int z = circle.size(); z; z -= 2 )
        {
            bool flag = false;
            for( char c = 'a'; !flag && c <= 'z'; ++c )
            {
                int x = circle.find( c );
                if ( x != string::npos && circle.find( toupper( c ) ) != string::npos )
                {
                    string s( circle + circle );
                    bool f = true;
                    for( int i = x + 1; f && s[i] != toupper( c ); ++i )
                    {
                        f = (s[i] == ' ') || isupper( s[i] );
                    }
                    if ( f )
                    {
                        flag = true;
                        result += c;
                        circle[circle.find( toupper( c ) )] = c;
                        circle[x] = ' ';
                        continue;
                    }
                    f = true;
                    for( int i = circle.find( toupper(c) ) + 1; f && s[i] != c; ++i )
                    {
                        f = (s[i] == ' ') || isupper( s[i] );
                    }
                    if ( f )
                    {
                        flag = true;
                        result += c;
                        circle[circle.find( toupper( c ) )] = c;
                        circle[x] = ' ';
                    }
                }
            }
            if ( !flag )
                return "NONE";
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string circle = 
	"BACacb"
	; A0.push_back( circle ); string result = 
	"abc"
	; A1.push_back( result );  }
	{ /*Test 1*/string circle = 
	"ABCacb"
	; A0.push_back( circle ); string result = 
	"NONE"
	; A1.push_back( result );  }
	{ /*Test 2*/string circle = 
	"XYxPyp"
	; A0.push_back( circle ); string result = 
	"xyp"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], firstOrder( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CircleOrder ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
