// BEGIN CUT HERE
#include "precompiled.h"
/*
// END CUT HERE
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
*/
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct MirrorPath
{
	int getDir( int i, int j, int m, int n )
	{
		if ( !i ) return 2;
		if ( j == n - 1 ) return 3;
		if ( i == m - 1 ) return 0;
		if ( !j ) return 1;
		return -1;
	}
	vs path( vs map )
	{
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, 1, 0, -1};
		char c[] = {'|', '-', '|', '-'};
		vs result(map);
		vi X, Y, D;
		fora2(i, j, result)
			if ( result[i][j] == '.' )
			{
				int dir = getDir( i, j, result.size(), result[0].size() );
				if ( dir >= 0 )
					X.push_back( i ), Y.push_back( j ), D.push_back( dir );
			}
		int x = X[0], y = Y[0], d = D[0];
		while( x != X[1] || y != Y[1] )
		{
			if ( result[x][y] == '.' )
				result[x][y] = c[d];
			else if ( result[x][y] == '-' || result[x][y] == '|' )
				result[x][y] = '+';
			else if ( result[x][y] == '`' )
			{
				switch( d )
				{
					case 0:
						d = 3;
						break;
					case 1:
						d = 2;
						break;
					case 2:
						d = 1;
						break;
					case 3:
						d = 0;
						break;
				}
			}
			else if ( result[x][y] == '/' )
			{
				switch( d )
				{
					case 0:
						d = 1;
						break;
					case 1:
						d = 0;
						break;
					case 2:
						d = 3;
						break;
					case 3:
						d = 2;
						break;
				}
			}
			x += dx[d]; y += dy[d];
		}
		result[x][y] = c[d];
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _map[] = 
	{ "#.#",
  "#.#",
  "#.#" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); string _result[] = 
	{"#|#", "#|#", "#|#" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _map[] = 
	{ "############",
  "#######/....",
  "######//####",
  "#####//#####",
  "####//######",
  "..../#######",
  "############" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); string _result[] = 
	{"############", "#######/----", "######//####", "#####//#####", "####//######", "----/#######", "############" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _map[] = 
	{ "#######",
  "##/..`#",
  "##.##.#",
  "##.##.#",
  "...../#",
  "##.####",
  "##.####" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); string _result[] = 
	{"#######", "##/--`#", "##|##|#", "##|##|#", "--+--/#", "##|####", "##|####" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/string _map[] = 
	{ "###########.#",
  "#/........./.",
  "#.#########.#",
  "#`........./#",
  "#############" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); string _result[] = 
	{"###########|#", "#/---------/-", "#|#########|#", "#`---------/#", "#############" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/string _map[] = 
	{ "########.##",
  "#./......`#",
  "#../.`....#",
  "#.`...../.#",
  "#....`.../#",
  "###.#######" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); string _result[] = 
	{"########|##", "#./-----+`#", "#.|/-`..||#", "#.`+-+--/|#", "#..|.`---/#", "###|#######" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 5*/string _map[] = 
	{ "##.########",
  "#.........#",
  "..`.`.....#",
  "#..`......#",
  "#.`.`.`...#",
  "#....`....#",
  "#...`.`.`.#",
  "#.........#",
  "#.....`./.#",
  "#.........#",
  "###########" }
	; vs map(_map, _map + (sizeof(_map) / sizeof(_map[0]))); A0.push_back( map ); string _result[] = 
	{"##|########", "#.|.......#", "--`-`.....#", "#.|`|.....#", "#.`-`-`...#", "#...|`|...#", "#...`-`-`.#", "#.....|.|.#", "#.....`-/.#", "#.........#", "###########" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], path( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MirrorPath ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
