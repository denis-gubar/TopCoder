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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
template<typename T> T FromString( string s )
{
	istringstream S( s ); T result; S >> result; return result;
}
template<typename Predicate> vs parse( string s, Predicate predicate, bool skipEmpty = true )
{
	vs result; bool isWord = false; int j;
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
struct TimeAnalysis
{
	double calc( map<string, double>& v, string s )
	{
		vs z = split( s, "+" );
		if ( z.size() > 1 )
		{
			double result = 0;
			fora(i, z)
				result += calc( v, z[i] );
			return result;
		}
		z = split( s, "*" );
		if ( z.size() > 1 )
		{
			double result = 1;
			fora(i, z)
				result *= calc( v, z[i] );
			return result;
		}
		z = split( s, "^" );
		if ( z.size() > 1 )
			return pow( calc( v, z[0] ), calc( v, z[1] ) );
		if ( s[0] == 'l' )
			return log( calc( v, string(1, s[3]) ) ) / log( 2.0 );
		if ( ::isdigit( s[0] ) ) return s[0] - '0';
		return v[s];
	}
	string time( vs variables, string equation )
	{
		map<string, double> v;
		fora(i, variables)
		{
			vs z = split( variables[i] );
			v[z[0]] = FromString<double>( z[1] );
		}
		double x = calc( v, equation );
		if ( x < 1000 )	return ToString( int(x) ) + " nanoseconds";
		x /= 1000;
		if ( x < 1000 )	return ToString( int(x) ) + " microseconds";
		x /= 1000;
		if ( x < 1000 )	return ToString( int(x) ) + " milliseconds";
		x /= 1000;
		if ( x < 60 )	return ToString( int(x) ) + " seconds";
		x /= 60;
		if ( x < 60 ) return ToString( int(x) ) + " minutes";
		x /= 60;
		if ( x < 24 ) return ToString( int(x) ) + " hours";
		x /= 24;
		if ( x < 365 )return ToString( int(x) ) + " days";
		x /= 365;
		return ToString( int(x) ) + " years";
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<string> A1; vector<string> A2;
	{ /*Test 0*/string _Arg0[] = 
	{"N 1000"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"N*lg(N)"
	; A1.push_back( Arg1 ); string Arg2 = 
	"9 microseconds"
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"N 1000000000","M 10"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"M*N*lg(N)"
	; A1.push_back( Arg1 ); string Arg2 = 
	"4 minutes"
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/string _Arg0[] = 
	{"N 1000","M 205"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"N^2*M+M^3"
	; A1.push_back( Arg1 ); string Arg2 = 
	"213 milliseconds"
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/string _Arg0[] = 
	{"N 30"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"2^N*N^2"
	; A1.push_back( Arg1 ); string Arg2 = 
	"16 minutes"
	; A2.push_back( Arg2 );  }
	{ /*Test 4*/string _Arg0[] = 
	{"N 29"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string Arg1 = 
	"3^N*N^2"
	; A1.push_back( Arg1 ); string Arg2 = 
	"1 years"
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], time( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TimeAnalysis ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
