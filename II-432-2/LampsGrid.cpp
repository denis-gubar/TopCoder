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
#define all(v) (v).begin(), (v).end()
struct LampsGrid
{
	int mostLit( vs initial, int K )
	{
		int result = 0;
        int m = initial[0].size();
        string s(m, '1');
        fora(i, initial)
        {
            int k = count(all(initial[i]), '0');
            if ( k % 2 != K % 2 || k > K )
                continue;
            vs current(initial);
            fora2(x, y, current)
                if ( initial[i][y] == '0' )
                    current[x][y] = '0' + '1' - current[x][y];
            int currentResult = 0;
            fora(j, current)
                currentResult += (current[j] == s);
            if ( result < currentResult )
                result = currentResult;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<int> A2;
	{ /*Test 0*/string _initial[] = 
	{"01",
 "10",
 "10"}
	; vs initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A0.push_back( initial ); int K = 
	1
	; A1.push_back( K ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 1*/string _initial[] = 
	{"101010"}
	; vs initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A0.push_back( initial ); int K = 
	2
	; A1.push_back( K ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 2*/string _initial[] = 
	{"00", "11"}
	; vs initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A0.push_back( initial ); int K = 
	999
	; A1.push_back( K ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 3*/string _initial[] = 
	{"0", "1", "0", "1", "0"}
	; vs initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A0.push_back( initial ); int K = 
	1000
	; A1.push_back( K ); int result = 
	2
	; A2.push_back( result );  }
	{ /*Test 4*/string _initial[] = 
	{"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"}
	; vs initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A0.push_back( initial ); int K = 
	6
	; A1.push_back( K ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 5*/string _initial[] = 
	{"01", "10", "01", "01", "10"}
	; vs initial(_initial, _initial + (sizeof(_initial) / sizeof(_initial[0]))); A0.push_back( initial ); int K = 
	1
	; A1.push_back( K ); int result = 
	3
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], mostLit( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	LampsGrid ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
