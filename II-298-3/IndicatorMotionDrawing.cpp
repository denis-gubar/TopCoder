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
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
struct IndicatorMotionDrawing
{
    int m, n, k;
    int setBit( int x, int y )
    {
        return x | (1 << y);
    }
    int clearBit( int x, int y )
    {
        return (x | (1 << y)) - (1 << y);
    }
    int hash( int x, int y, int s, int state )
    {
        return (x * n + y) * 4 * k + s * k + state;
    }
	int getMinSteps( vs desiredState, char startState )
	{
        string states( "\\/-|" );
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        m = desiredState.size(), n = desiredState[0].size(), k = 1 << (m * n);
        int x, y, s = states.find( startState );
        vi M( m * n * 4 * k );
        if ( desiredState[0][0] == ' ' )
            return -1;
        int state = desiredState[0][0] == startState;
        fora2(i, j, desiredState)
            if ( i + j && desiredState[i][j] == ' ' )
                state = setBit( state, i * n + j );
        M[hash(0, 0, s, state)] = 1;
        queue<int> q; q.push( 0 ); q.push( 0 ); q.push( s ); q.push( state ); q.push( 0 );
        while( !q.empty() )
        {
            int nx = x = q.front(); q.pop();
            int ny = y = q.front(); q.pop();
            int ns = s = q.front(); q.pop();
            int nstate = state = q.front(); q.pop();
            int result = q.front(); q.pop();
            if ( (state & (k - 1)) == k - 1 )
                return result;
            for( ns = 0; ns < 4; ++ns )
            {
                if ( states[ns] == desiredState[nx][ny] )
                    nstate = setBit( state, nx * n + ny );
                else
                    nstate = clearBit( state, nx * n + ny );
                int h = hash( nx, ny, ns, nstate );
                if ( !M[h] )
                {
                    M[h] = 1;
                    q.push( nx ); q.push( ny ); q.push( ns );
                    q.push( nstate ); q.push( result + 1 );
                }
            }
            ns = s;
            for( int t = 0; t < 4; ++t )
            {
                nx = x + dx[t]; ny = y + dy[t];
                if ( nx >= 0 && nx < m && ny >= 0 && ny < n )
                {
                    if ( states[ns] == desiredState[nx][ny] )
                        nstate = setBit( state, nx * n + ny );
                    else
                        nstate = clearBit( state, nx * n + ny );
                    int h = hash( nx, ny, ns, nstate );
                    if ( !M[h] )
                    {
                        M[h] = 1;
                        q.push( nx ); q.push( ny ); q.push( ns );
                        q.push( nstate ); q.push( result + 1 );
                    }
                }
            }
        }
		return -1;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<char> A1; vector<int> A2;
	{ /*Test 0*/string _desiredState[] = 
	{"///",
 "///",
 "---"}
	; vs desiredState(_desiredState, _desiredState + (sizeof(_desiredState) / sizeof(_desiredState[0]))); A0.push_back( desiredState ); char startState = 
	'-'
	; A1.push_back( startState ); int result = 
	10
	; A2.push_back( result );  }
	{ /*Test 1*/string _desiredState[] = 
	{" ||",
 "|||",
 "|||"}
	; vs desiredState(_desiredState, _desiredState + (sizeof(_desiredState) / sizeof(_desiredState[0]))); A0.push_back( desiredState ); char startState = 
	'|'
	; A1.push_back( startState ); int result = 
	-1
	; A2.push_back( result );  }
	{ /*Test 2*/string _desiredState[] = 
	{"/- ",
 "/  ",
 "/--"}
	; vs desiredState(_desiredState, _desiredState + (sizeof(_desiredState) / sizeof(_desiredState[0]))); A0.push_back( desiredState ); char startState = 
	'/'
	; A1.push_back( startState ); int result = 
	9
	; A2.push_back( result );  }
	{ /*Test 3*/string _desiredState[] = 
	{"/-|/",
 "/ |/",
 "-/\\/"}
	; vs desiredState(_desiredState, _desiredState + (sizeof(_desiredState) / sizeof(_desiredState[0]))); A0.push_back( desiredState ); char startState = 
	'\\'
	; A1.push_back( startState ); int result = 
	18
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], getMinSteps( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	IndicatorMotionDrawing ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
