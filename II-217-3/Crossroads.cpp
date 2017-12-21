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
struct Crossroads
{
	vi getOut( vi angles )
	{
		vi result;
		vi f( angles.size() );
		bool flag = true;
		while( flag )
		{
			flag = false;
			fora(i, f)
				for( int j = i + 1; j < f.size(); ++j )
					if ( angles[i] < angles[j] )
					{
						if ( abs( angles[i] - 90 ) <= abs( angles[j] - 90 ) )
						{
							flag = !f[j];
							f[j] = 1;
						}
						else
						{
							flag = !f[i];
							f[i] = 1;
						}
					}
		}
		fora(i, f)
			if ( !f[i] )
				result.push_back( i );
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
	{ /*Test 0*/int _angles[] = 
	{105, 75, 25, 120, 35, 75}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0,  1,  5 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/int _angles[] = 
	{1, 1, 1, 1, 1, 1}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0,  1,  2,  3,  4,  5 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/int _angles[] = 
	{13}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/int _angles[] = 
	{90, 123, 1, 23, 132, 11, 28, 179, 179, 77, 113, 91}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/int _angles[] = 
	{179, 89, 90, 91, 1}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0,  2,  4 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 5*/int _angles[] = 
	{89, 91}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 6*/int _angles[] = 
	{140, 118, 54, 166, 151, 44, 90, 5, 14, 6,
 64, 129, 74, 33, 134, 25, 11, 95, 65, 145,
 29, 162, 24, 147, 45, 103, 63, 97, 120, 156,
 167, 170, 19, 28, 100, 144, 161, 13, 157, 148}
	; vi angles(_angles, _angles + (sizeof(_angles) / sizeof(_angles[0]))); A0.push_back( angles ); int _result[] = 
	{ 0,  1,  6 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], getOut( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Crossroads ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
