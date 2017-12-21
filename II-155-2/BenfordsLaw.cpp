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
struct BenfordsLaw
{
	int questionableDigit( vi transactions, int threshold )
	{
		vi freq(10, 0);
		fora(i, transactions)
		{
			int x;
			for( x = transactions[i]; x > 9; x /= 10 );
			++freq[x];
		}
		for( int result = 1; result <= 9; ++result )
			if ( static_cast<double>(freq[result]) / transactions.size() < log10( 1 + 1.0 / result ) / threshold ||
				 static_cast<double>(freq[result]) / transactions.size() > log10( 1 + 1.0 / result ) * threshold )
				return result;
		return -1;
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
	{ /*Test 0*/int _transactions[] = 
	{ 5236,7290,200,1907,3336,9182,17,4209,8746,7932,
  6375,909,2189,3977,2389,2500,1239,3448,6380,4812 }
	; vi transactions(_transactions, _transactions + (sizeof(_transactions) / sizeof(_transactions[0]))); A0.push_back( transactions ); int threshold = 
	2
	; A1.push_back( threshold ); int result = 
	1
	; A2.push_back( result );  }
	{ /*Test 1*/int _transactions[] = 
	{ 1,10,100,2,20,200,2000,3,30,300 }
	; vi transactions(_transactions, _transactions + (sizeof(_transactions) / sizeof(_transactions[0]))); A0.push_back( transactions ); int threshold = 
	2
	; A1.push_back( threshold ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 2*/int _transactions[] = 
	{ 9,87,765,6543,54321,43219,321987,21987,1987,345,234,123 }
	; vi transactions(_transactions, _transactions + (sizeof(_transactions) / sizeof(_transactions[0]))); A0.push_back( transactions ); int threshold = 
	2
	; A1.push_back( threshold ); int result = 
	-1
	; A2.push_back( result );  }
	{ /*Test 3*/int _transactions[] = 
	{ 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 }
	; vi transactions(_transactions, _transactions + (sizeof(_transactions) / sizeof(_transactions[0]))); A0.push_back( transactions ); int threshold = 
	8
	; A1.push_back( threshold ); int result = 
	9
	; A2.push_back( result );  }
	{ /*Test 4*/int _transactions[] = 
	{ 987,234,1234,234873487,876,234562,17,
  7575734,5555,4210,678234,3999,8123 }
	; vi transactions(_transactions, _transactions + (sizeof(_transactions) / sizeof(_transactions[0]))); A0.push_back( transactions ); int threshold = 
	3
	; A1.push_back( threshold ); int result = 
	8
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], questionableDigit( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BenfordsLaw ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
