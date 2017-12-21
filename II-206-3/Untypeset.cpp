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
template<typename T> T FromString( string s )
{
    istringstream S( s );
	T result; S >> result;
	return result;
}
struct Untypeset
{
	int calc( vs A )
	{
		int m = A.size(), n = A[0].size();
		for( int j = 0; j < n; j++ )
		{
			bool flag = true; int f = 0;
			for( int i = 0; i < m; i++ )
			{
				flag &= A[i][j] == '+' || A[i][j] == ' ';
				if ( A[i][j] == '+' ) f++;
			}
			if ( flag && f == 1 )
			{
				vs B, C;
				for( int i = 0; i < m; i++ )
				{
					B.push_back( A[i].substr( 0, j - 1 ) );
					C.push_back( A[i].substr( j + 1 ) );
				}
				return calc( B ) + calc( C );
			}
		}
		int k = -1, best = 0;
		for( int i = 0; i < m; i++ )
		{
			int count = 0;
			for( int j = 0; j < n; j++ )
				if ( A[i][j] == '-' ) count++;
			if ( count > best )
			{
				best = count; k = i;
			}
		}
		if ( k > -1 )
		{
			vs B, C;
			copy( A.begin(), A.begin() + k, back_inserter( B ) );
			copy( A.begin() + k + 1, A.end(), back_inserter( C ) );
			return calc( B ) / calc( C );
		}
		string s;
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
				if ( A[i][j] != ' ' ) s += A[i][j];
		return FromString<int>( s );
	}
	int evaluate( vector <string> expression )
	{
		return calc( expression );
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "2801" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2801; verify_case(0, Arg1, evaluate(Arg0)); }
	void test_case_1() { string Arr0[] = { "  625       ",
  "------------",
  "        5   " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 125; verify_case(1, Arg1, evaluate(Arg0)); }
	void test_case_2() { string Arr0[] = { "       ",
  "500    ",
  "       ",
  "    +  ",
  "       ",
  "       ",
  "      1",
  "       ",
  "       " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 501; verify_case(2, Arg1, evaluate(Arg0)); }
	void test_case_3() { string Arr0[] = { "   120   ",
  "  -----  ",
  "    10   ",
  "---------",
  "    6    ",
  "   ---   ",
  "    2    " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, evaluate(Arg0)); }
	void test_case_4() { string Arr0[] = { "       24       ",
  " 31 + ----      ",
  "       12   + 16",
  "-----------     ",
  "   5 + 6        " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, evaluate(Arg0)); }
	void test_case_5() { string Arr0[] = {"3 + 4 + 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(5, Arg1, evaluate(Arg0)); }
	void test_case_6() { string Arr0[] = { " 1     4     9 ",
  "--- + --- + ---",
  " 1     2     3 " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(6, Arg1, evaluate(Arg0)); }
	void test_case_7() { string Arr0[] = 
{ "34      ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "   +    ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "     924" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 958; verify_case(7, Arg1, evaluate(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Untypeset ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
