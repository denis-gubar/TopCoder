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
typedef vector<int> vi;
struct Pool
{
	vi t;
	int x( int i )
	{
		if ( t[i] == 8 ) return 2;
		return t[i] < 8;
	}
	int o( int i )
	{
		if ( t[i] == 8 ) return 2;
		return t[i] > 8;
	}
	int eight( int i )
	{
		return t[i] != 8;
	}
	int rackMoves( vi triangle )
	{
		t = vi(triangle);
		int a = x(0) + o(1) + o(2) + x(3) + eight(4) + x(5) + o(6) + x(7) + o(8) + x(9) + x(10) + o(11) + x(12) + o(13) + o(14);
		int b = o(0) + x(1) + x(2) + o(3) + eight(4) + o(5) + x(6) + o(7) + x(8) + o(9) + o(10) + x(11) + o(12) + x(13) + x(14);
		return min( a, b ) / 2;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1;
	{ /*Test 0*/int _triangle[] = 
	{6, 12, 14, 1, 8, 2, 11, 3, 9, 4, 7, 13, 5, 15, 10}
	; vi triangle(_triangle, _triangle + (sizeof(_triangle) / sizeof(_triangle[0]))); A0.push_back( triangle ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 1*/int _triangle[] = 
	{2, 10, 7, 1, 8, 12, 6, 11, 4, 9, 13, 3, 14, 15, 5}
	; vi triangle(_triangle, _triangle + (sizeof(_triangle) / sizeof(_triangle[0]))); A0.push_back( triangle ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 2*/int _triangle[] = 
	{8, 15, 9, 4, 10, 6, 11, 3, 14, 7, 2, 1, 13, 12, 5}
	; vi triangle(_triangle, _triangle + (sizeof(_triangle) / sizeof(_triangle[0]))); A0.push_back( triangle ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 3*/int _triangle[] = 
	{15, 5, 8, 13, 2, 14, 10, 3, 4, 6, 7, 9, 1, 12, 11}
	; vi triangle(_triangle, _triangle + (sizeof(_triangle) / sizeof(_triangle[0]))); A0.push_back( triangle ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 4*/int _triangle[] = 
	{1, 5, 15, 6, 10, 9, 11, 13, 7, 4, 3, 8, 2, 12, 14}
	; vi triangle(_triangle, _triangle + (sizeof(_triangle) / sizeof(_triangle[0]))); A0.push_back( triangle ); int result = 
	3
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], rackMoves( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Pool ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
