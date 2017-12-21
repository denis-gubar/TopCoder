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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct ProgramSchedule
{
	int schedule( vi A, vi B )
	{
		int setup = 0, result = 0;
		vpii M;
		fora(i, A)
			M.push_back( make_pair( -B[i], A[i] ) );
		sort( all(M) );
		fora(i, M)
		{
			setup += M[i].second;
			result = max( result, setup - M[i].first );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int _A[] = 
	{1,2,3,4}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{2,2,4,2}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int result = 
	12
	; A2.push_back( result );  }
	{ /*Test 1*/int _A[] = 
	{3,1,2}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{4,3,9}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int result = 
	11
	; A2.push_back( result );  }
	{ /*Test 2*/int _A[] = 
	{1000}
	; vi A(_A, _A + (sizeof(_A) / sizeof(_A[0]))); A0.push_back( A ); int _B[] = 
	{1000}
	; vi B(_B, _B + (sizeof(_B) / sizeof(_B[0]))); A1.push_back( B ); int result = 
	2000
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], schedule( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ProgramSchedule ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
