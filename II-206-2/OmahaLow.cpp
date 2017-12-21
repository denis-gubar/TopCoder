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
struct OmahaLow
{
	string low( string sharedCards, string playersCards )
	{
		string result = "";
		for( int i1 = 0; i1 < sharedCards.size(); i1++ )
			for( int i2 = i1 + 1; i2 < sharedCards.size(); i2++ )
				for( int i3 = i2 + 1; i3 < sharedCards.size(); i3++ )
					for( int j1 = 0; j1 < playersCards.size(); j1++ )
						for( int j2 = j1 + 1; j2 < playersCards.size(); j2++ )
						{
							string s; s += sharedCards[i1];
							s += sharedCards[i2]; s += sharedCards[i3];
							s += playersCards[j1]; s += playersCards[j2];
							sort( all(s), greater<char>() );
							if ( s[0] > '8' ) continue;
							s.erase( unique( all(s) ), s.end() );
							if ( s.size() < 5 ) continue;
							if ( s < result || result == "" ) result = s;
						}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123QK"; string Arg1 = "45TJ"; string Arg2 = "54321"; verify_case(0, Arg2, low(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "55443"; string Arg1 = "2345"; string Arg2 = ""; verify_case(1, Arg2, low(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1357Q"; string Arg1 = "345J"; string Arg2 = "75431"; verify_case(2, Arg2, low(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "76285"; string Arg1 = "4816"; string Arg2 = "65421"; verify_case(3, Arg2, low(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "12345"; string Arg1 = "3339"; string Arg2 = ""; verify_case(4, Arg2, low(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "58463"; string Arg1 = "947K"; string Arg2 = "76543"; verify_case(5, Arg2, low(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "67521"; string Arg1 = "J859"; string Arg2 = "86521"; verify_case(6, Arg2, low(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	OmahaLow ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
