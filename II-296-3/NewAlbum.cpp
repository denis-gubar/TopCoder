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
struct NewAlbum
{
	int leastAmountOfCDs( int nSongs, int length, int cdCapacity )
	{
        vi M( 101, 101 );
        M[0] = 0;
        int k = (cdCapacity + 1) / (length + 1);
        for( int i = 1; i < 101; ++i )
            for( int j = 1; i >= j && j <= k; ++j )
                if ( (j % 13) && M[i - j] + 1 < M[i] )
                    M[i] = M[i - j] + 1;
		return M[nSongs];
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int nSongs = 
	7
	; A0.push_back( nSongs ); int length = 
	2
	; A1.push_back( length ); int cdCapacity = 
	6
	; A2.push_back( cdCapacity ); int result = 
	4
	; A3.push_back( result );  }
	{ /*Test 1*/int nSongs = 
	20
	; A0.push_back( nSongs ); int length = 
	1
	; A1.push_back( length ); int cdCapacity = 
	100
	; A2.push_back( cdCapacity ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 2*/int nSongs = 
	26
	; A0.push_back( nSongs ); int length = 
	1
	; A1.push_back( length ); int cdCapacity = 
	100
	; A2.push_back( cdCapacity ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 3*/int nSongs = 
	26
	; A0.push_back( nSongs ); int length = 
	3
	; A1.push_back( length ); int cdCapacity = 
	51
	; A2.push_back( cdCapacity ); int result = 
	3
	; A3.push_back( result );  }
	{ /*Test 4*/int nSongs = 
	67
	; A0.push_back( nSongs ); int length = 
	271
	; A1.push_back( length ); int cdCapacity = 
	1000
	; A2.push_back( cdCapacity ); int result = 
	23
	; A3.push_back( result );  }
	{ /*Test 5*/int nSongs = 
	27
	; A0.push_back( nSongs ); int length = 
	1
	; A1.push_back( length ); int cdCapacity = 
	27
	; A2.push_back( cdCapacity ); int result = 
	3
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], leastAmountOfCDs( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	NewAlbum ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
