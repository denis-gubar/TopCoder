#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
#endif
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
#define fora(i,v) for(unsigned int i = 0; i < (v).size(); i++)
int rotl( int size, int x )
{
	return (x << 1) & ((1 << size) - 1) | (x >> size - 1);
}
struct CircleBugs
{
public:
	int calc( int n, int x )
	{
		vi a(n);
		int result = x;
		fora(i, a)
		{
			a[i] = x = rotl( n, x );
			result = min( result, x );
		}
		return result;
	}
	int cycleLength( string formation )
	{ 
		int n = formation.size();
		set<int> H;
		int x = 0;
		fora(i, formation)
		{
			x <<= 1;
			if ( formation[i] == 'R' ) x |= 1;
		}
		x = calc( n, x );
		while( H.find(x) == H.end() )
		{
			H.insert(x);
			int y = rotl( n, x );
			x = ((x & y) | (~x & ~y)) & ((1 << n) - 1);
			x = calc( n, x );
		}
		int result = H.size();
		while( H.find(x) != H.end() )
		{
			H.erase(x);
			int y = rotl( n, x );
			x = ((x & y) | (~x & ~y)) & ((1 << n) - 1);
			x = calc( n, x );
		}
		return result - H.size();
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRG"; int Arg1 = 1; verify_case(0, Arg1, cycleLength(Arg0)); }
	void test_case_1() { string Arg0 = "RRGRG"; int Arg1 = 3; verify_case(1, Arg1, cycleLength(Arg0)); }
	void test_case_2() { string Arg0 = "RRRRRRRRRR"; int Arg1 = 1; verify_case(2, Arg1, cycleLength(Arg0)); }
	void test_case_3() { string Arg0 = "RGGGGGGGGG"; int Arg1 = 6; verify_case(3, Arg1, cycleLength(Arg0)); }
	void test_case_4() { string Arg0 = "GGRRGGRGRGRRGRRRGGR"; int Arg1 = 511; verify_case(4, Arg1, cycleLength(Arg0)); }
	void test_case_5() { string Arg0 = "RGGGGGGGGGGGGGGGGGGGGGGGGGGGR"; int Arg1 = 16383; verify_case(5, Arg1, cycleLength(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CircleBugs ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
