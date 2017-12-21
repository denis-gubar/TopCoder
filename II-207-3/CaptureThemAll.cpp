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
typedef vector<vector<int> > vvi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct CaptureThemAll
{
	int calc( string a, string b )
	{
		vvi M(8, vi(8, 0));
		M[a[0] - 'a'][a[1] - '1'] = true;
		for( int result = 1; ; result++ )
		{
			vvi Z(8, vi(8, 0));
			fora(i, M)
				fora(j, M)
					for( int dx = -2; dx <= 2; dx++ )
						for( int dy = -2; dy <= 2; dy++ )
							Z[i][j] |= i + dx >= 0 && i + dx <= 7 && j + dy >= 0 && j + dy <= 7 && abs(dx) + abs(dy) == 3 && M[i + dx][j + dy];
			M = Z;
			if ( M[b[0] - 'a'][b[1] - '1'] )
				return result;
		}
	}
	int fastKnight( string knight, string rook, string queen )
	{
		return calc( rook, queen ) + min( calc( knight, rook ), calc( queen, knight ) );
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a1"; string Arg1 = "b3"; string Arg2 = "c5"; int Arg3 = 2; verify_case(0, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "b1"; string Arg1 = "c3"; string Arg2 = "a3"; int Arg3 = 3; verify_case(1, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "a1"; string Arg1 = "a2"; string Arg2 = "b2"; int Arg3 = 6; verify_case(2, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "a5"; string Arg1 = "b7"; string Arg2 = "e4"; int Arg3 = 3; verify_case(3, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "h8"; string Arg1 = "e2"; string Arg2 = "d2"; int Arg3 = 6; verify_case(4, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	CaptureThemAll ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
