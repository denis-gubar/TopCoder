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
#define all(v) (v).begin(), (v).end()
struct RoyalTreasurer
{
	int minimalArrangement( vi A, vi B )
	{
        sort( all(A) );
        sort( all(B) );
        return inner_product( all(A), B.rbegin(), 0 );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int _A[] = 
	{1,1,3}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{10,30,20}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int result = 
	80
	; A2.push_back( result );  }
	{ /*Test 1*/int _A[] = 
	{1,1,1,6,0}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{2,7,8,3,1}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int result = 
	18
	; A2.push_back( result );  }
	{ /*Test 2*/int _A[] = 
	{5,15,100,31,39,0,0,3,26}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{11,12,13,2,3,4,5,9,1}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int result = 
	528
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], minimalArrangement( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RoyalTreasurer ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
