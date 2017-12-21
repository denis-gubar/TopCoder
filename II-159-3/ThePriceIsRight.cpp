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
#define all(v) (v).begin(), (v).end()
struct ThePriceIsRight
{
	vi howManyReveals( vi prices )
	{
		vi result; int n = prices.size();
		vi A(n, 1), B(n, 1);
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < i; ++j )
				if ( prices[i] > prices[j] )
					if ( A[i] <= A[j] )
					{
						A[i] = A[j] + 1; B[i] = B[j];
					} else if ( A[i] == A[j] + 1 )
						B[i] += B[j];
		int k = *max_element( all(A) );
		result.push_back( k ); result.push_back( 0 );
		fora(i, A)
			if ( A[i] == k )
				result.back() += B[i];
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
	{ /*Test 0*/int _prices[] = 
	{30,10,20,40,50}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 4,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/int _prices[] = 
	{39,88,67,5,69,87,82,64,58,61}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 4,  2 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/int _prices[] = 
	{1,2,3,4,5,6,7,8,9,10}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 10,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/int _prices[] = 
	{10,9,8,7,6,5,4,3,2,1}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 1,  10 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/int _prices[] = 
	{29,31,73,70,14,5,6,34,53,30,15,86}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 5,  2 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 5*/int _prices[] = 
	{100,99,1,2,3}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 3,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 6*/int _prices[] = 
	{10,20,11,12}
	; vi prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); int _result[] = 
	{ 3,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], howManyReveals( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ThePriceIsRight ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
