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
typedef vector<vs> vvs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct Matching
{
	vs findMatch( vs first, vs second )
	{
		vs result;
		vvs A(4);
		A[0].push_back( "CIRCLE" );
		A[0].push_back( "SQUIGGLE" );
		A[0].push_back( "DIAMOND" );
		A[1].push_back( "RED" );
		A[1].push_back( "BLUE" );
		A[1].push_back( "GREEN" );
		A[2].push_back( "SOLID" );
		A[2].push_back( "STRIPED" );
		A[2].push_back( "EMPTY" );
		A[3].push_back( "ONE" );
		A[3].push_back( "TWO" );
		A[3].push_back( "THREE" );
		fora(i, first)
			if ( first[i] == second[i] )
				result.push_back( first[i] );
			else
				fora(j, A[i])
					if ( A[i][j] != first[i] && A[i][j] != second[i] )
						result.push_back( A[i][j] );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vs> A2;
	{ /*Test 0*/string _first[] = 
	{"DIAMOND","BLUE","SOLID","ONE"}
	; vs first(_first, _first + (sizeof(_first) / sizeof(_first[0]))); A0.push_back( first ); string _second[] = 
	{"DIAMOND","GREEN","SOLID","TWO"}
	; vs second(_second, _second + (sizeof(_second) / sizeof(_second[0]))); A1.push_back( second ); string _result[] = 
	{ "DIAMOND",  "RED",  "SOLID",  "THREE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _first[] = 
	{"CIRCLE","GREEN","EMPTY","TWO"}
	; vs first(_first, _first + (sizeof(_first) / sizeof(_first[0]))); A0.push_back( first ); string _second[] = 
	{"DIAMOND","BLUE","STRIPED","ONE"}
	; vs second(_second, _second + (sizeof(_second) / sizeof(_second[0]))); A1.push_back( second ); string _result[] = 
	{ "SQUIGGLE",  "RED",  "SOLID",  "THREE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _first[] = 
	{"DIAMOND","RED","SOLID","ONE"}
	; vs first(_first, _first + (sizeof(_first) / sizeof(_first[0]))); A0.push_back( first ); string _second[] = 
	{"SQUIGGLE","BLUE","SOLID","TWO"}
	; vs second(_second, _second + (sizeof(_second) / sizeof(_second[0]))); A1.push_back( second ); string _result[] = 
	{ "CIRCLE",  "GREEN",  "SOLID",  "THREE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _first[] = 
	{"SQUIGGLE","RED","STRIPED","ONE"}
	; vs first(_first, _first + (sizeof(_first) / sizeof(_first[0]))); A0.push_back( first ); string _second[] = 
	{"SQUIGGLE","RED","STRIPED","ONE"}
	; vs second(_second, _second + (sizeof(_second) / sizeof(_second[0]))); A1.push_back( second ); string _result[] = 
	{ "SQUIGGLE",  "RED",  "STRIPED",  "ONE" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], findMatch( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Matching ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
