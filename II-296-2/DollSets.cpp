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
struct DollSets
{
	int maximumQuantity( vi dollSizes, int K )
	{
		int result = 0;
        sort( all(dollSizes) );
        fora(i, dollSizes)
            if ( dollSizes[i] > 0 )
            {
                vi::iterator it = find( dollSizes.begin() + i + 1, dollSizes.end(), dollSizes[i] * K );
                if ( it != dollSizes.end() )
                {
                    ++result;
                    dollSizes[i] = *it = -1;
                }
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/int _dollSizes[] = 
	{1,2,1,2,4}
	; vi dollSizes(_dollSizes, _dollSizes + (sizeof(_dollSizes) / sizeof(_dollSizes[0]))); A0.push_back( dollSizes ); int K = 
	2
	; A1.push_back( K ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/int _dollSizes[] = 
	{5,4,3,2,1}
	; vi dollSizes(_dollSizes, _dollSizes + (sizeof(_dollSizes) / sizeof(_dollSizes[0]))); A0.push_back( dollSizes ); int K = 
	2
	; A1.push_back( K ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 2*/int _dollSizes[] = 
	{5,4,1,2,3,4,5,67,8,9,8,7,15,12}
	; vi dollSizes(_dollSizes, _dollSizes + (sizeof(_dollSizes) / sizeof(_dollSizes[0]))); A0.push_back( dollSizes ); int K = 
	3
	; A1.push_back( K ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 3*/int _dollSizes[] = 
	{1}
	; vi dollSizes(_dollSizes, _dollSizes + (sizeof(_dollSizes) / sizeof(_dollSizes[0]))); A0.push_back( dollSizes ); int K = 
	25
	; A1.push_back( K ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 4*/int _dollSizes[] = 
	{1,9,81,729,1,81}
	; vi dollSizes(_dollSizes, _dollSizes + (sizeof(_dollSizes) / sizeof(_dollSizes[0]))); A0.push_back( dollSizes ); int K = 
	9
	; A1.push_back( K ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 5*/int _dollSizes[] = 
	{1,2,2}
	; vi dollSizes(_dollSizes, _dollSizes + (sizeof(_dollSizes) / sizeof(_dollSizes[0]))); A0.push_back( dollSizes ); int K = 
	1
	; A1.push_back( K ); int result = 
	1
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], maximumQuantity( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	DollSets ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
