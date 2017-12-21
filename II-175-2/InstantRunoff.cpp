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
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
string replace_all( string s, string oldValue, string newValue )
{
	string result; int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
struct InstantRunoff
{
	string outcome( string candidates, vs ballots )
	{
		if ( candidates.empty() ) return "";
		int n = ballots.size();
		vi count( 256, -1 );
		fora(i, candidates)
			count[candidates[i]] = 0;
		fora(i, ballots)
			++count[ballots[i][0]];
		fora(i, count)
			if ( count[i] * 2 > n )
				return string(1, i);
		int m = n;
		fora(i, count)
			if ( count[i] >= 0 && count[i] < m )
				m = count[i];
		fora(i, count)
			if ( count[i] == m )
			{
				candidates = replace_all( candidates, string(1, i), "" );
				fora(j, ballots)
					ballots[j] = replace_all( ballots[j], string(1, i), "" );
			}
		return outcome( candidates, ballots );
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
	{ /*Test 0*/string candidates = 
	"ABC"
	; A0.push_back( candidates ); string _ballots[] = 
	{"ACB", "BCA", "ACB", "BCA", "CBA"}
	; vs ballots(_ballots, _ballots + (sizeof(_ballots) / sizeof(_ballots[0]))); A1.push_back( ballots ); string result = 
	"B"
	; A2.push_back( result );  }
	{ /*Test 1*/string candidates = 
	"DCBA"
	; A0.push_back( candidates ); string _ballots[] = 
	{"ACBD", "ACBD", "ACBD", "BCAD", "BCAD", "DBCA", "CBDA"}
	; vs ballots(_ballots, _ballots + (sizeof(_ballots) / sizeof(_ballots[0]))); A1.push_back( ballots ); string result = 
	"B"
	; A2.push_back( result );  }
	{ /*Test 2*/string candidates = 
	"ACB"
	; A0.push_back( candidates ); string _ballots[] = 
	{"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CBA", "CAB"}
	; vs ballots(_ballots, _ballots + (sizeof(_ballots) / sizeof(_ballots[0]))); A1.push_back( ballots ); string result = 
	""
	; A2.push_back( result );  }
	{ /*Test 3*/string candidates = 
	"CAB"
	; A0.push_back( candidates ); string _ballots[] = 
	{"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CAB", "CAB"}
	; vs ballots(_ballots, _ballots + (sizeof(_ballots) / sizeof(_ballots[0]))); A1.push_back( ballots ); string result = 
	"A"
	; A2.push_back( result );  }
	{ /*Test 4*/string candidates = 
	"Z"
	; A0.push_back( candidates ); string _ballots[] = 
	{"Z"}
	; vs ballots(_ballots, _ballots + (sizeof(_ballots) / sizeof(_ballots[0]))); A1.push_back( ballots ); string result = 
	"Z"
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], outcome( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	InstantRunoff ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
