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
struct CountGame
{
public:
	int howMany( int maxAdd, int goal, int next )
	{
		if ( !((goal - next + 1) % (maxAdd + 1)) ) return -1;
		return (goal - next + 1) % (maxAdd + 1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 20; int Arg2 = 10; int Arg3 = 3; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 10; int Arg3 = 5; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 9; int Arg3 = -1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 50; int Arg2 = 50; int Arg3 = 1; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CountGame ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
