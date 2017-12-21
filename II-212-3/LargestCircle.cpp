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
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct LargestCircle
{
	int radius( vs grid )
	{
		int m = grid.size(), n = grid[0].size();
		vector< vector< pair<int, int> > > M( min(m, n) / 2 + 1 );
		for( int i = min(m, n) / 2; i > 0; i-- )
			for( int x = 0; x <= i; x++ )
				for( int y = 0; y <= i; y++ )
					if ( !(x*x + y*y <= i*i &&
						(x+1)*(x+1) + y*y <= i*i &&
						x*x + (y+1)*(y+1) <= i*i &&
						(x+1)*(x+1) + (y+1)*(y+1) <= i*i) &&
						!(x*x + y*y >= i*i &&
						(x+1)*(x+1) + y*y >= i*i &&
						x*x + (y+1)*(y+1) >= i*i &&
						(x+1)*(x+1) + (y+1)*(y+1) >= i*i) )
						M[i].push_back( make_pair( x, y ) );
		for( int radius = min(m, n) / 2; radius > 0; radius-- )
			fora2(i, j, grid)
				if ( i + radius <= m && i >= radius && j + radius <= n && j >= radius )
				{
					bool flag = true;
					fora(k, M[radius])
					{
						int a = M[radius][k].first, b = M[radius][k].second;
						if ( grid[i + a][j + b] == '#' || 
							grid[i + a][j - b - 1] == '#' || 
							grid[i - a - 1][j - b - 1] == '#' || 
							grid[i - a - 1][j + b] == '#' )
						{
							flag = false; break;
						}
					}
					if ( flag ) return radius;
				}
		return 0;
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = - 1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _Arg0[] = 
	{ "####",
  "#..#",
  "#..#",
  "####" }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	1
	; A1.push_back( Arg1 );  }
	{ /*Test 1*/string _Arg0[] = 
	{ "############",
  "###......###",
  "##.######.##",
  "#.########.#",
  "#.##..####.#",
  "#.##..####.#",
  "#.########.#",
  "#.########.#",
  "#.########.#",
  "##.######.##",
  "###......###",
  "############" }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	5
	; A1.push_back( Arg1 );  }
	{ /*Test 2*/string _Arg0[] = 
	{ ".........." }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	0
	; A1.push_back( Arg1 );  }
	{ /*Test 3*/string _Arg0[] = 
	{ "#######",
  "#######",
  "#######",
  "#######",
  "#######" }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	0
	; A1.push_back( Arg1 );  }
	{ /*Test 4*/string _Arg0[] = 
	{ "#####.......",
  "#####.......",
  "#####.......",
  "............",
  "............",
  "............",
  "............",
  "............",
  "............",
  "............" }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	4
	; A1.push_back( Arg1 );  }
	{ /*Test 5*/string _Arg0[] = 
	{ "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
  "...#...#...#...#...#...#...#...#...#...#...#...#..",
  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
  ".#...#...#...#...#...#...#...#...#...#...#...#...#",
  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
  "...#...#...#...#...#...#...#...#...#...#...#...#..",
  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
  ".#...#...#...#...#...#...#...#...#...#...#...#...#",
  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
  "...#...#...#...#...#...#...#...#...#...#...#...#.#",
  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#." }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	0
	; A1.push_back( Arg1 );  }
	{ /*Test 6*/string _Arg0[] = 
	{ ".........................#........................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  ".................................................." }
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	24
	; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], radius( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	LargestCircle ___test;
	___test.run_test();
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
