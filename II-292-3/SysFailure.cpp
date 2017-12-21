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
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
#define all(v) (v).begin(), (v).end()
struct SysFailure
{
	int critical( int nn, vs state )
	{
		int result = 0, k = 0;
        int m = state.size(), n = state[0].size();
        vvi M(m, vi(n)), F(M);
        vi A(1);
        fora2(i, j, state)
            if ( state[i][j] == '1' )
            {
                if ( !M[i][j] )
                {
                    M[i][j] = ++k;
                    A.push_back( 1 );
                }
                state[i][j] = '0';
                vvi N(m, vi(n));
                for( int nx = i - 1; nx <= i + 1; ++nx )
                    for( int ny = j - 1; ny <= j + 1; ++ny )
                        if ( nx >= 0 && nx < m && ny >= 0 && ny < n && state[nx][ny] == '1' && !N[nx][ny] )
                        {
                            N[nx][ny] = 1;
                            if ( !M[nx][ny] )
                            {
                                M[nx][ny] = k;
                                ++A[k];
                            }
                            int t = 0;
                            queue<int> q;
                            q.push( nx ); q.push( ny );
                            while( !q.empty() )
                            {
                                ++t;
                                int x = q.front(); q.pop();
                                int y = q.front(); q.pop();
                                for( int sx = x - 1; sx <= x + 1; ++sx )
                                    for( int sy = y - 1; sy <= y + 1; ++sy )
                                        if ( sx >= 0 && sx < m && sy >= 0 && sy < n && state[sx][sy] == '1' && !N[sx][sy] )
                                        {
                                            N[sx][sy] = 1;
                                            if ( !M[sx][sy] )
                                            {
                                                M[sx][sy] = k;
                                                ++A[k];
                                            }
                                            q.push( sx ); q.push( sy );
                                        }
                            }
                            F[i][j] |= (t >= nn);
                        }
                state[i][j] = '1';
            }
        if ( *max_element( all(A) ) < nn )
            return -1;
        fora2(i, j, state)
            if ( state[i][j] == '1' && !F[i][j] )
            {
                int f = 1;
                k = M[i][j];
                fora(z, A)
                    if ( k != z && A[z] >= nn )
                    {
                        f = 0; break;
                    }
                result += f;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<vs> A1; vector<int> A2;
	{ /*Test 0*/int n = 
	4
	; A0.push_back( n ); string _state[] = 
	{ "00000",
  "00000",
  "11111" }
	; vs state(_state, _state + (sizeof(_state) / sizeof(_state[0]))); A1.push_back( state ); int result = 
	3
	; A2.push_back( result );  }
	{ /*Test 1*/int n = 
	6
	; A0.push_back( n ); string _state[] = 
	{ "01010",
  "10001",
  "11011",
  "10001",
  "01010"} 
	; vs state(_state, _state + (sizeof(_state) / sizeof(_state[0]))); A1.push_back( state ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 2*/int n = 
	4
	; A0.push_back( n ); string _state[] = 
	{ "111",
  "111" }
	; vs state(_state, _state + (sizeof(_state) / sizeof(_state[0]))); A1.push_back( state ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 3*/int n = 
	2
	; A0.push_back( n ); string _state[] = 
	{ "101" }
	; vs state(_state, _state + (sizeof(_state) / sizeof(_state[0]))); A1.push_back( state ); int result = 
	-1
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], critical( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SysFailure ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
