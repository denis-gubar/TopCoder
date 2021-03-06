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
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
struct GuessCard
{
	int whichRow( int width, int height, vi columns )
	{
        vvi A(height, vi(width));
        vi D;
        for( int i = 0; i < width * height; ++i )
            D.push_back( i );
        vi B(D);
        fora(t, columns)
        {
            for( int i = 0; i < width * height; ++i )
                A[i / width][i % width] = D[i];
            D.clear();
            for( int j = 0; j < width; ++j )
                for( int i = 0; i < height; ++i )
                     D.push_back( A[i][j] );
            vi Z, C;
            for( int i = 0; i < height; ++i )
                C.push_back( A[i][columns[t]] );
            sort( all(C) );
            set_intersection( all(B), all(C), back_inserter<vi>( Z ) );
            B.swap( Z );
        }
        if ( B.size() > 1 )
            return -1;
        if ( B.size() == 1 )
        {
            int k = 0;
            if ( !columns.empty() )
                k = columns.back();
            for( int i = 0; i < height; ++i )
                if ( A[i][k] == B[0] )
                    return i;
        }
		return -2;
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vi> A2; vector<int> A3;
	{ /*Test 0*/int width = 
	3
	; A0.push_back( width ); int height = 
	7
	; A1.push_back( height ); int _columns[] = 
	{2, 1, 0}
	; vi columns(_columns, _columns + (sizeof(_columns) / sizeof(_columns[0]))); A2.push_back( columns ); int result = 
	4
	; A3.push_back( result );  }
	{ /*Test 1*/int width = 
	3
	; A0.push_back( width ); int height = 
	7
	; A1.push_back( height ); int _columns[] = 
	{2, 1}
	; vi columns(_columns, _columns + (sizeof(_columns) / sizeof(_columns[0]))); A2.push_back( columns ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 2*/int width = 
	1
	; A0.push_back( width ); int height = 
	10
	; A1.push_back( height ); int _columns[] = 
	{0, 0, 0}
	; vi columns(_columns, _columns + (sizeof(_columns) / sizeof(_columns[0]))); A2.push_back( columns ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 3*/int width = 
	10
	; A0.push_back( width ); int height = 
	1
	; A1.push_back( height ); int _columns[] = 
	{4, 4, 4}
	; vi columns(_columns, _columns + (sizeof(_columns) / sizeof(_columns[0]))); A2.push_back( columns ); int result = 
	0
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], whichRow( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	GuessCard ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
