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
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
struct LoadBalancing
{
	int minTime( vector <int> chunkSizes )
	{
		transform( all(chunkSizes), chunkSizes.begin(), bind2nd( divides<int>(), 1024 ) );
		int total = accumulate( all(chunkSizes), 0 );
		vi M( total / 2 + 1, 0 ); M[0] = 1;
		fora(i, chunkSizes)
			forad(j, M)
				if ( M[j] && j + chunkSizes[i] <= total / 2 ) M[j + chunkSizes[i]] = 1;
		forad(j, M)
			if ( M[j] ) return (total - j) << 10;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3072, 3072, 7168, 3072, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9216; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = {2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2048; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = {2048, 1024, 1024, 2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3072; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = {4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 104857600; verify_case(3, Arg1, minTime(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	LoadBalancing ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
