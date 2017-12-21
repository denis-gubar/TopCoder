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
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef long long lint;
typedef vector<string> vs;
#define all(v) (v).begin(), (v).end()
struct Fairness
{
	struct comp: binary_function<string, string, bool>
	{
		bool operator() ( string a, string b ) const
		{
			int x = accumulate( all(a), 0 ), y = accumulate( all(b), 0 );
			return x * b.size() < y * a.size();
		}
	};
	vs fairSort( vs names )
	{
		stable_sort( all(names), comp() );
		return names;
	}
// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _Arg0[] = 
	{"BOB","AAAAAAA","TOM"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "AAAAAAA",  "BOB",  "TOM" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"ABE","ABLE","ABE"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "ABE",  "ABE",  "ABLE" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"PANE","TOM","BONE","AAAA"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "AAAA",  "PANE",  "BONE",  "TOM" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"BONE","TOM","PANE","AAAA"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "AAAA",  "BONE",  "PANE",  "TOM" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], fairSort( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Fairness ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
