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
typedef long long lint;
typedef vector<lint> vl;
typedef vector<string> vs;
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
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
struct Removal
{
	int finalPos( int n, int k, vs remove )
	{
		lint result = k;
		forad(i, remove)
		{
			vl z(Split<lint>( remove[i], "-" ));
			if ( z[0] <= result )
				result += z[1] - z[0] + 1;
		}
		return result > n ? -1 : static_cast<int>( result );
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
	void run_test( int Case = -1 ) { vector<int> A0; vector<int> A1; vector<vs> A2; vector<int> A3;
	{ /*Test 0*/int n = 
	8
	; A0.push_back( n ); int k = 
	3
	; A1.push_back( k ); string _remove[] = 
	{"3-4","4-5"}
	; vs remove(_remove, _remove + (sizeof(_remove) / sizeof(_remove[0]))); A2.push_back( remove ); int result = 
	5
	; A3.push_back( result );  }
	{ /*Test 1*/int n = 
	100
	; A0.push_back( n ); int k = 
	13
	; A1.push_back( k ); string _remove[] = 
	{"19-50","19-50","19-19"}
	; vs remove(_remove, _remove + (sizeof(_remove) / sizeof(_remove[0]))); A2.push_back( remove ); int result = 
	13
	; A3.push_back( result );  }
	{ /*Test 2*/int n = 
	100
	; A0.push_back( n ); int k = 
	39
	; A1.push_back( k ); string _remove[] = 
	{"19-50","19-50","19-19"}
	; vs remove(_remove, _remove + (sizeof(_remove) / sizeof(_remove[0]))); A2.push_back( remove ); int result = 
	-1
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], finalPos( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Removal ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
