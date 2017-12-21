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
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct CalcButton
{
	int check( const string& s, const string& t )
	{
		int result = 0;
		for( int i = 0; i + t.size() <= s.size(); ++i )
			if ( s.substr( i, t.size() ) == t )
			{
				++result;
				i += t.size() - 1;
			}
		return result;
	}
	string getDigits( vs sequence )
	{
		string result("000");
		int best = 0;
		string s( accumulate( all(sequence), string() ) );
		for( int i = 1000; i < 2000; ++i )
		{
			string current( ToString(i).substr( 1 ) );
			int c = check( s, current );
			if ( c > best )
			{
				best = c;
				result = current;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _sequence[] = 
	{"100002000"}
	; vs sequence(_sequence, _sequence + (sizeof(_sequence) / sizeof(_sequence[0]))); A0.push_back( sequence ); string result = 
	"000"
	; A1.push_back( result );  }
	{ /*Test 1*/string _sequence[] = 
	{"777777777"}
	; vs sequence(_sequence, _sequence + (sizeof(_sequence) / sizeof(_sequence[0]))); A0.push_back( sequence ); string result = 
	"777"
	; A1.push_back( result );  }
	{ /*Test 2*/string _sequence[] = 
	{"6503","210"}
	; vs sequence(_sequence, _sequence + (sizeof(_sequence) / sizeof(_sequence[0]))); A0.push_back( sequence ); string result = 
	"032"
	; A1.push_back( result );  }
	{ /*Test 3*/string _sequence[] = 
	{"0993034","6","4137","45959935","25939","93993","0","9358333"}
	; vs sequence(_sequence, _sequence + (sizeof(_sequence) / sizeof(_sequence[0]))); A0.push_back( sequence ); string result = 
	"993"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], getDigits( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CalcButton ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
