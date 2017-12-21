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
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
template<typename T, typename Predicate> vector<T> Parse( const string& s, Predicate predicate )
{
	vector<T> result;
	for( size_t i = 0, j = 0, n = s.size(), isWord = 0; i <= n; ++i )
		if ( isWord == (i == n || !predicate( s[i] )) )
			if ( isWord = !isWord ) j = i;
			else
			{
				istringstream S( s.substr( j, i - j ) ); T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
			}
	return result;
}
template<typename Predicate> vs parse( const string& s, Predicate predicate )
{
	vs result;
	for( size_t i = 0, j = 0, n = s.size(), isWord = 0; i <= n; ++i )
		if ( isWord == (i == n || !predicate( s[i] )) )
			if ( isWord = !isWord ) j = i;
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
template <typename T> vector<T> Split( string s, string delimeter = " " )
{
	return Parse<T>( s, split_helper( delimeter ) );
}
vs split( const string& s, const string& delimeter = " " )
{
	return parse( s, split_helper( delimeter ) );
}
struct TravellingByTrain
{
	int calc( const string& s )
	{
		vi z( Split<int>( s, ":" ) );
		return z[0] * 60 + z[1];
	}
	string earliestArrival( vs timeTable )
	{
		int now = 540, days = 1;
		fora(i, timeTable)
		{
			vs z( split( timeTable[i] ) );
			vi A;
			fora(j, z)
			{
				int current = now, d = 0;
				vs t( split( z[j], "-" ) );
				if ( t[0] == t[1] )
				{
					++d;
					if ( current > calc( t[0] ) )
						++d;
					current = calc( t[0] );
				}
				else
					fora(k, t)
					{
						if ( current > calc( t[k] ) )
							++d;
						current = calc( t[k] );
					}
				A.push_back( current + d * 1440 );
			}
			int q = *min_element( all(A) );
			now = q % 1440; days += q / 1440;
		}
		return ToString(100 + now / 60).substr( 1 ) + ":" + ToString(100 + now % 60).substr( 1 ) + ", day " + ToString( days );
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
	{ /*Test 0*/string _timeTable[] = 
	{"10:00-13:00 12:00-15:00","11:00-16:00 14:00-19:00"}
	; vs timeTable(_timeTable, _timeTable + (sizeof(_timeTable) / sizeof(_timeTable[0]))); A0.push_back( timeTable ); string result = 
	"19:00, day 1"
	; A1.push_back( result );  }
	{ /*Test 1*/string _timeTable[] = 
	{"09:00-13:57","13:56-17:00"}
	; vs timeTable(_timeTable, _timeTable + (sizeof(_timeTable) / sizeof(_timeTable[0]))); A0.push_back( timeTable ); string result = 
	"17:00, day 2"
	; A1.push_back( result );  }
	{ /*Test 2*/string _timeTable[] = 
	{"10:00-08:00"}
	; vs timeTable(_timeTable, _timeTable + (sizeof(_timeTable) / sizeof(_timeTable[0]))); A0.push_back( timeTable ); string result = 
	"08:00, day 2"
	; A1.push_back( result );  }
	{ /*Test 3*/string _timeTable[] = 
	{"09:10-11:00 09:05-10:05","10:10-12:00 11:00-11:05","17:00-08:00","09:00-08:00"}
	; vs timeTable(_timeTable, _timeTable + (sizeof(_timeTable) / sizeof(_timeTable[0]))); A0.push_back( timeTable ); string result = 
	"08:00, day 3"
	; A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], earliestArrival( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TravellingByTrain ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
