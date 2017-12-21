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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
template<typename Predicate> vs parse( string s, Predicate predicate, bool skipEmpty = true )
{
	vs result; bool isWord = false; int j = 0;
	for( int i = 0; i < s.size(); i++ )
		if ( isWord )
		{
			if ( !predicate( s[i] ) )
			{
				result.push_back( s.substr( j, i - j ) ); isWord = false;
			}
		}
		else
		{
			if ( predicate( s[i] ) )
			{
				j = i; isWord = true;
			} else if ( !skipEmpty )
				result.push_back( "" );
		}
		if ( isWord )
			result.push_back( s.substr( j ) );
		else if ( !skipEmpty && !s.empty() )
			result.push_back( "" );
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
vs split( const string& s, const string& delimeter = " ", bool skipEmpty = true )
{
	return parse( s, split_helper( delimeter ), skipEmpty );
}
struct ClientsList
{
	struct comp: binary_function<string, string, bool>
	{
		bool operator() ( const string& a, const string& b ) const
		{
			vs A( split( a ) ), B( split( b ) );
			if ( A[1] != B[1] )
				return A[1] < B[1];
			return A[0] < B[0];
		}
	};
	vs dataCleanup( vs names )
	{
		vs result;
		fora(i, names)
			if ( names[i].find( ',' ) == string::npos )
				result.push_back( names[i] );
			else
			{
				vs z( split( names[i], ", " ) );
				result.push_back( z[1] + " " + z[0] );
			}
		sort( all(result), comp() );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _names[] = 
	{"Joe Smith", "Brown, Sam", "Miller, Judi"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _result[] = 
	{ "Sam Brown",  "Judi Miller",  "Joe Smith" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _names[] = 
	{"Campbell, Phil", "John Campbell", "Young, Warren"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _result[] = 
	{ "John Campbell",  "Phil Campbell",  "Warren Young" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _names[] = 
	{"Kelly, Anthony", "Kelly Anthony", "Thompson, Jack"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _result[] = 
	{ "Kelly Anthony",  "Anthony Kelly",  "Jack Thompson" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/string _names[] = 
	{"Trevor Alvarez", "Jackson, Walter", "Mandi Stuart",
 "Martin, Michael", "Peters, Tammy", "Richard Belmont",
 "Carl Thomas", "Ashton, Roger", "Jamie Martin"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _result[] = 
	{ "Trevor Alvarez",  "Roger Ashton",  "Richard Belmont",  "Walter Jackson",  "Jamie Martin",  "Michael Martin",  "Tammy Peters",  "Mandi Stuart",  "Carl Thomas" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/string _names[] = 
	{"Banks, Cody", "Cody Banks", "Tod Wilson"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _result[] = 
	{ "Cody Banks",  "Cody Banks",  "Tod Wilson" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 5*/string _names[] = 
	{"Mill, Steve", "Miller, Jane"}
	; vs names(_names, _names + (sizeof(_names) / sizeof(_names[0]))); A0.push_back( names ); string _result[] = 
	{ "Steve Mill",  "Jane Miller" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], dataCleanup( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ClientsList ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
