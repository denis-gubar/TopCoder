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
struct TitleString
{
	string toFirstUpperCase( string title )
	{
		string result;
		title = " " + title;
		for( int i = 1; i < title.size(); i++ )
			result += (title[i - 1] == ' ') ? toupper(title[i]) : title[i];
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "introduction to algorithms"; string Arg1 = "Introduction To Algorithms"; verify_case(0, Arg1, toFirstUpperCase(Arg0)); }
	void test_case_1() { string Arg0 = "more than  one   space    between     words"; string Arg1 = "More Than  One   Space    Between     Words"; verify_case(1, Arg1, toFirstUpperCase(Arg0)); }
	void test_case_2() { string Arg0 = "  lord of the rings   the fellowship of the ring  "; string Arg1 = "  Lord Of The Rings   The Fellowship Of The Ring  "; verify_case(2, Arg1, toFirstUpperCase(Arg0)); }
	void test_case_3() { string Arg0 = "  "; string Arg1 = "  "; verify_case(3, Arg1, toFirstUpperCase(Arg0)); }
	void test_case_4() { string Arg0 = "i"; string Arg1 = "I"; verify_case(4, Arg1, toFirstUpperCase(Arg0)); }
	void test_case_5() { string Arg0 = "the king and i"; string Arg1 = "The King And I"; verify_case(5, Arg1, toFirstUpperCase(Arg0)); }
	void test_case_6() { string Arg0 = ""; string Arg1 = ""; verify_case(6, Arg1, toFirstUpperCase(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TitleString ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
