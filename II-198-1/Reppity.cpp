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
struct Reppity
{
	int longestRep( string input )
	{
		int result = 0;
		fora(start, input)
			for( int finish = start; finish < input.size(); finish++ )
				if ( result <= finish - start && input.find( input.substr( start, finish - start + 1 ), finish + 1 ) != - 1 )
					result = finish - start + 1;
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDEXXXYYYZZZABCDEZZZYYYXXX"; int Arg1 = 5; verify_case(0, Arg1, longestRep(Arg0)); }
	void test_case_1() { string Arg0 = "abcdabcdabcdabCD"; int Arg1 = 6; verify_case(1, Arg1, longestRep(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy"; int Arg1 = 25; verify_case(2, Arg1, longestRep(Arg0)); }
	void test_case_3() { string Arg0 = "againANDagainANDagainANDagainANDagainANDagain"; int Arg1 = 21; verify_case(3, Arg1, longestRep(Arg0)); }
	void test_case_4() { string Arg0 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX"; int Arg1 = 0; verify_case(4, Arg1, longestRep(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Reppity ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
