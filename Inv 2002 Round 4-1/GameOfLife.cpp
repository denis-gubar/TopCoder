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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct GameOfLife
{
	int alive( vector <string> start, string rules, int generations )
	{
		int result = 0, m = start.size(), n = start[0].size();
		while( generations-- )
		{
			vs current(m, string(n, '.'));
			fora(i, start)
				fora(j, start[0])
				{
					int count = 0;
					for( int dx = -1; dx <= 1; dx++ )
						for( int dy = -1; dy <= 1; dy++ )
							count += (dx || dy) && start[(i + dx + m) % m][(j + dy + n) % n] == 'X';
					switch( rules[count] )
					{
						case 'B': current[i][j] = 'X'; break;
						case 'S': current[i][j] = start[i][j]; break;
					}
				}
			start = current;
		}
		fora(i, start)
			fora(j, start[0])
				result += start[i][j] == 'X';
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......"
,"......"
,".XXXX."
,"......"
,"......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DDSBDDDDD"; int Arg2 = 2; int Arg3 = 6; verify_case(0, Arg3, alive(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"XX","XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DDSBDDDDD"; int Arg2 = 1; int Arg3 = 0; verify_case(1, Arg3, alive(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"........XXX"
,"..........X"
,".........X."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."
,"..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DDSBDDDDD"; int Arg2 = 1000; int Arg3 = 5; verify_case(2, Arg3, alive(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"......................XXX.XX......................"
,".......................X..X......................."
,".......................X..XX......................"
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DBDBDBDBD"; int Arg2 = 16; int Arg3 = 80; verify_case(3, Arg3, alive(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BDDDDDDDD"; int Arg2 = 2; int Arg3 = 1; verify_case(4, Arg3, alive(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	GameOfLife ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
