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
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct SimplePath
{
	int trouble( string direction, vector <int> length )
	{
		int n = length.size();
		vi x1(n), x2(n), y1(n), y2(n);
		int x = 0, y = 0;
		fora(i, length)
		{
			int dx = 0, dy = 0;
			switch( direction[i] )
			{
				case 'N': dx = 1; break;
				case 'S': dx = -1; break;
				case 'W': dy = 1; break;
				case 'E': dy = -1; break;
			}
			x1[i] = x, y1[i] = y;
			x += dx * length[i]; y += dy * length[i];
			x2[i] = x, y2[i] = y;
			if ( x1[i] > x2[i] ) swap(x1[i], x2[i]);
			if ( y1[i] > y2[i] ) swap(y1[i], y2[i]);
		}
		fora(i, length)
		{
			if ( i < n - 1 )
			{
				int a = ((direction[i]) << 8) + direction[i + 1];
				int b = ((direction[i + 1]) << 8) + direction[i];
				int z = min(a, b);
				if ( z == ('N' << 8) + 'S' || z == ('E' << 8) + 'W' ) return i;
			}
			for( int j = i + 2; j < n; j++ )
			{
				int a1 = x1[i], a2 = x2[i], a3 = x1[j], a4 = x2[j];
				int b1 = y1[i], b2 = y2[i], b3 = y1[j], b4 = y2[j];
				if ( (a3 <= a1 && a1 <= a4 || a3 <= a2 && a2 <= a4 || a1 <= a3 && a3 <= a2 || a1 <= a4 && a4 <= a2 ) &&
				 	 (b3 <= b1 && b1 <= b4 || b3 <= b2 && b2 <= b4 || b1 <= b3 && b3 <= b2 || b1 <= b4 && b4 <= b2 ) )
					return i;
			}
		}
		return -1;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "NWSEEN"; int Arr1[] = {5,5,3,2,5,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, trouble(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "NWWS"; int Arr1[] = {10,3,7,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, trouble(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "NWES"; int Arr1[] = {2,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, trouble(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "NWSE"; int Arr1[] = {100,100,100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, trouble(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "EEEEEW"; int Arr1[] = {1,1,1,1,1,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, trouble(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SimplePath ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
