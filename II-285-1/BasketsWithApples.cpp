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
#define all(v) (v).begin(), (v).end()
struct BasketsWithApples
{
	int removeExcess( vi apples )
	{
		vi result;
		for( int i = 1; i <= 1000; ++i )
		{
			int current = 0;
			fora(j, apples)
				if ( apples[j] >= i )
					current += i;
			result.push_back( current );
		}
		return *max_element( all(result) );
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
	{ /*Test 0*/int _apples[] = 
	{1, 2, 3}
	; vi apples(_apples, _apples + (sizeof(_apples) / sizeof(_apples[0]))); A0.push_back( apples ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 1*/int _apples[] = 
	{5, 0, 30, 14}
	; vi apples(_apples, _apples + (sizeof(_apples) / sizeof(_apples[0]))); A0.push_back( apples ); int result = 
	30
	; A1.push_back( result );  }
	{ /*Test 2*/int _apples[] = 
	{51, 8, 38, 49}
	; vi apples(_apples, _apples + (sizeof(_apples) / sizeof(_apples[0]))); A0.push_back( apples ); int result = 
	114
	; A1.push_back( result );  }
	{ /*Test 3*/int _apples[] = 
	{24, 92, 38, 0, 79, 45}
	; vi apples(_apples, _apples + (sizeof(_apples) / sizeof(_apples[0]))); A0.push_back( apples ); int result = 
	158
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], removeExcess( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BasketsWithApples ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
