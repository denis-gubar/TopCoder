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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct ImageDithering
{
	int count( string dithered, vector <string> screen )
	{
		int result = 0;
		fora2(i, j, screen)
			if ( dithered.find( screen[i][j] ) != -1 ) result++;
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BW"; string Arr1[] = {"AAAAAAAA",
 "ABWBWBWA",
 "AWBWBWBA",
 "ABWBWBWA",
 "AWBWBWBA",
 "AAAAAAAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 24; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BW"; string Arr1[] = {"BBBBBBBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBBBBBBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 48; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ACEGIKMOQSUWY"; string Arr1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 150; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CA"; string Arr1[] = {"BBBBBBB",
 "BBBBBBB",
 "BBBBBBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "DCBA"; string Arr1[] = {"ACBD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, count(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ImageDithering ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
