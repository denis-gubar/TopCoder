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
string replace_all( string s, string oldValue, string newValue )
{
	string result;
	int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
struct Animation
{
public:
	vector <string> animate( int speed, string init )
	{
		vector <string> result;
		result.push_back( replace_all( replace_all( init, "L", "X" ), "R", "X" ) );
		string s(init.size(), '.');
		while( init != s )
		{
			string temp = s;
			fora(i, s)
			{
				if ( init[i] == 'R' || init[i] == 'X' )
				{
					if ( speed + i < init.size() )
						temp[speed + i] = temp[speed + i] == '.' ? 'R' : 'X';
				}
				if ( init[i] == 'L' || init[i] == 'X' )
				{
					if ( -int(speed) + i < init.size() )
						temp[i - speed] = temp[i - speed] == '.' ? 'L' : 'X';
				}
			}
			init = temp;
			result.push_back( replace_all( replace_all( init, "L", "X" ), "R", "X" ) );			
		}
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 =  "..R...." ; string Arr2[] = { "..X....",  "....X..",  "......X",  "......." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, animate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "RR..LRL" ; string Arr2[] = { "XX..XXX",  ".X.XX..",  "X.....X",  "......." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, animate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "LRLR.LRLR"; string Arr2[] = { "XXXX.XXXX",  "X..X.X..X",  ".X.X.X.X.",  ".X.....X.",  "........." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, animate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "RLRLRLRLRL"; string Arr2[] = { "XXXXXXXXXX",  ".........." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, animate(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; string Arg1 = "..."; string Arr2[] = { "..." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, animate(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; string Arg1 = "LRRL.LR.LRR.R.LRRL."; string Arr2[] = { "XXXX.XX.XXX.X.XXXX.",  "..XXX..X..XX.X..XX.",  ".X.XX.X.X..XX.XX.XX",  "X.X.XX...X.XXXXX..X",  ".X..XXX...X..XX.X..",  "X..X..XX.X.XX.XX.X.",  "..X....XX..XX..XX.X",  ".X.....XXXX..X..XX.",  "X.....X..XX...X..XX",  ".....X..X.XX...X..X",  "....X..X...XX...X..",  "...X..X.....XX...X.",  "..X..X.......XX...X",  ".X..X.........XX...",  "X..X...........XX..",  "..X.............XX.",  ".X...............XX",  "X.................X",  "..................." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, animate(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Animation ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
