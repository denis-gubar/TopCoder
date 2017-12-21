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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct Barbecue
{
	struct comp: binary_function<int, int, bool>
	{
		vi A, B;
		comp( vi A, vi B ): A(A), B(B) {}
		bool operator() ( int a, int b ) const
		{
			if ( B[a] != B[b] )
				return B[a] > B[b];
			if ( A[a] != A[b] )
				return A[a] > A[b];
			return a < b;
		}
	};
	int eliminate( int n, vi voter, vi excluded )
	{
		vi A(n), B(n), C(n);
		fora(i, C)
			C[i] = i;
		fora(i, voter)
			++A[voter[i]], ++B[excluded[i]];
		return *min_element( all(C), comp(A, B) );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<vi> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int n = 
	3
	; A0.push_back( n ); int _voter[] = 
	{0,1,2,2}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{2,2,0,1}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 1*/int n = 
	3
	; A0.push_back( n ); int _voter[] = 
	{0,2,2}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{2,0,1}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 2*/int n = 
	2
	; A0.push_back( n ); int _voter[] = 
	{0,1}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{1,0}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 3*/int n = 
	20
	; A0.push_back( n ); int _voter[] = 
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,
6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,2,3}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 4*/int n = 
	5
	; A0.push_back( n ); int _voter[] = 
	{4,3,1,0}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{2,2,3,3}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	3
	; A3.push_back( result );  }
	{ /*Test 5*/int n = 
	10
	; A0.push_back( n ); int _voter[] = 
	{4,5,6,7,8,9,0,1,2}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{5,6,7,8,9,0,1,2,3}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 6*/int n = 
	7
	; A0.push_back( n ); int _voter[] = 
	{1,2,3,4,5,6,0,2,3,4,5,6,0,1,3,4,5,6,0,1,2,
 4,5,6,0,1,2,3,5,6,0,1,2,3,4,6,0,1,2,3,4,5}
	; vi voter(_voter, _voter + (sizeof(_voter) / sizeof(_voter[0]))); A1.push_back( voter ); int _excluded[] = 
	{0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,
 3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6}
	; vi excluded(_excluded, _excluded + (sizeof(_excluded) / sizeof(_excluded[0]))); A2.push_back( excluded ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 7*/int n = 
	5
	; A0.push_back( n ); vi voter; A1.push_back( voter ); vi excluded; A2.push_back( excluded ); int result = 
	0
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], eliminate( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Barbecue ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
