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
struct MergeSort
{
	int result;
	vi merge( vi b, vi c )
	{
		vi a;
		int i = 0, j = 0;
		while( i < b.size() && j < c.size() )
		{
			++result;
			if ( b[i] < c[j] )
				a.push_back( b[i++] );
			else if ( b[i] > c[j] )
				a.push_back( c[j++] );
			else
			{
				a.push_back( b[i++] );
				a.push_back( c[j++] );
			}
		}
		while( i < b.size() )
			a.push_back( b[i++] );
		while( j < c.size() )
			a.push_back( c[j++] );
		return a;
	}
	vi mergeSort( vi a )
	{
		if ( a.size() <= 1 ) return a;
		vi b(a.begin(), a.begin() + a.size() / 2), c(a.begin() + a.size() / 2, a.end());
		vi B = mergeSort( b ), C = mergeSort( c );
		return merge( B, C );
	}
	int howManyComparisons( vi numbers )
	{
		result = 0;
		mergeSort( numbers );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1;
	{ /*Test 0*/int _numbers[] = 
	{1, 2, 3, 4}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 1*/int _numbers[] = 
	{2, 3, 2}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 2*/int _numbers[] = 
	{-17}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 3*/vi numbers; A0.push_back( numbers ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 4*/int _numbers[] = 
	{-2000000000,2000000000,0,0,0,-2000000000,2000000000,0,0,0}
	; vi numbers(_numbers, _numbers + (sizeof(_numbers) / sizeof(_numbers[0]))); A0.push_back( numbers ); int result = 
	19
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], howManyComparisons( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MergeSort ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
