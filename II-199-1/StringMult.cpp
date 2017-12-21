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
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
#define all(v) (v).begin(), (v).end()
struct StringMult
{
	string times( string sFactor, int iFactor )
	{
		string result;
		if ( iFactor < 0 )
		{
			reverse( all(sFactor) );
			iFactor = -iFactor;
		}
		for( int i = 0; i < iFactor; i++ )
			result += sFactor;
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "wOw"; int Arg1 = 0; string Arg2 = ""; verify_case(0, Arg2, times(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AbC"; int Arg1 = -3; string Arg2 = "CbACbACbA"; verify_case(1, Arg2, times(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "Boo"; int Arg1 = 4; string Arg2 = "BooBooBooBoo"; verify_case(2, Arg2, times(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ""; int Arg1 = 50; string Arg2 = ""; verify_case(3, Arg2, times(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "Racecar"; int Arg1 = -5; string Arg2 = "racecaRracecaRracecaRracecaRracecaR"; verify_case(4, Arg2, times(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	StringMult ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
