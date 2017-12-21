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
struct Stairs
{
	int designs( int maxHeight, int minWidth, int totalHeight, int totalWidth )
	{
		int result = 0;
		for( int height = 1; height <= maxHeight; ++height )
			if ( totalHeight % height == 0 )
			{
				int k = totalHeight / height;
				for( int width = minWidth; width <= 1000; ++width )
					if ( totalWidth % width == 0 && totalWidth / width == k - 1 )
						++result;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3; vector<int> A4;
	{ /*Test 0*/int maxHeight = 
	22
	; A0.push_back( maxHeight ); int minWidth = 
	25
	; A1.push_back( minWidth ); int totalHeight = 
	100
	; A2.push_back( totalHeight ); int totalWidth = 
	100
	; A3.push_back( totalWidth ); int result = 
	1
	; A4.push_back( result );  }
	{ /*Test 1*/int maxHeight = 
	25
	; A0.push_back( maxHeight ); int minWidth = 
	25
	; A1.push_back( minWidth ); int totalHeight = 
	60
	; A2.push_back( totalHeight ); int totalWidth = 
	100
	; A3.push_back( totalWidth ); int result = 
	2
	; A4.push_back( result );  }
	{ /*Test 2*/int maxHeight = 
	1000
	; A0.push_back( maxHeight ); int minWidth = 
	1
	; A1.push_back( minWidth ); int totalHeight = 
	600
	; A2.push_back( totalHeight ); int totalWidth = 
	600
	; A3.push_back( totalWidth ); int result = 
	6
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], designs( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Stairs ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
