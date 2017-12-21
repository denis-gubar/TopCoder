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
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE
typedef long long lint;
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
struct PlayGame
{
	int saveCreatures( vi you, vi computer )
	{
		sort( all(you), greater<int>() );
		sort( all(computer), greater<int>() );
		int n = you.size();
		int result = 0, i = 0, j = 0;
		while( i < n && j < n )
		{					
			if ( you[i] > computer[j] )
			{
				result += you[i]; i++; j++;
			}
			else j++;
		}
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<int> A2;
	{ /*Test 0*/int _Arg0[] = 
	{5, 15, 100, 1, 5}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{5, 15, 100, 1, 5}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	120
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/int _Arg0[] = 
	{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	0
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/int _Arg0[] = 
	{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	99
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/int _Arg0[] = 
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	65
	; A2.push_back( Arg2 );  }
	{ /*Test 4*/int _Arg0[] = 
	{651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
 491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
 7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
 550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
 29, 329, 57, 636, 132, 843, 860, 594, 718, 849}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
 366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
 401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
 311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
 360, 852, 228, 859, 229, 249, 540, 979, 55, 82}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int Arg2 = 
	25084
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], saveCreatures( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PlayGame ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
