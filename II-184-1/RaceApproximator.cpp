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
struct RaceApproximator
{
public:
	string timeToBeat( int d1, int t1, int d2, int t2, int raceDistance )
	{
		int T = t1 * exp(log(1.0 * t2/t1)*log(1.0 * d1/raceDistance)/log(1.0 * d1/d2));
		char buf[100];
		sprintf( buf, "%d:%02d:%02d", T/3600, T % 3600 / 60, T % 60 );
		return buf;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 800; int Arg1 = 118; int Arg2 = 5000; int Arg3 = 906; int Arg4 = 1500; string Arg5 = "0:03:57"; verify_case(0, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 400; int Arg1 = 65; int Arg2 = 1600; int Arg3 = 350; int Arg4 = 800; string Arg5 = "0:02:30"; verify_case(1, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1600; int Arg1 = 299; int Arg2 = 10000; int Arg3 = 2360; int Arg4 = 5000; string Arg5 = "0:18:00"; verify_case(2, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 17; int Arg2 = 10000; int Arg3 = 4500; int Arg4 = 9000; string Arg5 = "1:06:00"; verify_case(3, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 156; int Arg1 = 117; int Arg2 = 3863; int Arg3 = 2754; int Arg4 = 1755; string Arg5 = "0:21:06"; verify_case(4, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RaceApproximator ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
