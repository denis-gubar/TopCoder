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
struct PackingParts
{
	int pack( vi partSizes, vi boxSizes )
	{
		int result = 0;
        fora(i, partSizes)
        {
            vi::iterator it = lower_bound( all(boxSizes), partSizes[i] );
            if ( it == boxSizes.end() )
                break;
            ++result;
            boxSizes.erase( it );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int _partSizes[] = 
	{2,2,2}
	; vi partSizes(_partSizes, _partSizes + (sizeof(_partSizes) / sizeof(_partSizes[0]))); A0.push_back( partSizes ); int _boxSizes[] = 
	{1,2,2,3}
	; vi boxSizes(_boxSizes, _boxSizes + (sizeof(_boxSizes) / sizeof(_boxSizes[0]))); A1.push_back( boxSizes ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 1*/int _partSizes[] = 
	{1,5}
	; vi partSizes(_partSizes, _partSizes + (sizeof(_partSizes) / sizeof(_partSizes[0]))); A0.push_back( partSizes ); int _boxSizes[] = 
	{2,5}
	; vi boxSizes(_boxSizes, _boxSizes + (sizeof(_boxSizes) / sizeof(_boxSizes[0]))); A1.push_back( boxSizes ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 2*/int _partSizes[] = 
	{10,10,10,10}
	; vi partSizes(_partSizes, _partSizes + (sizeof(_partSizes) / sizeof(_partSizes[0]))); A0.push_back( partSizes ); int _boxSizes[] = 
	{9,9,9,10,10,10}
	; vi boxSizes(_boxSizes, _boxSizes + (sizeof(_boxSizes) / sizeof(_boxSizes[0]))); A1.push_back( boxSizes ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 3*/int _partSizes[] = 
	{1,1,1,1}
	; vi partSizes(_partSizes, _partSizes + (sizeof(_partSizes) / sizeof(_partSizes[0]))); A0.push_back( partSizes ); int _boxSizes[] = 
	{1,2,2,3,6,7}
	; vi boxSizes(_boxSizes, _boxSizes + (sizeof(_boxSizes) / sizeof(_boxSizes[0]))); A1.push_back( boxSizes ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 4*/int _partSizes[] = 
	{1,1,1,1}
	; vi partSizes(_partSizes, _partSizes + (sizeof(_partSizes) / sizeof(_partSizes[0]))); A0.push_back( partSizes ); int _boxSizes[] = 
	{2,3,6}
	; vi boxSizes(_boxSizes, _boxSizes + (sizeof(_boxSizes) / sizeof(_boxSizes[0]))); A1.push_back( boxSizes ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 5*/int _partSizes[] = 
	{10,32,46,55,55,84,100}
	; vi partSizes(_partSizes, _partSizes + (sizeof(_partSizes) / sizeof(_partSizes[0]))); A0.push_back( partSizes ); int _boxSizes[] = 
	{15,31,34,46,59,68,83,99}
	; vi boxSizes(_boxSizes, _boxSizes + (sizeof(_boxSizes) / sizeof(_boxSizes[0]))); A1.push_back( boxSizes ); int result = 
	6
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], pack( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PackingParts ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
