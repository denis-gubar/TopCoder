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
struct WaterLevel
{
	double netAmt( int evapNormal, int evapFlood, vector <int> rain )
	{
		double result = 0;
		fora(i, rain)
		{
			if ( result + rain[i] - evapNormal <= 0 && result <= 0 )
			{
				result += rain[i] - evapNormal;
				continue;
			}
			if ( result + rain[i] - evapFlood >= 0 && result >= 0 )
			{
				result += rain[i] - evapFlood;
				continue;
			}
			if ( rain[i] >= evapNormal && rain[i] <= evapFlood )
			{
				result = 0;
				continue;
			}
			if ( result > 0 )
			{
				double z = result / (evapFlood - rain[i]);
				result = (1 - z) * (rain[i] - evapNormal);
			}
			else
			{
				double z = result / (evapNormal - rain[i]);
				result = (1 - z) * (rain[i] - evapFlood);
			}
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 40; int Arr2[] = {0,60,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -35.0; verify_case(0, Arg3, netAmt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 39; int Arr2[] = {0,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10.5; verify_case(1, Arg3, netAmt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 40; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -20.0; verify_case(2, Arg3, netAmt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 800; int Arr2[] = {0,600}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(3, Arg3, netAmt(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WaterLevel ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
