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
struct StrangeParticles
{
	int remain( vs interacts )
	{
		int k = 0;
        vi A( interacts.size() );
        fora(i, A)
            if ( !A[i] )
            {
                A[i] = ++k;
                queue<int> q; q.push( i );
                while( !q.empty() )
                {
                    int z = q.front(); q.pop();
                    fora(j, A)
                        if ( interacts[z][j] == '-' && A[j] != k )
                        {
                            A[j] = k;
                            q.push( j );
                        }
                }
            }
        sort( all(A) );
		return distance( A.begin(), unique( all(A) ) );
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
	{ /*Test 0*/string _interacts[] = 
	{"0+-","-0+","+-0"}
	; vs interacts(_interacts, _interacts + (sizeof(_interacts) / sizeof(_interacts[0]))); A0.push_back( interacts ); int result = 
	1
	; A1.push_back( result );  }
	{ /*Test 1*/string _interacts[] = 
	{"000","000","000"}
	; vs interacts(_interacts, _interacts + (sizeof(_interacts) / sizeof(_interacts[0]))); A0.push_back( interacts ); int result = 
	3
	; A1.push_back( result );  }
	{ /*Test 2*/string _interacts[] = 
	{"0++++++++++++++",
 "-0+++++++++++++",
 "--0++++++++++++",
 "---0+++++++++++",
 "----0++++++++++",
 "-----0+++++++++",
 "------0++++++++",
 "-------0+++++++",
 "--------0++++++",
 "---------0+++++",
 "----------0++++",
 "-----------0+++",
 "------------0++",
 "-------------0+",
 "--------------0"}
	; vs interacts(_interacts, _interacts + (sizeof(_interacts) / sizeof(_interacts[0]))); A0.push_back( interacts ); int result = 
	1
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], remain( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	StrangeParticles ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
