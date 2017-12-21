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
typedef vector<int> vi;
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
struct BadClock
{
	int calc( string s )
	{
		vi z = Split<int>( s, ":" );
		return z[0] * 3600 + z[1] * 60 + z[2];
	}
	double nextAgreement( string trueTime, string skewTime, int hourlyGain )
	{
		if ( trueTime == skewTime ) return 0;
		int delta = (calc( trueTime ) - calc( skewTime ) + 3600 * 12) % (3600 * 12);
		if ( hourlyGain < 0 ) delta = 3600 * 12 - delta;
		return 1.0 * delta / abs(hourlyGain);
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<string> A1; vector<int> A2; vector<double> A3;
	{ /*Test 0*/string trueTime = 
	"07:07:07"
	; A0.push_back( trueTime ); string skewTime = 
	"07:07:07"
	; A1.push_back( skewTime ); int hourlyGain = 
	1776
	; A2.push_back( hourlyGain ); double result = 
	0.0
	; A3.push_back( result );  }
	{ /*Test 1*/string trueTime = 
	"11:59:58"
	; A0.push_back( trueTime ); string skewTime = 
	"12:03:28"
	; A1.push_back( skewTime ); int hourlyGain = 
	-3
	; A2.push_back( hourlyGain ); double result = 
	70.0
	; A3.push_back( result );  }
	{ /*Test 2*/string trueTime = 
	"12:03:28"
	; A0.push_back( trueTime ); string skewTime = 
	"11:59:58"
	; A1.push_back( skewTime ); int hourlyGain = 
	3
	; A2.push_back( hourlyGain ); double result = 
	70.0
	; A3.push_back( result );  }
	{ /*Test 3*/string trueTime = 
	"03:03:02"
	; A0.push_back( trueTime ); string skewTime = 
	"03:01:47"
	; A1.push_back( skewTime ); int hourlyGain = 
	5
	; A2.push_back( hourlyGain ); double result = 
	15.0
	; A3.push_back( result );  }
	{ /*Test 4*/string trueTime = 
	"03:03:02"
	; A0.push_back( trueTime ); string skewTime = 
	"03:01:47"
	; A1.push_back( skewTime ); int hourlyGain = 
	-5
	; A2.push_back( hourlyGain ); double result = 
	8625.0
	; A3.push_back( result );  }
	{ /*Test 5*/string trueTime = 
	"07:08:09"
	; A0.push_back( trueTime ); string skewTime = 
	"09:08:07"
	; A1.push_back( skewTime ); int hourlyGain = 
	-321
	; A2.push_back( hourlyGain ); double result = 
	22.42367601246106
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], nextAgreement( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BadClock ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
