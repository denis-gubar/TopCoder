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
#ifdef __GNUC__
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template<typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
int gcd( int a, int b )
{
	while( a && b )
		if ( a > b ) a %= b;
		else b %= a;
	return a + b;
}
struct RSABreaker
{
public:
	int decrypt( int e, int n, int b )
	{
		int x = 1, m = 0;
		for( int i = 1; i < n; i++ )
			if ( gcd(i, n) == 1 ) m++;
		for( int i = 0; i < e; i++ )
			x = x * b % n;
		for( int d = 1; d < n; d++ )
			if ( e * d % m == 1 )
			{
				x = 1;
				for( int i = 0; i < d; i++ )
					x = x * b % n;
				return x;
			}
		return -1;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 3; int Arg3 = 7; verify_case(0, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 17; int Arg1 = 33; int Arg2 = 4; int Arg3 = 31; verify_case(1, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 42; int Arg2 = 17; int Arg3 = 17; verify_case(2, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 997; int Arg2 = 7; int Arg3 = 523; verify_case(3, Arg3, decrypt(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RSABreaker ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
