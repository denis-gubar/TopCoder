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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct ChessTournament
{
	struct comp: binary_function<int, int, bool>
	{
		comp( vi score, vi rating, vi result ): score(score), rating(rating), result(result) {}
		bool operator() ( int a, int b ) const
		{
			if ( result[a] >= 0 ) return false;
			if ( result[b] >= 0 ) return true;
			if ( score[a] != score[b] ) return score[a] > score[b];
			return rating[a] > rating[b];
		}
		vi score, rating, result;
	};
	vi nextRound( vi score, vi rating )
	{
		int n = score.size();
		vi result(n, -1), a;
		int x = n;
		fora(i, score)
			a.push_back( i );
		while( x )
		{
			sort( all(a), comp( score, rating, result ) );
			int i = 0;
			while( i < n && (score[a[i]] == score[a[0]] || i % 2)  ) ++i;
			for( int j = 0; j < i / 2; ++j )
			{
				result[a[j]] = a[j + i / 2];
				result[a[j + i / 2]] = a[j];
				x -= 2;
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
	void run_test( int Case = -1 ) { vector<vi> A0; vector<vi> A1; vector<vi> A2;
	{ /*Test 0*/int _Arg0[] = 
	{0,2,4,3,3,2,4,3,0,3}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1923,1882,2103,2210,2027,1988,2320,2294,1736,1864}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{ 8,  5,  6,  9,  7,  1,  2,  4,  0,  3 }
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 1*/int _Arg0[] = 
	{1,2,3,4,1,2,3,4,1,2,3,4,2,3}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010,2011,2012,1999}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{ 4,  9,  12,  11,  0,  8,  13,  10,  5,  1,  7,  3,  2,  6 }
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	{ /*Test 2*/int _Arg0[] = 
	{0,1000}
	; vi Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); int _Arg1[] = 
	{1500,3000}
	; vi Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); int _Arg2[] = 
	{ 1,  0 }
	; vi Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], nextRound( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ChessTournament ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
