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
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
struct ImageTraders
{
	int maxOwners( vs price )
	{
		int result = 1, n = price.size();
        vvi M(1 << n, vi(n, 100));
        M[1][0] = '0';
        queue<int> q; q.push( 1 ); q.push( 1 ); q.push( 0 );
        while( !q.empty() )
        {
            int t = q.front(); q.pop();
            if ( t > result )
                result = t;
            int state = q.front(); q.pop();
            int last = q.front(); q.pop();
            fora(i, price)
            {
                int newstate = state | (1 << i);
                if ( newstate != state && price[last][i] >= M[state][last] && M[newstate][i] > price[last][i] )
                {
                    M[newstate][i] = price[last][i]; q.push( t + 1 ); q.push( newstate ); q.push( i );
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
	{ /*Test 0*/string _price[] = 
	{
"01",
"10"
}
	; vs price(_price, _price + (sizeof(_price) / sizeof(_price[0]))); A0.push_back( price ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 1*/string _price[] = 
	{
"022",
"101",
"110"
}
	; vs price(_price, _price + (sizeof(_price) / sizeof(_price[0]))); A0.push_back( price ); int result = 
	2
	; A1.push_back( result );  }
	{ /*Test 2*/string _price[] = 
	{
"01231",
"00231",
"00031",
"00002",
"00000"
}
	; vs price(_price, _price + (sizeof(_price) / sizeof(_price[0]))); A0.push_back( price ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 3*/string _price[] = 
	{
"15555",
"11111",
"15111",
"11111",
"11111"
}
	; vs price(_price, _price + (sizeof(_price) / sizeof(_price[0]))); A0.push_back( price ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 4*/string _price[] = 
	{
"0100000000",
"0020000000",
"0003000000",
"0000400000",
"0000050000",
"0000006000",
"0000000700",
"0000000080",
"0000000009",
"1111111111"
}
	; vs price(_price, _price + (sizeof(_price) / sizeof(_price[0]))); A0.push_back( price ); int result = 
	10
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], maxOwners( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ImageTraders ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
