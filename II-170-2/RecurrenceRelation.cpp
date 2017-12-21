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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct RecurrenceRelation
{
	int moduloTen( vi coefficients, vi initial, int N )
	{
		int n = initial.size();
		if ( n > N ) return (initial[N] % 10 + 10) % 10;
		for( int i = n; i <= N; ++i )
		{
			initial.push_back( 0 );
			fora( j, coefficients )
				initial[i] = (initial[i] + coefficients[j] * initial[i - n + j] % 10 + 10) % 10;
		}
		return (initial[N] % 10 + 10) % 10;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int _coefficients[] = 
	{2,1}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{9,7}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	6
	; A2.push_back( N ); int result = 
	5
	; A3.push_back( result );  }
	{ /*Test 1*/int _coefficients[] = 
	{1,1}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{0,1}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	9
	; A2.push_back( N ); int result = 
	4
	; A3.push_back( result );  }
	{ /*Test 2*/int _coefficients[] = 
	{2}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{1}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	20
	; A2.push_back( N ); int result = 
	6
	; A3.push_back( result );  }
	{ /*Test 3*/int _coefficients[] = 
	{2}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{1}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	64
	; A2.push_back( N ); int result = 
	6
	; A3.push_back( result );  }
	{ /*Test 4*/int _coefficients[] = 
	{25,143}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{0,0}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	100000
	; A2.push_back( N ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 5*/int _coefficients[] = 
	{9,8,7,6,5,4,3,2,1,0}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{1,2,3,4,5,6,7,8,9,10}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	654
	; A2.push_back( N ); int result = 
	5
	; A3.push_back( result );  }
	{ /*Test 6*/int _coefficients[] = 
	{901,492,100}
	; vi coefficients(_coefficients, _coefficients + (sizeof(_coefficients) / sizeof(_coefficients[0]))); A0.push_back( coefficients ); int _initial[] = 
	{-6,-15,-39}
	; vi initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A1.push_back( initial ); int N = 
	0
	; A2.push_back( N ); int result = 
	4
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], moduloTen( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RecurrenceRelation ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
