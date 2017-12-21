#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct Socialize
{
	int average( vector <string> layout )
	{
		int count = 0, total = 0, k = 0, m = layout.size(), n = layout[0].size();
		vector<vvi> M;
		queue<int> q;
		fora2(i, j, layout)
			if ( layout[i][j] == 'P' )
			{
				q.push( k ); q.push( i ); q.push( j ); q.push( 0 );
				M.push_back( vvi(m, vi(n, 100000)) );
				M[k][i][j] = 0; k++;
			}
		while( !q.empty() )
		{
			int i = q.front(); q.pop();
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			int s = q.front(); q.pop();
			if ( s && layout[x][y] == 'P' && M[i][x][y] == s )
			{
				count++; total += s; M[i][x][y] = 0;
			}
#define calc(nx, ny)															\
			{																	\
				if ( M[i][nx][ny] > s + 1 && layout[nx][ny] != '#' )			\
				{																\
					q.push( i ); q.push( nx ); q.push( ny ); q.push( s + 1 );	\
					M[i][nx][ny] = s + 1;										\
				}																\
			}
			if ( x > 0 )
				calc( x - 1, y );
			if ( x < m - 1 )
				calc( x + 1, y );
			if ( y > 0 )
				calc( x, y - 1 );
			if ( y < n - 1 )
				calc( x, y + 1 );
		}
		return count ? (total + count / 2) / count : 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, average(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, average(Arg0)); }
	void test_case_2() { string Arr0[] = {"P#P"
,"P#."
,"P#P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, average(Arg0)); }
	void test_case_3() { string Arr0[] = {"P...P",
"###..",
"P...#",
"####P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, average(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Socialize ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
