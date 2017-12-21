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
#define all(v) (v).begin(), (v).end()
struct BinaryCardinality
{
	struct comp: binary_function<int, int, bool>
	{
		bool operator() ( int a, int b ) const
		{
			if ( calc(a) != calc(b) ) return calc(a) < calc(b);
			return a < b;
		}
		int calc( int x ) const
		{
			int result = 0;
			while( x )
			{
				x = x & (x - 1); ++result;
			}
			return result;
		}
	};
	vi arrange( vi numbers )
	{
		sort( all(numbers), comp() );
		return numbers;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1;
	{ /*Test 0*/int _numbers[] = 
	{4}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int _result[] = 
	{ 4 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/int _numbers[] = 
	{31,15,7,3,2}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int _result[] = 
	{ 2,  3,  7,  15,  31 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/int _numbers[] = 
	{10,9,8,7,6,5,4,3,2,1}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int _result[] = 
	{ 1,  2,  4,  8,  3,  5,  6,  9,  10,  7 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/int _numbers[] = 
	{811385,340578,980086,545001,774872,855585,13848,863414,419523,190151,784903,127461}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int _result[] = 
	{ 13848,  340578,  545001,  855585,  419523,  811385,  127461,  190151,  774872,  863414,  784903,  980086 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], arrange( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BinaryCardinality ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
