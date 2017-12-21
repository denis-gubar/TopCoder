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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct ATaleOfThreeCities
{
	int distance( int x1, int y1, int x2, int y2 )
	{
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
	double connect( vi ax, vi ay, vi bx, vi by, vi cx, vi cy )
	{
		vi A, B, C, D;
		fora(i, ax)
			fora(j, bx)
				A.push_back( distance( ax[i], ay[i], bx[j], by[j] ) );
		fora(i, ax)
			fora(j, cx)
				B.push_back( distance( ax[i], ay[i], cx[j], cy[j] ) );
		fora(i, bx)
			fora(j, cx)
				C.push_back( distance( bx[i], by[i], cx[j], cy[j] ) );
		D.push_back( *min_element( all(A) ) );
		D.push_back( *min_element( all(B) ) );
		D.push_back( *min_element( all(C) ) );
		sort( all(D) );
		return sqrt(1.0 * D[0]) + sqrt(1.0 * D[1]);
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<vi> A3; vector<vi> A4; vector<vi> A5; vector<double> A6;
	{ /*Test 0*/int _ax[] = 
	{0,0,0}
	; vi ax(_ax, _ax + (sizeof(_ax) / sizeof(_ax[0]))); A0.push_back( ax ); int _ay[] = 
	{0,1,2}
	; vi ay(_ay, _ay + (sizeof(_ay) / sizeof(_ay[0]))); A1.push_back( ay ); int _bx[] = 
	{2,3}
	; vi bx(_bx, _bx + (sizeof(_bx) / sizeof(_bx[0]))); A2.push_back( bx ); int _by[] = 
	{1,1}
	; vi by(_by, _by + (sizeof(_by) / sizeof(_by[0]))); A3.push_back( by ); int _cx[] = 
	{1,5}
	; vi cx(_cx, _cx + (sizeof(_cx) / sizeof(_cx[0]))); A4.push_back( cx ); int _cy[] = 
	{3,28}
	; vi cy(_cy, _cy + (sizeof(_cy) / sizeof(_cy[0]))); A5.push_back( cy ); double result = 
	3.414213562373095
	; A6.push_back( result );  }
	{ /*Test 1*/int _ax[] = 
	{-2,-1,0,1,2}
	; vi ax(_ax, _ax + (sizeof(_ax) / sizeof(_ax[0]))); A0.push_back( ax ); int _ay[] = 
	{0,0,0,0,0}
	; vi ay(_ay, _ay + (sizeof(_ay) / sizeof(_ay[0]))); A1.push_back( ay ); int _bx[] = 
	{-2,-1,0,1,2}
	; vi bx(_bx, _bx + (sizeof(_bx) / sizeof(_bx[0]))); A2.push_back( bx ); int _by[] = 
	{1,1,1,1,1}
	; vi by(_by, _by + (sizeof(_by) / sizeof(_by[0]))); A3.push_back( by ); int _cx[] = 
	{-2,-1,0,1,2}
	; vi cx(_cx, _cx + (sizeof(_cx) / sizeof(_cx[0]))); A4.push_back( cx ); int _cy[] = 
	{2,2,2,2,2}
	; vi cy(_cy, _cy + (sizeof(_cy) / sizeof(_cy[0]))); A5.push_back( cy ); double result = 
	2.0
	; A6.push_back( result );  }
	{ /*Test 2*/int _ax[] = 
	{4,5,11,21,8,10,3,9,5,6}
	; vi ax(_ax, _ax + (sizeof(_ax) / sizeof(_ax[0]))); A0.push_back( ax ); int _ay[] = 
	{12,8,9,12,2,3,5,7,10,13}
	; vi ay(_ay, _ay + (sizeof(_ay) / sizeof(_ay[0]))); A1.push_back( ay ); int _bx[] = 
	{34,35,36,41,32,39,41,37,39,50}
	; vi bx(_bx, _bx + (sizeof(_bx) / sizeof(_bx[0]))); A2.push_back( bx ); int _by[] = 
	{51,33,41,45,48,22,33,51,41,40}
	; vi by(_by, _by + (sizeof(_by) / sizeof(_by[0]))); A3.push_back( by ); int _cx[] = 
	{86,75,78,81,89,77,83,88,99,77}
	; vi cx(_cx, _cx + (sizeof(_cx) / sizeof(_cx[0]))); A4.push_back( cx ); int _cy[] = 
	{10,20,30,40,50,60,70,80,90,100}
	; vi cy(_cy, _cy + (sizeof(_cy) / sizeof(_cy[0]))); A5.push_back( cy ); double result = 
	50.323397776611024
	; A6.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A6[i], connect( A0[i], A1[i], A2[i], A3[i], A4[i], A5[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ATaleOfThreeCities ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
