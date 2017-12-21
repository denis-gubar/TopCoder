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
struct PermissionTree
{
	int calc( const vi& a, const vi& b )
	{
		int result = -1;
		do
		{
			++result;
		}
		while( result + 1 < a.size() && result + 1 < b.size() && a[result + 1] == b[result + 1] );
		return result;
	}
	vi findHome( vs folders, vs users )
	{
		vi result;
		vi A( folders.size() );
		map<string, vi> M;
		fora(i, folders)
		{
			istringstream is( folders[i] );
			int k; string s;
			is >> k >> s;
			A[i] = k;
			vs z = split( s, "," );
			fora(j, z)
				M[z[j]].push_back( i );
		}
		A[0] = -1;
		fora(i, users)
		{
			if ( M[users[i]].empty() )
			{
				result.push_back( -1 );
				continue;
			}			
			vvi S( M[users[i]].size() );
			fora(j, M[users[i]])
			{
				for( int k = M[users[i]][j]; k >= 0; k = A[k] )
					S[j].push_back( k );
				reverse( all(S[j]) );
			}
			vi temp;
			fora(i, S)
				temp.push_back( calc( S[0], S[i] ) );
			result.push_back( S[0][*min_element( all(temp) )] );
		}
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vi> A2;
	{ /*Test 0*/string _folders[] = 
	{"0 Admin", "0 Joe,Phil", "0 Joe"}
	; vs folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); string _users[] = 
	{"Admin", "Joe", "Phil"}
	; vs users(_users, _users + (sizeof(_users) / sizeof(_users[0]))); A1.push_back( users ); int _result[] = 
	{ 0,  0,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 1*/string _folders[] = 
	{"0 Admin"}
	; vs folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); string _users[] = 
	{"Peter", "Paul", "Mary"}
	; vs users(_users, _users + (sizeof(_users) / sizeof(_users[0]))); A1.push_back( users ); int _result[] = 
	{ -1,  -1,  -1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 2*/string _folders[] = 
	{"0 Admin", "2 John", "0 Peter,John", "0 Tim", "1 John"}
	; vs folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); string _users[] = 
	{"John"}
	; vs users(_users, _users + (sizeof(_users) / sizeof(_users[0]))); A1.push_back( users ); int _result[] = 
	{ 2 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 3*/string _folders[] = 
	{"0 Admin",
"0 Jeff", "1 Mark,Tim", "1 Tim,Jeff",
"0 Dan", "4 Ed", "4 Tom", "4 Kyle,Ed",
"0 Ben", "8 Rich", "8 Sam", "8 Tim"}
	; vs folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); string _users[] = 
	{"Jeff", "Ed", "Tim", "Steve"}
	; vs users(_users, _users + (sizeof(_users) / sizeof(_users[0]))); A1.push_back( users ); int _result[] = 
	{ 1,  4,  0,  -1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	{ /*Test 4*/string _folders[] = 
	{"0 Admin", "0 Bob,Joe,Bob", "0 Joe"}
	; vs folders(_folders, _folders + (sizeof(_folders) / sizeof(_folders[0]))); A0.push_back( folders ); string _users[] = 
	{"Joe", "Bob"}
	; vs users(_users, _users + (sizeof(_users) / sizeof(_users[0]))); A1.push_back( users ); int _result[] = 
	{ 0,  1 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], findHome( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PermissionTree ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
