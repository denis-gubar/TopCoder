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
struct SnowClearing
{
	int probe( const vs& citymap, int x, int y )
	{
		int result = 0;
		if ( x && citymap[x - 1][y] != ' ' )
			++result;
		if ( y && citymap[x][y - 1] != ' ' )
			++result;
		if ( x < citymap.size() - 1 && citymap[x + 1][y] != ' ' )
			++result;
		if ( y < citymap[0].size() - 1 && citymap[x][y + 1] != ' ' )
			++result;
		return result;
	}
	int unreachable( vs citymap, int row, int column )
	{
		int result = 0;
		queue<int> q;
		int r = (row - 1) << 1, c = (column - 1) << 1;
		fora2(i, j, citymap)
			if ( citymap[i][j] == '+' && ( i != r || j != c ) && probe( citymap, i, j ) == 1 )
			{
				q.push( i ); q.push( j );		
			}
		while( !q.empty() )
		{
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			if ( x == r && y == c )
				continue;
			if ( x && citymap[x - 1][y] != ' ' )
			{
				citymap[x - 1][y] = ' ';
				++result;
				if ( probe( citymap, x - 2, y ) == 1 )
				{
					q.push( x - 2 ); q.push( y );
				}
			}
			if ( x < citymap.size() - 1  && citymap[x + 1][y] != ' ' )
			{
				citymap[x + 1][y] = ' ';
				++result;
				if ( probe( citymap, x + 2, y ) == 1 )
				{
					q.push( x + 2 ); q.push( y );
				}
			}
			if ( y && citymap[x][y - 1] != ' ' )
			{
				citymap[x][y - 1] = ' ';
				++result;
				if ( probe( citymap, x, y - 2 ) == 1 )
				{
					q.push( x ); q.push( y - 2 );
				}
			}
			if ( y < citymap[0].size() - 1  && citymap[x][y + 1] != ' ' )
			{
				citymap[x][y + 1] = ' ';
				++result;
				if ( probe( citymap, x, y + 2 ) == 1 )
				{
					q.push( x ); q.push( y + 2 );
				}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/string _citymap[] = 
	{"+-+-+-+-+-+-+"
,"| | | | | | |"
,"+-+ +-+ +-+ +"
,"|   |   |    "
,"+-+-+-+-+-+-+"}
	; vs citymap(_citymap, _citymap + (sizeof(_citymap) / sizeof(_citymap[0]))); A0.push_back( citymap ); int row = 
	2
	; A1.push_back( row ); int column = 
	7
	; A2.push_back( column ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 1*/string _citymap[] = 
	{"+-+"
,"| |"
,"+ +"}
	; vs citymap(_citymap, _citymap + (sizeof(_citymap) / sizeof(_citymap[0]))); A0.push_back( citymap ); int row = 
	1
	; A1.push_back( row ); int column = 
	1
	; A2.push_back( column ); int result = 
	3
	; A3.push_back( result );  }
	{ /*Test 2*/string _citymap[] = 
	{"+-+-+"
,"| | |"
,"+-+ +"}
	; vs citymap(_citymap, _citymap + (sizeof(_citymap) / sizeof(_citymap[0]))); A0.push_back( citymap ); int row = 
	1
	; A1.push_back( row ); int column = 
	3
	; A2.push_back( column ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 3*/string _citymap[] = 
	{"+-+-+"
,"|   |"
,"+-+-+"}
	; vs citymap(_citymap, _citymap + (sizeof(_citymap) / sizeof(_citymap[0]))); A0.push_back( citymap ); int row = 
	2
	; A1.push_back( row ); int column = 
	2
	; A2.push_back( column ); int result = 
	0
	; A3.push_back( result );  }
	{ /*Test 4*/string _citymap[] = 
	{"+ +-+ +-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+-+-+ +"
,"| |   | |     |   |   |         |     | |     | |"
,"+ +-+-+-+ +-+-+-+ +-+ +-+-+-+-+ +-+-+-+ +-+ +-+-+"
,"| | |       |   | |   |   |   |   |     | |   |  "
,"+ +-+-+ +-+-+ +-+-+-+-+-+-+-+ +-+ +-+ +-+ +-+ +-+"
,"|     | | | | |   |             |     |   | |   |"
,"+-+-+ +-+-+-+ +-+ +-+ + +-+-+-+-+-+ +-+-+ +-+-+-+"
,"|       | |     |     |   |         |   | |     |"
,"+-+-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+-+-+-+"
,"      |   | |     |   | |     | | |   | |       |"
,"+ +-+-+-+-+ + +-+ +-+ +-+ +-+-+ +-+-+-+-+-+ +-+-+"
,"| |   | |     |   |         |   | | |     |   | |"
,"+-+-+-+-+-+ +-+-+ +-+-+-+ +-+-+ +-+-+ +-+-+ +-+-+"
,"          |   |   |   |   | |                    "
,"+-+-+-+-+-+-+ +-+-+-+ + +-+-+ +-+ +-+-+-+ +-+-+ +"
,"|                     | |     |   |   | |   | | |"
,"+ +-+-+-+-+-+-+ + +-+-+-+-+-+-+-+-+ +-+-+-+ + +-+"
,"| |     |   | | |   | | | |       | |   | | | | |"
,"+-+-+-+ +-+-+-+-+ +-+ + +-+ +-+-+-+ +-+-+ +-+ +-+"
,"    | |   | | |   |               |   |          "
,"+-+ +-+-+-+-+-+ +-+ + +-+-+-+-+-+-+ + + +-+-+ +-+"
,"  | | |         | | | |   |   | | | | | | | | |  "
,"+-+-+ + +-+ +-+ +-+-+-+-+ + + + +-+-+ +-+-+-+-+-+"
,"    | | | | | | |         | | |       |     | |  "
,"+ +-+ + + +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+"
,"| |   | |     | |   |   |   |   |   | |         |"
,"+-+-+ +-+-+-+-+ +-+ + +-+-+-+-+ +-+ +-+-+-+-+-+-+"
,"      | |   | | | |     |       | |         | |  "
,"+-+ + +-+-+-+-+ + +-+-+-+ +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | | |   |   |     | |   |   | |   | | |   |  "
,"+-+-+-+-+-+-+ +-+-+-+-+-+-+ +-+ +-+ +-+ +-+-+ +-+"
,"|     | | |   |     |     |   | | |   |   | | | |"
,"+-+-+-+-+-+-+ + +-+-+-+-+-+ +-+-+-+-+ +-+ + +-+-+"
,"| | | | |   | | |   | |         |     | | | |   |"
,"+ +-+ +-+-+ + + +-+-+ + + +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | |   |     | |     |         |   | |   | | |"
,"+ +-+ +-+-+-+ +-+-+-+-+ +-+-+-+ +-+-+-+ +-+-+ + +"
,"|     | |     |   |           |   | | |   | | |  "
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+ +-+-+ +-+-+ +-+"
,"|         |     |       | |   |       | | | | |  "
,"+-+-+-+ +-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+ +-+-+-+-+"
,"        |   |   | | | | | | | | | | | | | |     |"
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+ +-+-+-+ +-+ + +-+-+ +"
,"      | | | |       | |     | |   |       |   | |"
,"+ +-+-+-+-+-+ +-+ +-+ +-+-+-+ +-+-+-+-+-+ + +-+-+"
,"| | |       | | | |       |     | | | |       | |"
,"+-+-+-+-+-+-+-+ + +-+-+-+ + +-+-+-+-+-+-+-+ +-+ +"
,"      |   |   | |   | |         |     | | | | | |"
,"+-+-+-+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+ + + +-+-+ +"}
	; vs citymap(_citymap, _citymap + (sizeof(_citymap) / sizeof(_citymap[0]))); A0.push_back( citymap ); int row = 
	10
	; A1.push_back( row ); int column = 
	12
	; A2.push_back( column ); int result = 
	160
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], unreachable( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SnowClearing ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
