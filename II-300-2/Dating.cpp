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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
string replace_all( const string& s, const string& oldValue, const string& newValue )
{
	string result; size_t j = 0;
	for( size_t i = s.find( oldValue ), n = oldValue.size(); i != string::npos; i = s.find( oldValue, j ) )
		result += s.substr( j, i - j ) + newValue, j = i + n;
	return result + s.substr( j );
}
struct Dating
{
	string dates( string circle, int k )
	{
		string result;
        int z = 0; --k;
        while( circle.size() > 1 )
        {
            z = (z + k) % circle.size();
            char x = circle[z];
            circle[z] = ' ';
            circle = replace_all( circle, " ", "" );
            string next = (circle + circle).substr( z, 2 );
            string s(1, 127);
            if ( ::isupper( x ) )
            {
                fora( i, circle )
                    if ( ::islower( circle[i] ) )
                        s += circle[i];
            }
            else
            {
                fora( i, circle )
                    if ( ::isupper( circle[i] ) )
                        s += circle[i];
            }
            char y = *min_element( all(s) );
            if ( y == 127 )
                return result;
            next = replace_all( next, string(1, y), "" );
            circle = replace_all( circle, string(1, y), "" );
            z = circle.find( next[0] );
            result += (result.empty() ? string() : string(" ")) + x + y;
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
	{ /*Test 0*/string circle = 
	"abXCd"
	; A0.push_back( circle ); int k = 
	2
	; A1.push_back( k ); string result = 
	"bC dX"
	; A2.push_back( result );  }
	{ /*Test 1*/string circle = 
	"abXCd"
	; A0.push_back( circle ); int k = 
	8
	; A1.push_back( k ); string result = 
	"Xa dC"
	; A2.push_back( result );  }
	{ /*Test 2*/string circle = 
	"HGFhgfz"
	; A0.push_back( circle ); int k = 
	1
	; A1.push_back( k ); string result = 
	"Hf Gg Fh"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], dates( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Dating ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
