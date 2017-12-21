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
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct WordFind
{
	int probe( const vs& grid, int x, int y )
	{
		if ( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() )
			return 0;
		return grid[x][y];
	}
	vs findWords( vs grid, vs wordList )
	{
		vs result;
		fora(k, wordList)
		{
			int x = -1, y = -1;
			bool f = false;
			fora2(i, j, grid)
				if ( !f )
				{
					bool flag = true;
					fora(z, wordList[k])
						flag &= probe( grid, i, j + z ) == wordList[k][z];
					f |= flag;
					flag = true;
					fora(z, wordList[k])
						flag &= probe( grid, i + z, j ) == wordList[k][z];
					f |= flag;
					flag = true;
					fora(z, wordList[k])
						flag &= probe( grid, i + z, j + z ) == wordList[k][z];
					f |= flag;
					if ( f )
					{
						x = i; y = j;
					}
				}
			if ( x == -1 )
				result.push_back( string() );
			else
				result.push_back( ToString( x ) + " " + ToString( y ) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vs> A2;
	{ /*Test 0*/string _grid[] = 
	{"TEST",
 "GOAT",
 "BOAT"}
	; vs grid(_grid, _grid + (sizeof(_grid) / sizeof(_grid[0]))); A0.push_back( grid ); string _wordList[] = 
	{"GOAT", "BOAT", "TEST"}
	; vs wordList(_wordList, _wordList + (sizeof(_wordList) / sizeof(_wordList[0]))); A1.push_back( wordList ); string _result[] = 
	{ "1 0",
  "2 0",
  "0 0" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _grid[] = 
	{"SXXX",
 "XQXM",
 "XXLA",
 "XXXR"}
	; vs grid(_grid, _grid + (sizeof(_grid) / sizeof(_grid[0]))); A0.push_back( grid ); string _wordList[] = 
	{"SQL", "RAM"}
	; vs wordList(_wordList, _wordList + (sizeof(_wordList) / sizeof(_wordList[0]))); A1.push_back( wordList ); string _result[] = 
	{ "0 0",
  "" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _grid[] = 
	{"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"}
	; vs grid(_grid, _grid + (sizeof(_grid) / sizeof(_grid[0]))); A0.push_back( grid ); string _wordList[] = 
	{"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"}
	; vs wordList(_wordList, _wordList + (sizeof(_wordList) / sizeof(_wordList[0]))); A1.push_back( wordList ); string _result[] = 
	{ "0 0",
  "1 6",
  "0 22",
  "" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], findWords( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WordFind ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
