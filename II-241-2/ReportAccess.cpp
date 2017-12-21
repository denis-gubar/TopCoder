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
#define fora(i,v) for(int i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
template<typename Predicate> vs parse( const string& s, Predicate predicate )
{
	vs result;
	for( size_t i = 0, j = 0, n = s.size(), isWord = 0; i <= n; ++i )
		if ( isWord == (i == n || !predicate( s[i] )) )
			if ( (isWord = !isWord) ) j = i;
			else result.push_back( s.substr( j, i - j ) );
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
vs split( const string& s, const string& delimeter = " " )
{
	return parse( s, split_helper( delimeter ) );
}
struct ReportAccess
{
	vs whoCanSee( vs userNames, vs allowedData, vs reportData )
	{
		vs result;
        sort( all(reportData) );
        reportData.erase( unique( all(reportData) ), reportData.end() );
        fora(i, userNames)
        {
            vs z( split( allowedData[i] ) ), x;
            sort( all(z) );
            z.erase( unique( all(z) ), z.end() );
            set_intersection( all(z), all(reportData), back_inserter<vs>( x ) );
            if ( x == reportData )
                result.push_back( userNames[i] );
        }
        sort( all(result) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<vs> A2; vector<vs> A3;
	{ /*Test 0*/string _userNames[] = 
	{"joe", "nick", "ted"}
	; vs userNames(_userNames, _userNames + (sizeof(_userNames) / sizeof(_userNames[0]))); A0.push_back( userNames ); string _allowedData[] = 
	{"clients products", "products orders", "clients orders"}
	; vs allowedData(_allowedData, _allowedData + (sizeof(_allowedData) / sizeof(_allowedData[0]))); A1.push_back( allowedData ); string _reportData[] = 
	{"clients", "products"}
	; vs reportData(_reportData, _reportData + (sizeof(_reportData) / sizeof(_reportData[0]))); A2.push_back( reportData ); string _result[] = 
	{"joe" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 1*/string _userNames[] = 
	{"kathy", "john", "dan", "steve", "cheryl", "tony"}
	; vs userNames(_userNames, _userNames + (sizeof(_userNames) / sizeof(_userNames[0]))); A0.push_back( userNames ); string _allowedData[] = 
	{"users data", "data orders", "users permissions", "system users controls", "default", "admin users"}
	; vs allowedData(_allowedData, _allowedData + (sizeof(_allowedData) / sizeof(_allowedData[0]))); A1.push_back( allowedData ); string _reportData[] = 
	{"users"}
	; vs reportData(_reportData, _reportData + (sizeof(_reportData) / sizeof(_reportData[0]))); A2.push_back( reportData ); string _result[] = 
	{"dan", "kathy", "steve", "tony" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A3.push_back( result );  }
	{ /*Test 2*/string _userNames[] = 
	{"jim", "scott", "barbara"}
	; vs userNames(_userNames, _userNames + (sizeof(_userNames) / sizeof(_userNames[0]))); A0.push_back( userNames ); string _allowedData[] = 
	{"users order products", "products shipping", "tracking products orders"}
	; vs allowedData(_allowedData, _allowedData + (sizeof(_allowedData) / sizeof(_allowedData[0]))); A1.push_back( allowedData ); string _reportData[] = 
	{"admin"}
	; vs reportData(_reportData, _reportData + (sizeof(_reportData) / sizeof(_reportData[0]))); A2.push_back( reportData ); vs result; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], whoCanSee( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ReportAccess ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
