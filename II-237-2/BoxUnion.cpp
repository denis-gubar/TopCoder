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
struct BoxUnion
{
	int square( vi a )
	{
		if ( a[0] > a[2] || a[1] > a[3] ) return 0;
		return (a[2] - a[0]) * (a[3] - a[1]);
	}
	vi intersect( vi a, vi b )
	{
		vi result(a.size());
		result[0] = max( a[0], b[0] );		
		result[1] = max( a[1], b[1] );		
		result[2] = min( a[2], b[2] );		
		result[3] = min( a[3], b[3] );
		return result;
	}
	int area( vs rectangles )
	{
		int result = 0;
		vvi z;
		fora(i, rectangles)
			z.push_back(Split<int>( rectangles[i] ));
		fora(i, z)
			result += square( z[i] );
		fora(i, z)
			for( int j = i + 1; j < z.size(); ++j )
				result -= square( intersect( z[i], z[j] ) );
		if ( z.size() == 3 )
			result += square( intersect( z[0], intersect( z[1], z[2] ) ) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<int> A1;
	{ /*Test 0*/string _rectangles[] = 
	{ "200 300 203 304" }
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int result = 
	12
	; A1.push_back( result );  }
	{ /*Test 1*/string _rectangles[] = 
	{ "0 0 10 10",
  "20 20 30 30" }
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int result = 
	200
	; A1.push_back( result );  }
	{ /*Test 2*/string _rectangles[] = 
	{ "0 500 20000 501",
  "500 0 501 20000" }
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int result = 
	39999
	; A1.push_back( result );  }
	{ /*Test 3*/string _rectangles[] = 
	{ "4 6 18 24",
  "7 2 12 19",
  "0 0 100 100" }
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int result = 
	10000
	; A1.push_back( result );  }
	{ /*Test 4*/string _rectangles[] = 
	{ "1 3 5 6",
  "3 1 7 5",
  "4 4 9 7" }
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int result = 
	35
	; A1.push_back( result );  }
	{ /*Test 5*/string _rectangles[] = 
	{ "0 0 20000 20000",
  "0 0 20000 20000",
  "0 0 20000 20000" }
	; vs rectangles(_rectangles, _rectangles + (sizeof(_rectangles) / sizeof(_rectangles[0]))); A0.push_back( rectangles ); int result = 
	400000000
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], area( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BoxUnion ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
