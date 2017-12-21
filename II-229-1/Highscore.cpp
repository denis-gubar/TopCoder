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
struct Highscore
{
	int getRank( vi scores, int newscore, int places )
	{
		int result = 1;
		for( int i = scores.size(); i < places; ++i )
			scores.push_back( -1 );
		sort( all(scores), greater<int>() );
		if ( newscore <= scores[places - 1] )
			return -1;
		fora(i, scores)
			if ( scores[i] > newscore )
				++result;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int _scores[] = 
	{100,90,80}
	; vi scores(_scores, _scores + (sizeof(_scores) / sizeof(_scores[0]))); A0.push_back( scores ); int newscore = 
	90
	; A1.push_back( newscore ); int places = 
	10
	; A2.push_back( places ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 1*/vi scores; A0.push_back( scores ); int newscore = 
	0
	; A1.push_back( newscore ); int places = 
	50
	; A2.push_back( places ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 2*/int _scores[] = 
	{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	; vi scores(_scores, _scores + (sizeof(_scores) / sizeof(_scores[0]))); A0.push_back( scores ); int newscore = 
	1
	; A1.push_back( newscore ); int places = 
	10
	; A2.push_back( places ); int result = 
	-1
	; A3.push_back( result );  }
	{ /*Test 3*/int _scores[] = 
	{10, 9, 8, 7, 6, 5, 4, 3, 3, 0}
	; vi scores(_scores, _scores + (sizeof(_scores) / sizeof(_scores[0]))); A0.push_back( scores ); int newscore = 
	1
	; A1.push_back( newscore ); int places = 
	10
	; A2.push_back( places ); int result = 
	10
	; A3.push_back( result );  }
	{ /*Test 4*/int _scores[] = 
	{2000000000, 19539, 19466, 19146, 17441, 17002, 16348, 16343,
15981, 15346, 14748, 14594, 13752, 13684, 13336, 13290, 12939,
12208, 12163, 12133, 11621, 11119, 10872, 10710, 10390, 9934,
9296, 8844, 8662, 8653, 8168, 7914, 7529, 7354, 6016, 5428,
5302, 5158, 4853, 4538, 4328, 3443, 3222, 2107, 2107, 1337,
951, 586, 424, 31}
	; vi scores(_scores, _scores + (sizeof(_scores) / sizeof(_scores[0]))); A0.push_back( scores ); int newscore = 
	1337
	; A1.push_back( newscore ); int places = 
	50
	; A2.push_back( places ); int result = 
	46
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], getRank( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Highscore ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
