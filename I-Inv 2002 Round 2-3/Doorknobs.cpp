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
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct Doorknobs
{
	int ones( int x )
	{
		int result = 0;
		while( x )
		{
			x &= x - 1; result++;
		}
		return result;
	}
	int shortest( vector <string> house, int doorknobs )
	{
		int result = 0;
		vector<vvi> state( 64, vvi(64, vi(64, 0)) );
		vi X, Y;
		fora(i, house)
			fora(j, house[0])
				if ( house[i][j] == 'o' )
				{
					X.push_back( i ); Y.push_back( j );
				}
        queue<int> q;
		q.push( 0 ); q.push( 0 ); q.push( 0 ); q.push( 0 );
		while( !q.empty() )
		{
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			int t = q.front(); q.pop();
			int s = q.front(); q.pop();
			if ( state[t][x][y] ) continue;
			state[t][x][y] = 1;
			fora(i, X)
				if ( X[i] == x && Y[i] == y )
					t |= 1 << i;
			if ( ones( t ) == doorknobs ) return s;
			if ( x > 0 && house[x - 1][y] != '#' )
			{
				q.push( x - 1 ); q.push( y ); q.push( t ); q.push( s + 1 );
			}
			if ( y > 0 && house[x][y - 1] != '#' )
			{
				q.push( x ); q.push( y - 1 ); q.push( t ); q.push( s + 1 );
			}
			if ( x < house.size() - 1 && house[x + 1][y] != '#' )
			{
				q.push( x + 1 ); q.push( y ); q.push( t ); q.push( s + 1 );
			}
			if ( y < house[0].size() - 1 && house[x][y + 1] != '#' )
			{
				q.push( x ); q.push( y + 1 ); q.push( t ); q.push( s + 1 );
			}
		}
		return -1;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
/*	void test_case_0() { string Arr0[] = {"....."
,"o...."
,"o...."
,"o...."
,"...o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, shortest(Arg0, Arg1)); }
*/	void test_case_0() { string Arr0[] = {"..................................................", "..................................................", "..................................................", "..................................................",
	"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"...................o..............................", "..................................................", 
		"..................................................", "..................................................", 
		"........................................#.........", ".......................................#o#........", 
		"........................................#.........", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..........#.......................................", 
		".........#o#......................................", "..........#.......................................", 
		"..................................................", ".....................................#............", 
		"....................................#o#...........", ".....................................#............", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", "..................................................", 
		"..................................................", ".......................o.........................o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = -1; verify_case(0, Arg2, shortest(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"....."
,"o...."
,"o...."
,"o...."
,"...o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 7; verify_case(1, Arg2, shortest(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".#..."
,"#...."
,"...oo"
,"...oo"
,"...oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(2, Arg2, shortest(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"...o."
,"o..o."
,"....."
,"..oo."
,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 7; verify_case(3, Arg2, shortest(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"....#"
,".##o#"
,".##oo"
,"o##.#"
,"....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 12; verify_case(4, Arg2, shortest(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"....#"
,"o##o#"
,".##oo"
,".##.#"
,"....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 8; verify_case(5, Arg2, shortest(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"...................o.............................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"........................................o........."
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
,"..........o......................................."
,".................................................."
,".................................................."
,".................................................."
,".....................................o............"
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
,".................................................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 106; verify_case(6, Arg2, shortest(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Doorknobs ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 