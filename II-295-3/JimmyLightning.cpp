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
struct JimmyLightning
{
    struct D
    {
        int V, T, R;
    };
	int robTheBank( vi doors, vs diamonds )
	{
        vi M( doors[0] );
        for( int i = 1; i < doors.size(); ++i )
            doors[i] = min( doors[i], doors[i - 1] );
        vector<D> A( diamonds.size() );
        fora(i, diamonds)
        {
            istringstream s( diamonds[i] );
            s >> A[i].V >> A[i].T >> A[i].R;
            --A[i].R;
        }
        fora(t, M)
            fora(i, A)
                if ( t + A[i].T < doors[A[i].R] && M[t + A[i].T] < M[t] + A[i].V )
                    M[t + A[i].T] = M[t] + A[i].V;
		return *max_element( all(M) );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vs> A1; vector<int> A2;
	{ /*Test 0*/int _doors[] = 
	{6}
	; vi doors(_doors, _doors + (sizeof(_doors) / sizeof(_doors[0]))); A0.push_back( doors ); string _diamonds[] = 
	{"2 1 1"}
	; vs diamonds(_diamonds, _diamonds + (sizeof(_diamonds) / sizeof(_diamonds[0]))); A1.push_back( diamonds ); int result = 
	10
	; A2.push_back( result );  }
	{ /*Test 1*/int _doors[] = 
	{1}
	; vi doors(_doors, _doors + (sizeof(_doors) / sizeof(_doors[0]))); A0.push_back( doors ); string _diamonds[] = 
	{"999 1 1"}
	; vs diamonds(_diamonds, _diamonds + (sizeof(_diamonds) / sizeof(_diamonds[0]))); A1.push_back( diamonds ); int result = 
	0
	; A2.push_back( result );  }
	{ /*Test 2*/int _doors[] = 
	{10, 5, 2}
	; vi doors(_doors, _doors + (sizeof(_doors) / sizeof(_doors[0]))); A0.push_back( doors ); string _diamonds[] = 
	{"1 1 1",
 "2 1 2",
 "3 1 3"}
	; vs diamonds(_diamonds, _diamonds + (sizeof(_diamonds) / sizeof(_diamonds[0]))); A1.push_back( diamonds ); int result = 
	14
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], robTheBank( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	JimmyLightning ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
