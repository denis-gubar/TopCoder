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
#define all(v) (v).begin(), (v).end()
struct OldestOne
{
	struct comp: binary_function<string, string, bool>
	{
		int getAge( const string& a ) const
		{
			string temp( find_if( all(a), ::isdigit ), a.end() );
			istringstream s( temp );
			int result; s >> result;
			return result;
		}
		bool operator() ( const string& a, const string& b ) const
		{
			return getAge( a ) > getAge( b );
		}
	};
	string trim( const string& s ) const
	{
		int i, j;
		for( i = 0; i < s.size() && s[i] == ' '; ++i );
		for( j = s.size() - 1; i >= 0 && s[j] == ' '; --j );
		return s.substr( i, j - i + 1 );
	}
	string getName( const string& s ) const
	{
		string temp( s.begin(), find_if( all(s), ::isdigit ) );
		return trim( temp );
	}
	string oldest( vs data )
	{
		return getName( *min_element( all(data), comp() ) );
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
	{ /*Test 0*/string _data[] = 
	{"DOUG JONES 22 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string result = 
	"BOB     A SMITH"
	; A1.push_back( result );  }
	{ /*Test 1*/string _data[] = 
	{"DOUG JONES 102 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",
 "A 1 999ELM"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string result = 
	"DOUG JONES"
	; A1.push_back( result );  }
	{ /*Test 2*/string _data[] = 
	{"DOUG JONES 122 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",
 "A 199 ELM"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string result = 
	"A"
	; A1.push_back( result );  }
	{ /*Test 3*/string _data[] = 
	{"   DOUG                 JONES   122 213 ALDEN LANE",
"   BOB     A SMITH                       102  3",
 " J O H N N Y           199 ELM"}
	; vs data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); string result = 
	"J O H N N Y"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], oldest( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	OldestOne ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
