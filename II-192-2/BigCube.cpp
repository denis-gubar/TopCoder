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
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
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
struct BigCube
{
	string largestCube( vs range )
	{
		vl A(100001);
		forad(i, A)
			A[100000 - i] = static_cast<lint>(i) * static_cast<lint>(i) * static_cast<lint>(i);
		lint result = -1;
		forad(i, range)
		{
			vl z( Split<lint>( range[i], "-" ) );
			lint k = *lower_bound( all(A), z[1], greater<lint>() );
			if ( k >= z[0] )
				result = max( result, k );
		}
		if ( result == -1 )
			return "";
		return ToString( result );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1;
	{ /*Test 0*/string _range[] = 
	{"1-1000000000001"}
	; vs range(_range, _range + (sizeof(_range) / sizeof(_range[0]))); A0.push_back( range ); string result = 
	"1000000000000"
	; A1.push_back( result );  }
	{ /*Test 1*/string _range[] = 
	{"10-999999999999990","11-999999999999991","12-999999999999992",
 "13-999999999999993","14-999999999999994","15-999999999999995",
 "16-999999999999996","17-999999999999993","18-999999999999994",
 "19-999999999999999"}
	; vs range(_range, _range + (sizeof(_range) / sizeof(_range[0]))); A0.push_back( range ); string result = 
	"999970000299999"
	; A1.push_back( result );  }
	{ /*Test 2*/string _range[] = 
	{"0-3","10-20","30-60","80-120"}
	; vs range(_range, _range + (sizeof(_range) / sizeof(_range[0]))); A0.push_back( range ); string result = 
	"1"
	; A1.push_back( result );  }
	{ /*Test 3*/string _range[] = 
	{"999700030000-999999999999","999400119993-999700029998",
 "999100269974-999400119991","998800479937-999100269972"}
	; vs range(_range, _range + (sizeof(_range) / sizeof(_range[0]))); A0.push_back( range ); string result = 
	""
	; A1.push_back( result );  }
	{ /*Test 4*/string _range[] = 
	{"0-0","2-2","3-3","4-4","5-5","6-6","7-7","9-9","10-10","12-12",
 "14-14","16-16","18-18","20-20","22-22","24-24","26-26","28-28",
 "30-30","32-32","34-34","36-36","38-38","40-40","42-42","44-44",
 "46-46","48-48","50-50","52-52","54-54","56-56","58-58","60-60",
 "62-62","65-65","67-67","69-69","71-71","73-73","75-75","77-77",
 "79-79","81-81","83-83","85-85","87-87","89-89","99-99",
  "999970000300000-999999999999999" }
	; vs range(_range, _range + (sizeof(_range) / sizeof(_range[0]))); A0.push_back( range ); string result = 
	"0"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], largestCube( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BigCube ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
