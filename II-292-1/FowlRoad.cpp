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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
struct FowlRoad
{
	int crossings( int roadY, vi, vi bobY )
	{
		int result = 0, x = roadY < bobY[0];
		fora(i, bobY)
			if ( bobY[i] != roadY && x == (roadY > bobY[i]) )
				++result, x = !x;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<vi> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int roadY = 
	6
	; A0.push_back( roadY ); int _bobX[] = 
	{3,7,9,2}
	; vi bobX(_bobX, _bobX + (sizeof(_bobX) / sizeof(_bobX[0]))); A1.push_back( bobX ); int _bobY[] = 
	{-3,8,8,2}
	; vi bobY(_bobY, _bobY + (sizeof(_bobY) / sizeof(_bobY[0]))); A2.push_back( bobY ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 1*/int roadY = 
	10
	; A0.push_back( roadY ); int _bobX[] = 
	{3,7,9,2}
	; vi bobX(_bobX, _bobX + (sizeof(_bobX) / sizeof(_bobX[0]))); A1.push_back( bobX ); int _bobY[] = 
	{-3,8,8,2}
	; vi bobY(_bobY, _bobY + (sizeof(_bobY) / sizeof(_bobY[0]))); A2.push_back( bobY ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 2*/int roadY = 
	0
	; A0.push_back( roadY ); int _bobX[] = 
	{3,2,5,6,9}
	; vi bobX(_bobX, _bobX + (sizeof(_bobX) / sizeof(_bobX[0]))); A1.push_back( bobX ); int _bobY[] = 
	{2,0,0,2,-88}
	; vi bobY(_bobY, _bobY + (sizeof(_bobY) / sizeof(_bobY[0]))); A2.push_back( bobY ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 3*/int roadY = 
	0
	; A0.push_back( roadY ); int _bobX[] = 
	{3,2,5,6,9}
	; vi bobX(_bobX, _bobX + (sizeof(_bobX) / sizeof(_bobX[0]))); A1.push_back( bobX ); int _bobY[] = 
	{-2,0,0,2,-88}
	; vi bobY(_bobY, _bobY + (sizeof(_bobY) / sizeof(_bobY[0]))); A2.push_back( bobY ); int result = 
	2
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], crossings( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FowlRoad ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
