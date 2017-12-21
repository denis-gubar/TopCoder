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
struct TaglishTranslator
{
	string toLower( string s )
	{
		transform( all(s), s.begin(), ::tolower );
		return s;
	}
	string calc( string x )
	{
		return x.substr( 0, x.find_first_of( string( "aeuioAEUIO" ) ) + 1 ) + x;
	}
	string translate( string sentence )
	{
		string result;
		vs z( split( sentence ) );
		int k = 0;
		bool isThing = toLower( z[k] ) == "the";
		k += isThing;
		string subject = z[k++];
		bool isFuture = toLower( z[k] ) == "will";
		k += isFuture;
		string verb = z[k++];
		if ( isFuture )
			result += "mag" + calc( verb );
		else if ( toLower( verb.substr( max( 0, static_cast<int>( verb.size() ) - 2 ) ) ) == "ed" )
			result += "nag" + verb.substr( 0, verb.size() - 2 );
		else
			result += "nag" + calc( verb );
		if ( isThing )
			result += " ang " + subject;
		else
			result += " si " + subject;
		if ( k < z.size() )
		{
			bool isTo = toLower( z[k] ) == "to";
			k += isTo;
			isThing = toLower( z[k] ) == "the";
			k += isThing;
			string object = z[k];
			if ( isTo && isThing )
				result += " sa " + object;
			if ( isTo && !isThing )
				result += " kay " + object;
			if ( !isTo && isThing )
				result += " ng " + object;
			if ( !isTo && !isThing )
				result += " ni " + object;
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1;
	{ /*Test 0*/string sentence = 
	"The fox jumps to the dog"
	; A0.push_back( sentence ); string result = 
	"nagjujumps ang fox sa dog"
	; A1.push_back( result );  }
	{ /*Test 1*/string sentence = 
	"tomek codes"
	; A0.push_back( sentence ); string result = 
	"nagcocodes si tomek"
	; A1.push_back( result );  }
	{ /*Test 2*/string sentence = 
	"tHe mAn plAyEd ThE pIAnO"
	; A0.push_back( sentence ); string result = 
	"nagplAy ang mAn ng pIAnO"
	; A1.push_back( result );  }
	{ /*Test 3*/string sentence = 
	"Bob will Filed the taxes"
	; A0.push_back( sentence ); string result = 
	"magFiFiled si Bob ng taxes"
	; A1.push_back( result );  }
	{ /*Test 4*/string sentence = 
	"Matthew walked to Mathew"
	; A0.push_back( sentence ); string result = 
	"nagwalk si Matthew kay Mathew"
	; A1.push_back( result );  }
	{ /*Test 5*/string sentence = 
	"StrongBad kicked TheCheat"
	; A0.push_back( sentence ); string result = 
	"nagkick si StrongBad ni TheCheat"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], translate( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TaglishTranslator ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
