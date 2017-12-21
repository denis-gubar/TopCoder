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
#define all(v) (v).begin(), (v).end()
struct NumberSplit
{
	int longestSequence( int start )
	{
        vi A( start + 1 );
        A[start] = 1;
        queue<int> q;
        q.push( start ); q.push( 1 );
        while( !q.empty() )
        {
            start = q.front(); q.pop();
    		int result = q.front(); q.pop();
            if ( start > 9 )
            {
                vi B;                
                for( int k = start; k > 0; k /= 10 )
                    B.push_back( k % 10 );
                reverse( all(B) );
                int n = B.size() - 1;
                for( int k = 1; k < (1 << n); ++k )
                {
                    int p = 1, a = B[0];
                    for( int i = 0; i < n; ++i )
                        if ( k & (1 << i) )
                        {
                            p *= a;
                            a = B[i + 1];
                        }
                        else
                        {
                            a = a * 10 + B[i + 1];
                        }
                    p *= a;
                    if ( result >= A[p] )
                    {
                        A[p] = result + 1;
                        q.push( p ); q.push( result + 1 );
                    }
                }
            }
        }
		return *max_element( all(A) );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1;
	{ /*Test 0*/int start = 
	6
	; A0.push_back( start ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 1*/int start = 
	97
	; A0.push_back( start ); int result = 
	4
	; A1.push_back( result );  }
	{ /*Test 2*/int start = 
	234
	; A0.push_back( start ); int result = 
	5
	; A1.push_back( result );  }
	{ /*Test 3*/int start = 
	876
	; A0.push_back( start ); int result = 
	7
	; A1.push_back( result );  }
	{ /*Test 4*/int start = 
	99999
	; A0.push_back( start ); int result = 
	29
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], longestSequence( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NumberSplit ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
