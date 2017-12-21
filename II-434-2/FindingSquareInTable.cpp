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
struct FindingSquareInTable
{
	bool isSquare( int x )
	{
		int y = static_cast<int>( sqrt( 1.0 * x ) );
		return x == y * y || x == (y + 1) * (y + 1);
	}
	int findMaximalSquare( vs table )
	{
		int result = -1;
		int m = table.size(), n = table[0].size();
		fora2(x, y, table)
		{
			for(int dx = -m; dx <= m; ++dx)
				for(int dy = -n; dy <= n; ++dy)
					if ( dx || dy )
					{
						int current = 0;
						for( int i = 0; x + dx * i >= 0 && x + dx * i < m && y + dy * i >= 0 && y + dy * i < n; ++i )
						{
							current = current * 10 + table[x + dx * i][y + dy * i] - '0';
							if ( result < current && isSquare( current ) )
								result = current;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _table[] = 
	{"123",
 "456"}
	; vs table(_table, _table + (sizeof(_table) / sizeof(_table[0]))); A0.push_back( table ); int result = 
	64
	; A1.push_back( result );  }
	{ /*Test 1*/string _table[] = 
	{"00000",
 "00000",
 "00200",
 "00000",
 "00000"}
	; vs table(_table, _table + (sizeof(_table) / sizeof(_table[0]))); A0.push_back( table ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 2*/string _table[] = 
	{"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"}
	; vs table(_table, _table + (sizeof(_table) / sizeof(_table[0]))); A0.push_back( table ); int result = 
	320356
	; A1.push_back( result );  }
	{ /*Test 3*/string _table[] = 
	{"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}
	; vs table(_table, _table + (sizeof(_table) / sizeof(_table[0]))); A0.push_back( table ); int result = 
	9
	; A1.push_back( result );  }
	{ /*Test 4*/string _table[] = 
	{"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"}
	; vs table(_table, _table + (sizeof(_table) / sizeof(_table[0]))); A0.push_back( table ); int result = 
	-1
	; A1.push_back( result );  }
	{ /*Test 5*/string _table[] = 
	{"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"}
	; vs table(_table, _table + (sizeof(_table) / sizeof(_table[0]))); A0.push_back( table ); int result = 
	95481
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], findMaximalSquare( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	FindingSquareInTable ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
