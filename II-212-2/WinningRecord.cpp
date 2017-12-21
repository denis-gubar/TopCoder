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
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
typedef vector<int> vi;
struct WinningRecord
{
	vi getBestAndWorst( string games )
	{
		vi result(2, 0);
		pair<int, int> best = make_pair( -1, 0 ), worst = make_pair( -1, 2 );
		int n = games.size();
		for( int i = n; i >= 3; i-- )
		{
			int count = 0;
			for( int j = 0; j < i; j++ )
				if ( games[j] == 'W' ) count++;
			if ( best.first == -1 || best.second * i < best.first * count )
				best = make_pair( i, count );
			if ( worst.first == -1 || worst.second * i > worst.first * count  )
				worst = make_pair( i, count );
		}
		result[0] = best.first; result[1] = worst.first;
		return result;
	}
	// BEGIN CUT HERE
	private:
	template <typename T> string print_array( const vector<T>& v ) { ostringstream os; os << "{ "; for( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it ) os << '\"' << *it << "\","; os << " }"; return os.str(); }
	template<typename T> void verify_case( int Case, const vector<T>& expected, const vector<T>& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: " << print_array( expected ) << endl; cerr << "\tReceived: " << print_array( received ) << endl; } }
	void verify_case( int Case, const lint& expected, const lint& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const double& expected, const double& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const int& expected, const int& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	void verify_case( int Case, const string& expected, const string& received ) { cerr << "Test Case #" << Case << "..."; if ( expected == received ) cerr << "PASSED. "; else { cerr << "FAILED." << endl; cerr << "\tExpected: \"" << expected << '\"' << endl; cerr << "\tReceived: \"" << received << '\"' << endl; } }
	public:
	void run_test( int Case = - 1 ) { vector<string> A0; vector<vi> A1;
	{ /*Test 0*/string Arg0 = 
	"WWWWWLLLLLLLLLLLLLLL"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 5,  20 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 1*/string Arg0 = 
	"WWWWWW"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 6,  6 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 2*/string Arg0 = 
	"LWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLW"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 50,  3 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 3*/string Arg0 = 
	"WLWLWLLWWLWLWWWWWWWLWLLLLLLLLLLLLWWLWLLWWWLLLWLWLW"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 19,  33 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 4*/string Arg0 = 
	"LWWLWWLWWLLLW"
	; A0.push_back( Arg0 ); int _Arg1[] = 
	{ 9,  12 }
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], getBestAndWorst( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	WinningRecord ___test;
	___test.run_test();
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
