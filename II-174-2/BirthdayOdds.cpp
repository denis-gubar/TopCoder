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
struct BirthdayOdds
{
public:
	int minPeople( int minOdds, int daysInYear )
	{
		int result = 1;
		double curOdds = 1;
		while( 100 - 100 * curOdds < minOdds )
		{
			curOdds *= (1.0 * daysInYear - result) / daysInYear;
			result++;
		}
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 75; int Arg1 = 5; int Arg2 = 4; verify_case(0, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 50; int Arg1 = 365; int Arg2 = 23; verify_case(1, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 365; int Arg2 = 4; verify_case(2, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 84; int Arg1 = 9227; int Arg2 = 184; verify_case(3, Arg2, minPeople(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BirthdayOdds ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
