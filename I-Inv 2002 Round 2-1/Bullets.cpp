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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct Bullets
{
	int match( vector <string> guns, string bullet )
	{
		int result = -1;
		fora(i, guns)
		{
			string s = guns[i] + guns[i];
			if ( guns[i].size() == bullet.size() && s.find( bullet ) != -1 )
				result = i;
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"| | | |","|| || |"," ||||  "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "|| || |"; int Arg2 = 1; verify_case(0, Arg2, match(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"|||   |","| | || "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "||||   "; int Arg2 = 0; verify_case(1, Arg2, match(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"|| || ||","| | | | ","||||||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "||| ||| "; int Arg2 = -1; verify_case(2, Arg2, match(Arg0, Arg1)); }
	void test_case_3() { vector <string> Arg0; string Arg1 = "| | | |"; int Arg2 = -1; verify_case(3, Arg2, match(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"|| || ||","| | | | ","||| ||| ","||||||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "|| ||| |"; int Arg2 = 2; verify_case(4, Arg2, match(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Bullets ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
