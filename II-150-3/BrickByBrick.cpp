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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct BrickByBrick
{
	int timeToClear( vs map )
	{
		int result = 0, m = map.size(), n = map[0].size(), x = 0, y = 1, dir = 0, b = 0;
		int dx[] = {1, 1, -1, -1}; int dy[] = {1, -1, -1, 1};
		fora2(i, j, map)
			b += map[i][j] == 'B';
		set<int> S;
		while( b > 0 )
		{
			if ( !S.insert( x * 10000 + y * 100 + dir ).second ) return -1;
			x += dx[dir]; y += dy[dir]; ++result;
#define test(nx, ny, ndir) dir = ndir; else if ( map[nx][ny] == '#' ) dir = ndir; \
			else if ( map[nx][ny] == 'B' ) \
			{ --b; S.clear(); map[nx][ny] = '.'; dir = ndir; }
			switch( dir )
			{
				case 0:
					if ( x % 2 )
					{
						if ( y == 2 * n ) test( x / 2, y / 2, 1 );
					}
					else
					{
						if ( x == 2 * m ) test( x / 2, y / 2, 3 );
					}
					break;
				case 1:
					if ( x % 2 )
					{
						if ( y == 0 ) test( x / 2, y / 2 - 1, 0 );
					}
					else
					{
						if ( x == 2 * m ) test( x / 2, y / 2, 2 );
					}
					break;
				case 2:
					if ( x % 2 )
					{
						if ( y == 0 ) test( x / 2, y / 2 - 1, 3 );
					}
					else
					{
						if ( x == 0 ) test( x / 2 - 1, y / 2, 1 );
					}
					break;
				case 3:
					if ( x % 2 )
					{
						if ( y == 2 * n ) test( x / 2, y / 2, 2 );
					}
					else
					{
						if ( x == 0 ) test( x / 2 - 1, y / 2, 0 );
					}
					break;
			}
		}
		return result;
	}
// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const long long& expected, const long long& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _map[] = 
	{ ".B",
  "BB" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); int result = 
	6
	; A1.push_back( result );  }
	{ /*Test 1*/string _map[] = 
	{ ".BB",
  "BBB",
  "BBB" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); int result = 
	-1
	; A1.push_back( result );  }
	{ /*Test 2*/string _map[] = 
	{ "......B",
  "###.###",
  "B.....B" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); int result = 
	35
	; A1.push_back( result );  }
	{ /*Test 3*/string _map[] = 
	{ "..BBB...",
  ".#BB..#.",
  "B.#B.B..",
  "B.B.....",
  "##.B.B#.",
  "#BB.#.B.",
  "B..B.BB.",
  "#..BB..B",
  ".B....#." }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); int result = 
	-1
	; A1.push_back( result );  }
	{ /*Test 4*/string _map[] = 
	{ ".BB..BBB.B...",
  "B.B...B..BB..",
  "#B...B#B.....",
  "B#B.B##...##B",
  "BB.B#.B##B.B#",
  "B.B#.BBB.BB#B",
  "B#BBB##.#B#B.",
  "B#BB.BBB#BB.#" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); int result = 
	3912
	; A1.push_back( result );  }
	{ /*Test 5*/string _map[] = 
	{ ".BBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); int result = 
	31753
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], timeToClear( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BrickByBrick ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
