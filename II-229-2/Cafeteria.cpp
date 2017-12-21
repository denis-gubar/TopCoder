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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
struct Cafeteria
{
	string latestTime( vi offset, vi walkingTime, vi drivingTime )
	{
		vi A;
		fora(i, offset)
			for( int j = 0; j < 1000; j += 10 )
			{
				int k = j + offset[i];
				if ( k + drivingTime[i] <= 14 * 60 + 30 )
					A.push_back( k - walkingTime[i] );
			}
		int best = *max_element( all(A) );
		int h = best / 60, m = best % 60;
		if ( h > 12 ) h -= 12;
		return ToString( h + 100 ).substr( 1 ) + ":" + ToString( m + 100 ).substr( 1 );
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2; vector<string> A3;
	{ /*Test 0*/int _offset[] = 
	{9}
	; vi offset(_offset, _offset + (sizeof(_offset) / sizeof(_offset[0]))); A0.push_back( offset ); int _walkingTime[] = 
	{1}
	; vi walkingTime(_walkingTime, _walkingTime + (sizeof(_walkingTime) / sizeof(_walkingTime[0]))); A1.push_back( walkingTime ); int _drivingTime[] = 
	{1}
	; vi drivingTime(_drivingTime, _drivingTime + (sizeof(_drivingTime) / sizeof(_drivingTime[0]))); A2.push_back( drivingTime ); string result = 
	"02:28"
	; A3.push_back( result );  }
	{ /*Test 1*/int _offset[] = 
	{6}
	; vi offset(_offset, _offset + (sizeof(_offset) / sizeof(_offset[0]))); A0.push_back( offset ); int _walkingTime[] = 
	{9}
	; vi walkingTime(_walkingTime, _walkingTime + (sizeof(_walkingTime) / sizeof(_walkingTime[0]))); A1.push_back( walkingTime ); int _drivingTime[] = 
	{120}
	; vi drivingTime(_drivingTime, _drivingTime + (sizeof(_drivingTime) / sizeof(_drivingTime[0]))); A2.push_back( drivingTime ); string result = 
	"12:17"
	; A3.push_back( result );  }
	{ /*Test 2*/int _offset[] = 
	{6,9}
	; vi offset(_offset, _offset + (sizeof(_offset) / sizeof(_offset[0]))); A0.push_back( offset ); int _walkingTime[] = 
	{9,10}
	; vi walkingTime(_walkingTime, _walkingTime + (sizeof(_walkingTime) / sizeof(_walkingTime[0]))); A1.push_back( walkingTime ); int _drivingTime[] = 
	{120,121}
	; vi drivingTime(_drivingTime, _drivingTime + (sizeof(_drivingTime) / sizeof(_drivingTime[0]))); A2.push_back( drivingTime ); string result = 
	"12:19"
	; A3.push_back( result );  }
	{ /*Test 3*/int _offset[] = 
	{0,1,2,3,4,5,6,7,8,9}
	; vi offset(_offset, _offset + (sizeof(_offset) / sizeof(_offset[0]))); A0.push_back( offset ); int _walkingTime[] = 
	{11,11,11,11,11,11,11,11,11,11}
	; vi walkingTime(_walkingTime, _walkingTime + (sizeof(_walkingTime) / sizeof(_walkingTime[0]))); A1.push_back( walkingTime ); int _drivingTime[] = 
	{190,190,190,190,190,190,190,190,190,190}
	; vi drivingTime(_drivingTime, _drivingTime + (sizeof(_drivingTime) / sizeof(_drivingTime[0]))); A2.push_back( drivingTime ); string result = 
	"11:09"
	; A3.push_back( result );  }
	{ /*Test 4*/int _offset[] = 
	{7,4,0,0,2,1,6,7,7,0,8,6,0,5,0,6,7,9,0,2,4,8,4,7,
9,2,4,4,3,1,4,5,8,8,2,5,7,8,7,5,6,8,8,0,1,3,5,0,8}
	; vi offset(_offset, _offset + (sizeof(_offset) / sizeof(_offset[0]))); A0.push_back( offset ); int _walkingTime[] = 
	{26,14,1,4,16,28,16,6,4,5,21,18,5,2,21,21,28,22,5,22,26,16,14,
19,19,19,4,12,24,4,30,16,28,20,25,2,30,18,4,6,9,22,8,3,7,29,8,30,6}
	; vi walkingTime(_walkingTime, _walkingTime + (sizeof(_walkingTime) / sizeof(_walkingTime[0]))); A1.push_back( walkingTime ); int _drivingTime[] = 
	{151,264,280,89,63,57,15,120,28,296,76,269,90,106,31,222,
291,52,102,73,140,248,44,187,76,49,296,106,54,119,54,283,263,
285,275,127,108,82,84,241,169,203,244,256,109,288,9,262,103}
	; vi drivingTime(_drivingTime, _drivingTime + (sizeof(_drivingTime) / sizeof(_drivingTime[0]))); A2.push_back( drivingTime ); string result = 
	"02:07"
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], latestTime( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Cafeteria ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
