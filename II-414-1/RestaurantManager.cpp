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
typedef vector<vi> vvi;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct RestaurantManager
{
	int allocateTables( vi tables, vi groupSizes, vi arrivals, vi departures )
	{
		int result = 0;
        vvi busy(201);
        for( int t = 0; t <= 200; ++t )
        {
            tables.insert( tables.end(), all(busy[t]) );
            sort( all(tables) );
            fora(i, arrivals)
                if ( arrivals[i] == t )
                {
                    vi::iterator it = lower_bound( all(tables), groupSizes[i] );
                    if ( it == tables.end() )
                        result += groupSizes[i];
                    else
                    {
                        busy[departures[i]].push_back( *it );
                        tables.erase( it );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<vi> A3; vector<int> A4;
	{ /*Test 0*/int _tables[] = 
	{4}
	; vi tables(_tables, _tables + (sizeof(_tables) / sizeof(_tables[0]))); A0.push_back( tables ); int _groupSizes[] = 
	{4,8,4,2,2,4}
	; vi groupSizes(_groupSizes, _groupSizes + (sizeof(_groupSizes) / sizeof(_groupSizes[0]))); A1.push_back( groupSizes ); int _arrivals[] = 
	{0,10,12,16,18,26}
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A2.push_back( arrivals ); int _departures[] = 
	{10,20,18,26,36,28}
	; vi departures(_departures, _departures + (sizeof(_departures) / sizeof(_departures[0]))); A3.push_back( departures ); int result = 
	14
	; A4.push_back( result );  }
	{ /*Test 1*/int _tables[] = 
	{4,4}
	; vi tables(_tables, _tables + (sizeof(_tables) / sizeof(_tables[0]))); A0.push_back( tables ); int _groupSizes[] = 
	{4,8,4,2,2,4}
	; vi groupSizes(_groupSizes, _groupSizes + (sizeof(_groupSizes) / sizeof(_groupSizes[0]))); A1.push_back( groupSizes ); int _arrivals[] = 
	{0,10,12,16,18,26}
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A2.push_back( arrivals ); int _departures[] = 
	{10,20,18,26,36,28}
	; vi departures(_departures, _departures + (sizeof(_departures) / sizeof(_departures[0]))); A3.push_back( departures ); int result = 
	8
	; A4.push_back( result );  }
	{ /*Test 2*/int _tables[] = 
	{4,8}
	; vi tables(_tables, _tables + (sizeof(_tables) / sizeof(_tables[0]))); A0.push_back( tables ); int _groupSizes[] = 
	{4,8,4,2,2,4}
	; vi groupSizes(_groupSizes, _groupSizes + (sizeof(_groupSizes) / sizeof(_groupSizes[0]))); A1.push_back( groupSizes ); int _arrivals[] = 
	{0,10,12,16,18,26}
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A2.push_back( arrivals ); int _departures[] = 
	{10,20,18,26,36,28}
	; vi departures(_departures, _departures + (sizeof(_departures) / sizeof(_departures[0]))); A3.push_back( departures ); int result = 
	2
	; A4.push_back( result );  }
	{ /*Test 3*/int _tables[] = 
	{10,8,11,16}
	; vi tables(_tables, _tables + (sizeof(_tables) / sizeof(_tables[0]))); A0.push_back( tables ); int _groupSizes[] = 
	{14,1,15,1,19,15,9,15,20,2}
	; vi groupSizes(_groupSizes, _groupSizes + (sizeof(_groupSizes) / sizeof(_groupSizes[0]))); A1.push_back( groupSizes ); int _arrivals[] = 
	{4,5,7,18,21,25,29,31,46,49}
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A2.push_back( arrivals ); int _departures[] = 
	{8,37,11,36,36,46,40,42,47,50}
	; vi departures(_departures, _departures + (sizeof(_departures) / sizeof(_departures[0]))); A3.push_back( departures ); int result = 
	69
	; A4.push_back( result );  }
	{ /*Test 4*/int _tables[] = 
	{18,15,2,6}
	; vi tables(_tables, _tables + (sizeof(_tables) / sizeof(_tables[0]))); A0.push_back( tables ); int _groupSizes[] = 
	{7,9,16,3,10,3,2,10,16,16}
	; vi groupSizes(_groupSizes, _groupSizes + (sizeof(_groupSizes) / sizeof(_groupSizes[0]))); A1.push_back( groupSizes ); int _arrivals[] = 
	{10,15,19,20,21,22,27,35,37,43}
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A2.push_back( arrivals ); int _departures[] = 
	{13,24,22,32,32,32,35,48,41,44}
	; vi departures(_departures, _departures + (sizeof(_departures) / sizeof(_departures[0]))); A3.push_back( departures ); int result = 
	10
	; A4.push_back( result );  }
	{ /*Test 5*/int _tables[] = 
	{13,9,6,1,9,8,6,2,8,20}
	; vi tables(_tables, _tables + (sizeof(_tables) / sizeof(_tables[0]))); A0.push_back( tables ); int _groupSizes[] = 
	{20,10,11,10,1,5,16,2,9,17}
	; vi groupSizes(_groupSizes, _groupSizes + (sizeof(_groupSizes) / sizeof(_groupSizes[0]))); A1.push_back( groupSizes ); int _arrivals[] = 
	{12,14,64,78,100,121,151,155,162,164}
	; vi arrivals(_arrivals, _arrivals + (sizeof(_arrivals) / sizeof(_arrivals[0]))); A2.push_back( arrivals ); int _departures[] = 
	{19,26,159,96,155,134,169,199,169,174}
	; vi departures(_departures, _departures + (sizeof(_departures) / sizeof(_departures[0]))); A3.push_back( departures ); int result = 
	17
	; A4.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A4[i], allocateTables( A0[i], A1[i], A2[i], A3[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RestaurantManager ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
