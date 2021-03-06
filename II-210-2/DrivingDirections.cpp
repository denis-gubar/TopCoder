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
struct DrivingDirections
{
	vector <string> reverse( vector <string> directions )
	{
		vector <string> result;
		if ( directions.size() == 1 ) return directions;
		result.push_back( "Start on " + directions.back().substr( directions.back()[5] == 'L' ? 13 : 14 ) );
		for( int k = directions.size() - 1; k > 1; k-- )
			result.push_back( (directions[k][5] == 'L' ? "Turn RIGHT on " : "Turn LEFT on ") + directions[k - 1].substr( directions[k - 1][5] == 'L' ? 13 : 14 ) );
		result.push_back( (directions[1][5] == 'L' ? "Turn RIGHT on " : "Turn LEFT on ") + directions[0].substr( directions[0][5] == 'L' ? 8 : 9 ) );
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Start on Pirate Street",
"Turn LEFT on Viking Avenue",
"Turn RIGHT on Ninja Court"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Start on Ninja Court",  "Turn LEFT on Viking Avenue",  "Turn RIGHT on Pirate Street" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reverse(Arg0)); }
	void test_case_1() { string Arr0[] = {"Start on planet Earth"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Start on planet Earth" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reverse(Arg0)); }
	void test_case_2() { string Arr0[] = {"Start on Hebron Ave",
"Turn RIGHT on CT-2",
"Turn LEFT on I-84",
"Turn LEFT on I-81",
"Turn RIGHT on I-80",
"Turn LEFT on I-680",
"Turn RIGHT on Mission Blvd",
"Turn LEFT on I-880",
"Turn RIGHT on Montague Expressway",
"Turn RIGHT on Mission College Blvd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Start on Mission College Blvd",  "Turn LEFT on Montague Expressway",  "Turn LEFT on I-880",  "Turn RIGHT on Mission Blvd",  "Turn LEFT on I-680",  "Turn RIGHT on I-80",  "Turn LEFT on I-81",  "Turn RIGHT on I-84",  "Turn RIGHT on CT-2",  "Turn LEFT on Hebron Ave" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reverse(Arg0)); }
	void test_case_3() { string Arr0[] = {"Start on  ",
"Turn LEFT on  0123456789 - ",
"Turn RIGHT on  0123456789 - ",
"Turn LEFT on                                      ",
"Turn RIGHT on                                     ",
"Turn LEFT on -a0b1c2d3e4f5g6h7i8j9k ",
"Turn RIGHT on -A0B1C2D3E4F5G6H7I8J9K ",
"Turn LEFT on -",
"Turn RIGHT on -"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Start on -",  "Turn LEFT on -",  "Turn RIGHT on -A0B1C2D3E4F5G6H7I8J9K ",  "Turn LEFT on -a0b1c2d3e4f5g6h7i8j9k ",  "Turn RIGHT on                                     ",  "Turn LEFT on                                      ",  "Turn RIGHT on  0123456789 - ",  "Turn LEFT on  0123456789 - ",  "Turn RIGHT on  " }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reverse(Arg0)); }
	void test_case_4() { string Arr0[] = {"Start on Duke University Rd",
"Turn RIGHT on Swift Ave",
"Turn LEFT on NC-147",
"Turn LEFT on I-85",
"Turn RIGHT on I-40",
"Turn RIGHT on US-52",
"Turn LEFT on I-74",
"Turn RIGHT on I-77",
"Turn LEFT on I-64",
"Turn RIGHT on Martin Luther King Memorial Bridge",
"Turn RIGHT on N 3rd St",
"Turn LEFT on Cole St",
"Turn LEFT on N Broadway",
"Turn RIGHT on Convention Plz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Start on Convention Plz",  "Turn LEFT on N Broadway",  "Turn RIGHT on Cole St",  "Turn RIGHT on N 3rd St",  "Turn LEFT on Martin Luther King Memorial Bridge",  "Turn LEFT on I-64",  "Turn RIGHT on I-77",  "Turn LEFT on I-74",  "Turn RIGHT on US-52",  "Turn LEFT on I-40",  "Turn LEFT on I-85",  "Turn RIGHT on NC-147",  "Turn RIGHT on Swift Ave",  "Turn LEFT on Duke University Rd" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, reverse(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	DrivingDirections ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
