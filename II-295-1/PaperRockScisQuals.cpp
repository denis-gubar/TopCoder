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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct PaperRockScisQuals
{
	int whoPassed( vs players )
	{
        vi A( players.size() );
        fora(i, players)
            fora(j, players)
                if ( i > j )
                {
                    int x = 0;
                    for( int k = 0; k < 5; ++k )
                        if ( players[i][k] == 'P' && players[j][k] == 'R' ||
                            players[i][k] == 'R' && players[j][k] == 'S' ||
                            players[i][k] == 'S' && players[j][k] == 'P' )
                            ++x;
                        else if ( players[j][k] == 'P' && players[i][k] == 'R' ||
                            players[j][k] == 'R' && players[i][k] == 'S' ||
                            players[j][k] == 'S' && players[i][k] == 'P' )
                            --x;
                    if ( x < 0 )
                        A[j] += 2;
                    else if ( x > 0 )
                        A[i] += 2;
                    else
                    {
                        ++A[i]; ++A[j];
                    }
                }
		return distance( A.begin(), max_element( all(A) ) );
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
	{ /*Test 0*/string _players[] = 
	{"PPRRS","PPRRP","PPRSP","PPSSP"}
	; vs players(_players, _players + (sizeof(_players) / sizeof(_players[0]))); A0.push_back( players ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 1*/string _players[] = 
	{"RRRRR","PPPPP","RRRRR","PPPPP"}
	; vs players(_players, _players + (sizeof(_players) / sizeof(_players[0]))); A0.push_back( players ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 2*/string _players[] = 
	{"RRRRR","PPPPP","SSSSS","PPPPP"}
	; vs players(_players, _players + (sizeof(_players) / sizeof(_players[0]))); A0.push_back( players ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 3*/string _players[] = 
	{"RRRRR","PPPPP","SSSSS","SSSSS","RRRRR","RRRRR"}
	; vs players(_players, _players + (sizeof(_players) / sizeof(_players[0]))); A0.push_back( players ); int result = 
	0
	; A1.push_back( result );  }
	{ /*Test 4*/string _players[] = 
	{"PPRPS","RRRPR","SSPRS","SSPRR","PPRSP","SPRPS","SPRSP","PRSPR","PRSPR"}
	; vs players(_players, _players + (sizeof(_players) / sizeof(_players[0]))); A0.push_back( players ); int result = 
	6
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], whoPassed( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PaperRockScisQuals ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
