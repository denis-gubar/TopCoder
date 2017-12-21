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
struct PulseRadar
{
	vi deduceSpeeds( vi x1, vi y1, vi x2, vi y2, vi x3, vi y3 )
	{
		vi result;
		int n = x1.size();
		vi A(n);
		fora(i, A)
			A[i] = i;
		do
		{
			int count = 0;
			fora(i, A)
			{
				fora(j, A)
					if ( x2[A[i]] - x1[i] == x3[j] - x2[A[i]] && 
						y2[A[i]] - y1[i] == y3[j] - y2[A[i]] )
					{
						++count; break;
					}
				if ( count < i ) break;
			}
			if ( count == n )
			{
				if ( !result.empty() ) return vi();
				fora(i, A)
					result.push_back( (sqrt(4.0 * (x1[i] - x2[A[i]]) * (x1[i] - x2[A[i]]) +
						4.0 * (y1[i] - y2[A[i]]) * (y1[i] - y2[A[i]])) + 1) / 2 );
			}
		} while ( next_permutation( all(A) ) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<vi> A3; vector<vi> A4; vector<vi> A5; vector<vi> A6;
	{ /*Test 0*/int _x1[] = 
	{-8, -7, 9, -5}
	; vi x1(_x1, _x1 + (sizeof(_x1) / sizeof(_x1[0]))); A0.push_back( x1 ); int _y1[] = 
	{2, -1, -2, -6}
	; vi y1(_y1, _y1 + (sizeof(_y1) / sizeof(_y1[0]))); A1.push_back( y1 ); int _x2[] = 
	{-2, -3, 8, 1}
	; vi x2(_x2, _x2 + (sizeof(_x2) / sizeof(_x2[0]))); A2.push_back( x2 ); int _y2[] = 
	{-3, 1, 4, -2}
	; vi y2(_y2, _y2 + (sizeof(_y2) / sizeof(_y2[0]))); A3.push_back( y2 ); int _x3[] = 
	{4, 1, 7, 7}
	; vi x3(_x3, _x3 + (sizeof(_x3) / sizeof(_x3[0]))); A4.push_back( x3 ); int _y3[] = 
	{-8, 3, 10, 2}
	; vi y3(_y3, _y3 + (sizeof(_y3) / sizeof(_y3[0]))); A5.push_back( y3 ); int _result[] = 
	{ 8,  4,  6,  7 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A6.push_back( result );  }
	{ /*Test 1*/int _x1[] = 
	{-7, -2, 2, 0}
	; vi x1(_x1, _x1 + (sizeof(_x1) / sizeof(_x1[0]))); A0.push_back( x1 ); int _y1[] = 
	{8, -2, -2, -6}
	; vi y1(_y1, _y1 + (sizeof(_y1) / sizeof(_y1[0]))); A1.push_back( y1 ); int _x2[] = 
	{-5, -1, 3, -1}
	; vi x2(_x2, _x2 + (sizeof(_x2) / sizeof(_x2[0]))); A2.push_back( x2 ); int _y2[] = 
	{9, 1, -4, -8}
	; vi y2(_y2, _y2 + (sizeof(_y2) / sizeof(_y2[0]))); A3.push_back( y2 ); int _x3[] = 
	{-3, 1, 5, -2}
	; vi x3(_x3, _x3 + (sizeof(_x3) / sizeof(_x3[0]))); A4.push_back( x3 ); int _y3[] = 
	{10, 5, -6, -10}
	; vi y3(_y3, _y3 + (sizeof(_y3) / sizeof(_y3[0]))); A5.push_back( y3 ); vi result; A6.push_back( result );  }
	{ /*Test 2*/int _x1[] = 
	{-4, -4, -4, -4}
	; vi x1(_x1, _x1 + (sizeof(_x1) / sizeof(_x1[0]))); A0.push_back( x1 ); int _y1[] = 
	{9, 3, -1, -7}
	; vi y1(_y1, _y1 + (sizeof(_y1) / sizeof(_y1[0]))); A1.push_back( y1 ); int _x2[] = 
	{-1, -1, -1, -1}
	; vi x2(_x2, _x2 + (sizeof(_x2) / sizeof(_x2[0]))); A2.push_back( x2 ); int _y2[] = 
	{6, -2, 4, -4}
	; vi y2(_y2, _y2 + (sizeof(_y2) / sizeof(_y2[0]))); A3.push_back( y2 ); int _x3[] = 
	{2, 2, 2, 2}
	; vi x3(_x3, _x3 + (sizeof(_x3) / sizeof(_x3[0]))); A4.push_back( x3 ); int _y3[] = 
	{3, -7, 9, -1}
	; vi y3(_y3, _y3 + (sizeof(_y3) / sizeof(_y3[0]))); A5.push_back( y3 ); vi result; A6.push_back( result );  }
	{ /*Test 3*/int _x1[] = 
	{5, -4, 2, -1, 8, -4, -8, 3, -3, -4}
	; vi x1(_x1, _x1 + (sizeof(_x1) / sizeof(_x1[0]))); A0.push_back( x1 ); int _y1[] = 
	{9, 9, -2, -8, 3, -8, -4, 2, -4, -2}
	; vi y1(_y1, _y1 + (sizeof(_y1) / sizeof(_y1[0]))); A1.push_back( y1 ); int _x2[] = 
	{-2, 2, 1, 2, 1, -1, -3, 1, -4, -1}
	; vi x2(_x2, _x2 + (sizeof(_x2) / sizeof(_x2[0]))); A2.push_back( x2 ); int _y2[] = 
	{-1, -5, 6, -2, 2, 2, 0, -1, -2, -5}
	; vi y2(_y2, _y2 + (sizeof(_y2) / sizeof(_y2[0]))); A3.push_back( y2 ); int _x3[] = 
	{8, 5, -1, -3, 6, -5, 2, 0, -6, -8}
	; vi x3(_x3, _x3 + (sizeof(_x3) / sizeof(_x3[0]))); A4.push_back( x3 ); int _y3[] = 
	{4, -2, 2, 3, -5, 2, -8, 0, -5, 2}
	; vi y3(_y3, _y3 + (sizeof(_y3) / sizeof(_y3[0]))); A5.push_back( y3 ); int _result[] = 
	{ 5,  9,  5,  4,  8,  8,  4,  4,  3,  4 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A6.push_back( result );  }
	{ /*Test 4*/int _x1[] = 
	{-300, 466}
	; vi x1(_x1, _x1 + (sizeof(_x1) / sizeof(_x1[0]))); A0.push_back( x1 ); int _y1[] = 
	{-600, 866}
	; vi y1(_y1, _y1 + (sizeof(_y1) / sizeof(_y1[0]))); A1.push_back( y1 ); int _x2[] = 
	{466, 100}
	; vi x2(_x2, _x2 + (sizeof(_x2) / sizeof(_x2[0]))); A2.push_back( x2 ); int _y2[] = 
	{866, -450}
	; vi y2(_y2, _y2 + (sizeof(_y2) / sizeof(_y2[0]))); A3.push_back( y2 ); int _x3[] = 
	{500, 466}
	; vi x3(_x3, _x3 + (sizeof(_x3) / sizeof(_x3[0]))); A4.push_back( x3 ); int _y3[] = 
	{-300, 866}
	; vi y3(_y3, _y3 + (sizeof(_y3) / sizeof(_y3[0]))); A5.push_back( y3 ); int _result[] = 
	{ 427,  0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A6.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A6[i], deduceSpeeds( A0[i], A1[i], A2[i], A3[i], A4[i], A5[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PulseRadar ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
