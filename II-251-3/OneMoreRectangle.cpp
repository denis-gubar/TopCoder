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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename T, typename Predicate> vector<T> Parse( string s, Predicate predicate )
{
	vector<T> result; bool isWord = false; int j = 0;
	for( int i = 0; i < s.size(); i++ )
		if ( isWord )
		{
			if ( !predicate( s[i] ) )
			{
				istringstream S( s.substr( j, i - j ) );
				T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
				isWord = false;
			}
		}
		else
		{
			if ( predicate( s[i] ) )
			{
				j = i; isWord = true;
			}
		}
		if ( isWord )
		{
			istringstream S( s.substr( j ) );
			T current; S >> current; 
			if ( S.rdstate() ^ ios::failbit )
				result.push_back( current );
		}
		return result;
}
struct split_helper: unary_function<int, bool>
{
	explicit split_helper( string delimeter ): delimeter(delimeter) {};
	bool operator() ( int c ) const
	{
		return delimeter.find( c ) == string::npos;
	}
private: string delimeter;
};
template <typename T> vector<T> Split( string s, string delimeter = " " )
{
	return Parse<T>( s, split_helper( delimeter ) );
}
struct OneMoreRectangle
{
	int calc( const vvi& M, int x, int y, int h, int w )
	{
		int result = 0;
		fora(i, M)
			result += (x <= M[i][0] && x + h >= M[i][2] && y <= M[i][1] && y + w >= M[i][3]);
		return result;
	}
	int maxCover( vs rectangles, int qa, int qb )
	{
		vi result;
		result.push_back( 0 );
		vvi M;
		vi X, Y;
		fora(i, rectangles)
		{
			M.push_back( Split<int>( rectangles[i] ) );
			for( int j = -1; j <= 1; ++j )
				for( int k = 0; k <= 2; k += 2 )
			{
				X.push_back( M[i][k] + j * qa );
				X.push_back( M[i][k] + j * qb );
				Y.push_back( M[i][k + 1] + j * qa );
				Y.push_back( M[i][k + 1] + j * qb );				
			}
		}
		sort( all(X) ); sort( all(Y) );
		X.erase( unique( all(X) ), X.end() );
		Y.erase( unique( all(Y) ), Y.end() );
		fora(i, X)
			fora(j, Y)
			{
				result.push_back( calc( M, X[i], Y[j], qa, qb ) );
				result.push_back( calc( M, X[i], Y[j], qb, qa ) );
			}
		return *max_element( all(result) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/string _rectangles[] = 
	{"1 1 2 2","2 2 3 3","3 3 4 4"}
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int qa = 
	2
	; A1.push_back( qa ); int qb = 
	2
	; A2.push_back( qb ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 1*/string _rectangles[] = 
	{"1 1 5 5","1 1 4 2","1 1 2 4", "2 3 5 5"}
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int qa = 
	3
	; A1.push_back( qa ); int qb = 
	3
	; A2.push_back( qb ); int result = 
	2
	; A3.push_back( result );  }
	{ /*Test 2*/string _rectangles[] = 
	{"1 1 4 2","1 2 2 5","4 1 5 4","2 4 5 5"}
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int qa = 
	3
	; A1.push_back( qa ); int qb = 
	3
	; A2.push_back( qb ); int result = 
	1
	; A3.push_back( result );  }
	{ /*Test 3*/string _rectangles[] = 
	{"1 1 4 2","1 2 2 5","4 1 5 4","2 4 5 5"}
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int qa = 
	4
	; A1.push_back( qa ); int qb = 
	4
	; A2.push_back( qb ); int result = 
	4
	; A3.push_back( result );  }
	{ /*Test 4*/string _rectangles[] = 
	{"1 4 6573 345","23 4366 23545 366783","54 7895 2565 23567","3456 345 475457 45767654",
"-234 -654885 0 0","-32654 -43256 -34 -5463","-10000 -10000 10000 10000"}
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int qa = 
	100000
	; A1.push_back( qa ); int qb = 
	100000
	; A2.push_back( qb ); int result = 
	4
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], maxCover( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	OneMoreRectangle ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
