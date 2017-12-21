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
typedef vector<double> vd;
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct ComputationalComplexity
{
	int fastestAlgo( vi constant, vi power, vi logPower, int N )
	{
		vd A;
        fora(i, power)
            A.push_back( 1.0 * constant[i] * pow(1.0 * N, power[i]) * pow(log(1.0 * N), logPower[i]) );
		return distance( A.begin(), min_element( all(A) ) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<int> A3; vector<int> A4;
	{ /*Test 0*/int _constant[] = 
	{5, 50, 45}
	; vi constant(_constant, _constant + (sizeof(_constant) / sizeof(_constant[0]))); A0.push_back( constant ); int _power[] = 
	{2, 1, 1}
	; vi power(_power, _power + (sizeof(_power) / sizeof(_power[0]))); A1.push_back( power ); int _logPower[] = 
	{0, 1, 1}
	; vi logPower(_logPower, _logPower + (sizeof(_logPower) / sizeof(_logPower[0]))); A2.push_back( logPower ); int N = 
	400
	; A3.push_back( N ); int result = 
	2
	; A4.push_back( result );  }
	{ /*Test 1*/int _constant[] = 
	{5, 50, 45}
	; vi constant(_constant, _constant + (sizeof(_constant) / sizeof(_constant[0]))); A0.push_back( constant ); int _power[] = 
	{2, 1, 1}
	; vi power(_power, _power + (sizeof(_power) / sizeof(_power[0]))); A1.push_back( power ); int _logPower[] = 
	{0, 1, 1}
	; vi logPower(_logPower, _logPower + (sizeof(_logPower) / sizeof(_logPower[0]))); A2.push_back( logPower ); int N = 
	10
	; A3.push_back( N ); int result = 
	0
	; A4.push_back( result );  }
	{ /*Test 2*/int _constant[] = 
	{100}
	; vi constant(_constant, _constant + (sizeof(_constant) / sizeof(_constant[0]))); A0.push_back( constant ); int _power[] = 
	{5}
	; vi power(_power, _power + (sizeof(_power) / sizeof(_power[0]))); A1.push_back( power ); int _logPower[] = 
	{5}
	; vi logPower(_logPower, _logPower + (sizeof(_logPower) / sizeof(_logPower[0]))); A2.push_back( logPower ); int N = 
	1000
	; A3.push_back( N ); int result = 
	0
	; A4.push_back( result );  }
	{ /*Test 3*/int _constant[] = 
	{32, 33, 58, 93, 8, 27, 43, 69, 95, 77,
 57, 73, 87, 87, 50, 92, 67, 20, 2, 46,
 73, 48, 25, 90, 48, 18, 28, 26, 20, 33,
 59, 48, 69, 4, 19, 13, 10, 78, 55, 90}
	; vi constant(_constant, _constant + (sizeof(_constant) / sizeof(_constant[0]))); A0.push_back( constant ); int _power[] = 
	{5, 0, 1, 4, 0, 3, 5, 4, 3, 3,
 0, 5, 0, 5, 5, 3, 0, 4, 1, 1,
 4, 0, 2, 4, 0, 0, 3, 2, 0, 0,
 4, 3, 5, 0, 2, 4, 3, 4, 3, 0}
	; vi power(_power, _power + (sizeof(_power) / sizeof(_power[0]))); A1.push_back( power ); int _logPower[] = 
	{2, 2, 2, 0, 4, 5, 2, 3, 4, 5,
 0, 0, 1, 4, 2, 5, 2, 4, 5, 0,
 5, 4, 3, 0, 4, 1, 1, 3, 3, 0,
 1, 5, 2, 1, 1, 4, 0, 0, 2, 3}
	; vi logPower(_logPower, _logPower + (sizeof(_logPower) / sizeof(_logPower[0]))); A2.push_back( logPower ); int N = 
	1000
	; A3.push_back( N ); int result = 
	33
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], fastestAlgo( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ComputationalComplexity ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
