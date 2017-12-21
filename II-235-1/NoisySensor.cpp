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
struct NoisySensor
{
	vi medianFilter( vi data )
	{
		vi result( data );
		for( int i = 1; i < result.size() - 1; ++i )
		{
			vi a( data.begin() + i - 1, data.begin() + i + 2 );
			sort( all(a) );
			result[i] = a[1];
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1;
	{ /*Test 0*/int _data[] = 
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	; vi data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/int _data[] = 
	{10, 1, 9, 2, 8}
	; vi data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{10, 9, 2, 8, 8 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/int _data[] = 
	{500, 500, 500, 500, 500}
	; vi data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{500, 500, 500, 500, 500 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/int _data[] = 
	{-2147483648, 2147483647}
	; vi data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{-2147483648, 2147483647 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/int _data[] = 
	{432296535, 1983848899, -434724194, 135703525, -1146336142,
-680568092, -1183352724, 1337550909, -1597342716, -1901441857,
1726722019, -558651015, 649930787, 1889036519, 1752815826,
930647381, -852547667, 2028345278, -1835531493, -1040566300,
-1566043783, -1282411107, -1123988603, 2132078516, -1169614369,
-523503536, 1466102514, -2003903121, -779001645, 1919742042,
1210980485, -9273881, 1033032137, -1474003783, 296280591,
920184999, -1235054743, -1329769514, -1727085135}
	; vi data(_data, _data + (sizeof(_data) / sizeof(_data[0]))); A0.push_back( data ); int _result[] = 
	{432296535, 432296535, 135703525, -434724194, -680568092, -1146336142, -680568092, -1183352724, -1597342716, -1597342716, -558651015, 649930787, 649930787, 1752815826, 1752815826, 930647381, 930647381, -852547667, -1040566300, -1566043783, -1282411107, -1282411107, -1123988603, -1123988603, -523503536, -523503536, -523503536, -779001645, -779001645, 1210980485, 1210980485, 1033032137, -9273881, 296280591, 296280591, 296280591, -1235054743, -1329769514, -1727085135 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], medianFilter( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NoisySensor ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
