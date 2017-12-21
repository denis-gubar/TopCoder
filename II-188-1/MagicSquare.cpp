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
#include <utility>
using namespace std;
#ifdef __GNUC__
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template <typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
struct MagicSquare
{
public:
	int missing( vector <int> square )
	{
		int result;
		int a, b, x;
		for( int i = 0; i < 9; i += 3 )
		{
			x = accumulate( square.begin() + i, square.begin() + i + 3, 0 );
			if ( find( square.begin() + i, square.begin() + i + 3, -1 ) != square.begin() + i + 3 )
				a = x + 1;
			else
				b = x;
		}
		return b - a;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 8, 1, 6, 3, 5, -1, 4, 9, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, missing(Arg0)); }
	void test_case_1() { int Arr0[] = { -1, 1, 6, 3, 5, 7, 4, 9, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, missing(Arg0)); }
	void test_case_2() { int Arr0[] = { 5, 15, 13, 19, 11, 3, 9, 7, -1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(2, Arg1, missing(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MagicSquare ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
