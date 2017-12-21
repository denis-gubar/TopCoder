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
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vl;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct PayBill
{
	vi whoPaid( vi meals, int totalMoney )
	{
		vi result;
		vl A( totalMoney + 1 );
		for( int i = 1; i <= totalMoney; ++i )
			fora(j, meals)
				if ( !A[i] && (i > meals[j] && A[i - meals[j]] > 0 && (A[i - meals[j]] & (1LL << j)) == 0 || i == meals[j]) )
					A[i] = A[i - meals[j]] | (1LL << j);
		fora(j, meals)
			if ( A[totalMoney] & (1LL << j) )
				result.push_back( j );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<vi> A2;
	{ /*Test 0*/int _meals[] = 
	{ 1000, 1200, 1300 }
	; vi meals(_meals, _meals + (sizeof(_meals) / sizeof(_meals[0]))); A0.push_back( meals ); int totalMoney = 
	2500
	; A1.push_back( totalMoney ); int _result[] = 
	{ 1,  2 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/int _meals[] = 
	{ 100, 200, 350 }
	; vi meals(_meals, _meals + (sizeof(_meals) / sizeof(_meals[0]))); A0.push_back( meals ); int totalMoney = 
	300
	; A1.push_back( totalMoney ); int _result[] = 
	{ 0,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/int _meals[] = 
	{ 150, 200, 350, 400 }
	; vi meals(_meals, _meals + (sizeof(_meals) / sizeof(_meals[0]))); A0.push_back( meals ); int totalMoney = 
	900
	; A1.push_back( totalMoney ); int _result[] = 
	{ 0,  2,  3 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/int _meals[] = 
	{6584,6733,6018,5840,2723,4902,4260,
 5375,6745,1234,3000,8222,2472,
 4348,1716,9995,415,1234,2345,5679}
	; vi meals(_meals, _meals + (sizeof(_meals) / sizeof(_meals[0]))); A0.push_back( meals ); int totalMoney = 
	70630
	; A1.push_back( totalMoney ); int _result[] = 
	{ 0,  1,  3,  4,  5,  6,  8,  9,  11,  13,  14,  15,  16,  17,  19 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], whoPaid( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PayBill ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
