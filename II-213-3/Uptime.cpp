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
#include <utility>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
typedef vector<int> vi;
typedef vector<string> vs;
template<typename T> string ToString( T x )
{
	ostringstream S;
	S << x;
	return S.str();
}
template<typename T> T FromString( string s )
{
	istringstream S( s );
	T result; S >> result;
	return result;
}
template <typename T> vector<T> Split( string s, string delimeters = " " )
{
	vector<T> result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( prev < i )
			{
				istringstream S( s.substr( prev, i - prev ) );
				T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
			}
			prev = i + 1;
		}
	return result;
}
vs Split( string s, string delimeters = " ", bool skipEmpty = true )
{
	vs result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( !skipEmpty || prev < i )
				result.push_back( s.substr( prev, i - prev ) );
			prev = i + 1;
		}
	return result;
}
struct Uptime
{
	bool isLeap( int x )
	{
		return x % 4 == 0 && ( x % 100 != 0 || x % 400 == 0 );
	}
	void calc( string& s, int& y, int& m, int& d, int& sec )
	{
		string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		vs z = Split( s );
		d = FromString<int>( z[0] );
		m = distance( months, find( months, months + 12, z[1] ) );
		y = FromString<int>( z[2] );
		vi x = Split<int>( z[4], ":" );
		sec = x[0] % 12 * 3600 + x[1] * 60 + x[2];
		if ( z[5] == "PM" ) sec += 12 * 3600;
	}
	string calcUptime( string started, string now )
	{
		string result;
		int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int y1, y2, d1, d2, m1, m2, s1, s2;
		calc( started, y1, m1, d1, s1 );
		calc( now, y2, m2, d2, s2 );
		int total = d2 - d1;
		if ( s1 > s2 )
		{
			s2 += 24 * 3600; total--;
		}
		int total_sec = s2 - s1;
		days[1] = isLeap( y1 ) + 28;
		while( y1 != y2 || m1 != m2 )
		{
			total += days[m1++];
			if ( m1 == 12 )
			{
				m1 = 0; y1++;
				days[1] = isLeap( y1 ) + 28;
			}
		}
		int h = total_sec / 3600, m = total_sec / 60 % 60, s = total_sec % 60;
		if ( total )
			result = ToString( total ) + "d";
		if ( h )
			if ( result == "" )
				result = ToString( h ) + "h";
			else
				result += " " + ToString( h ) + "h";
		if ( m )
			if ( result == "" )
				result = ToString( m ) + "m";
			else
				result += " " + ToString( m ) + "m";
		if ( s )
			if ( result == "" )
				result = ToString( s ) + "s";
			else
				result += " " + ToString( s ) + "s";
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1; vector<string> A2;
	{ /*Test 0*/string Arg0 = 
	"7 Jun 2004 at 04:41:32 PM"
	; A0.push_back( Arg0 ); string Arg1 = 
	"8 Jun 2004 at 07:16:28 PM"
	; A1.push_back( Arg1 ); string Arg2 = 
	"1d 2h 34m 56s"
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/string Arg0 = 
	"7 Jun 2004 at 04:41:32 PM"
	; A0.push_back( Arg0 ); string Arg1 = 
	"7 Jun 2004 at 04:41:32 PM"
	; A1.push_back( Arg1 ); string Arg2 = 
	""
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/string Arg0 = 
	"28 Feb 2004 at 01:23:45 PM"
	; A0.push_back( Arg0 ); string Arg1 = 
	"1 Mar 2004 at 12:34:56 AM"
	; A1.push_back( Arg1 ); string Arg2 = 
	"1d 11h 11m 11s"
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/string Arg0 = 
	"28 Feb 2005 at 01:23:45 PM"
	; A0.push_back( Arg0 ); string Arg1 = 
	"1 Jan 2015 at 12:34:56 AM"
	; A1.push_back( Arg1 ); string Arg2 = 
	"3593d 11h 11m 11s"
	; A2.push_back( Arg2 );  }
	{ /*Test 4*/string Arg0 = 
	"25 Jan 1922 at 05:58:52 AM"
	; A0.push_back( Arg0 ); string Arg1 = 
	"26 Feb 2190 at 11:53:14 AM"
	; A1.push_back( Arg1 ); string Arg2 = 
	"97918d 5h 54m 22s"
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], calcUptime( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Uptime ___test;
	___test.run_test();
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
