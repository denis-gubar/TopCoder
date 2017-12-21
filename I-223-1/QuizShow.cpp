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
struct QuizShow
{
	bool calc( int x, int y, int z )
	{
		return x > max(y, z);
	}
	int wager( vi scores, int wager1, int wager2 )
	{
		int result, best = -1;
		for( int i = 0; i <= scores[0]; i++ )
		{
			int p = 0;
			p += calc( scores[0] - i, scores[1] - wager1, scores[2] - wager2 );
			p += calc( scores[0] - i, scores[1] - wager1, scores[2] + wager2 );
			p += calc( scores[0] - i, scores[1] + wager1, scores[2] - wager2 );
			p += calc( scores[0] - i, scores[1] + wager1, scores[2] + wager2 );
			p += calc( scores[0] + i, scores[1] - wager1, scores[2] - wager2 );
			p += calc( scores[0] + i, scores[1] - wager1, scores[2] + wager2 );
			p += calc( scores[0] + i, scores[1] + wager1, scores[2] - wager2 );
			p += calc( scores[0] + i, scores[1] + wager1, scores[2] + wager2 );
			if ( best < p )
			{
				best = p; result = i;
			}
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/int _Arg0[] = 
	{ 100, 100, 100 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	25
	; A1.push_back( Arg1 ); int Arg2 = 
	75
	; A2.push_back( Arg2 ); int Arg3 = 
	76
	; A3.push_back( Arg3 );  }
	{ /*Test 1*/int _Arg0[] = 
	{ 10, 50, 60 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	30
	; A1.push_back( Arg1 ); int Arg2 = 
	41
	; A2.push_back( Arg2 ); int Arg3 = 
	0
	; A3.push_back( Arg3 );  }
	{ /*Test 2*/int _Arg0[] = 
	{ 10, 50, 60 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	31
	; A1.push_back( Arg1 ); int Arg2 = 
	41
	; A2.push_back( Arg2 ); int Arg3 = 
	10
	; A3.push_back( Arg3 );  }
	{ /*Test 3*/int _Arg0[] = 
	{ 2, 2, 12 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	0
	; A1.push_back( Arg1 ); int Arg2 = 
	10
	; A2.push_back( Arg2 ); int Arg3 = 
	1
	; A3.push_back( Arg3 );  }
	{ /*Test 4*/int _Arg0[] = 
	{ 10000, 10000, 10000 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	9998
	; A1.push_back( Arg1 ); int Arg2 = 
	9997
	; A2.push_back( Arg2 ); int Arg3 = 
	9999
	; A3.push_back( Arg3 );  }
	{ /*Test 5*/int _Arg0[] = 
	{ 5824, 4952, 6230 }
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int Arg1 = 
	364
	; A1.push_back( Arg1 ); int Arg2 = 
	287
	; A2.push_back( Arg2 ); int Arg3 = 
	694
	; A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], wager( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	QuizShow ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
