#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
struct PseudoPrimeTest
{
	int calc( int x, int y, int p )
	{
		if ( !y ) return 1;
		if ( y % 2 ) return x * calc( x, y - 1, p ) % p;
		int a = calc( x, y >> 1, p );
		return a * a % p;
	}
	int firstFail( int q )
	{
		int result;
		for( result = 2; result < q; result++ )
			if ( calc( result, q - 1, q ) != 1 ) break;
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; verify_case(0, Arg1, firstFail(Arg0)); }
	void test_case_1() { int Arg0 = 1729; int Arg1 = 7; verify_case(1, Arg1, firstFail(Arg0)); }
	void test_case_2() { int Arg0 = 561; int Arg1 = 3; verify_case(2, Arg1, firstFail(Arg0)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; verify_case(3, Arg1, firstFail(Arg0)); }
	void test_case_4() { int Arg0 = 341; int Arg1 = 3; verify_case(4, Arg1, firstFail(Arg0)); }
	void test_case_5() { int Arg0 = 31859; int Arg1 = 31859; verify_case(5, Arg1, firstFail(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PseudoPrimeTest ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
