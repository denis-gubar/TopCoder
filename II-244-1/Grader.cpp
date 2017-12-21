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
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
struct Grader
{
	vi grade( vi predictedGrades, vi actualGrades )
	{
		vi result( 7 );
        fora(i, predictedGrades)
            ++result[abs( predictedGrades[i] - actualGrades[i] )];
        fora(i, result)
            result[i] = result[i] * 100 / predictedGrades.size();
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2;
	{ /*Test 0*/int _predictedGrades[] = 
	{1,5,7,3}
	; vi predictedGrades(_predictedGrades, _predictedGrades + (sizeof(_predictedGrades) / sizeof(_predictedGrades[0]))); A0.push_back( predictedGrades ); int _actualGrades[] = 
	{3,5,4,5}
	; vi actualGrades(_actualGrades, _actualGrades + (sizeof(_actualGrades) / sizeof(_actualGrades[0]))); A1.push_back( actualGrades ); int _result[] = 
	{25, 0, 50, 25, 0, 0, 0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/int _predictedGrades[] = 
	{1,1,1}
	; vi predictedGrades(_predictedGrades, _predictedGrades + (sizeof(_predictedGrades) / sizeof(_predictedGrades[0]))); A0.push_back( predictedGrades ); int _actualGrades[] = 
	{5,6,7}
	; vi actualGrades(_actualGrades, _actualGrades + (sizeof(_actualGrades) / sizeof(_actualGrades[0]))); A1.push_back( actualGrades ); int _result[] = 
	{0, 0, 0, 0, 33, 33, 33 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/int _predictedGrades[] = 
	{3}
	; vi predictedGrades(_predictedGrades, _predictedGrades + (sizeof(_predictedGrades) / sizeof(_predictedGrades[0]))); A0.push_back( predictedGrades ); int _actualGrades[] = 
	{3}
	; vi actualGrades(_actualGrades, _actualGrades + (sizeof(_actualGrades) / sizeof(_actualGrades[0]))); A1.push_back( actualGrades ); int _result[] = 
	{100, 0, 0, 0, 0, 0, 0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/int _predictedGrades[] = 
	{1,5,3,5,6,4,2,5,7,6,5,2,3,4,1,4,6,5,4,7,6,6,1}
	; vi predictedGrades(_predictedGrades, _predictedGrades + (sizeof(_predictedGrades) / sizeof(_predictedGrades[0]))); A0.push_back( predictedGrades ); int _actualGrades[] = 
	{5,1,3,2,6,4,1,7,5,2,7,4,2,6,5,7,3,1,4,6,3,1,7}
	; vi actualGrades(_actualGrades, _actualGrades + (sizeof(_actualGrades) / sizeof(_actualGrades[0]))); A1.push_back( actualGrades ); int _result[] = 
	{17, 13, 21, 17, 21, 4, 4 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], grade( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Grader ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
