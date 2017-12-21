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
typedef vector<int> vi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
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
struct Salary
{
	int getTime( string s )
	{
		vi z = Split<int>( s, ":" );
		return z[0] * 3600 + z[1] * 60 + z[2];
	}
	int howMuch( vs arrival, vs departure, int wage )
	{
		lint result = 0;
		fora(i, arrival)
		{
			int a = getTime( arrival[i] ), b = getTime( departure[i] );
			while( a != b )
			{
				if ( a >= 18 * 3600 || a < 6 * 3600 ) result += 3;
				else result += 2;
				++a; a %= 3600 * 24;
			}
		}
		return result * wage / 7200;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<int> A2; vector<int> A3;
	{ /*Test 0*/string _arrival[] = 
	{"08:00:00","13:00:00","19:27:32"}
	; vs arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); string _departure[] = 
	{"12:00:00","17:00:00","20:48:10"}
	; vs departure(_departure, _departure + (sizeof(_departure) / sizeof(_departure[0]))); A1.push_back( departure ); int wage = 
	1000
	; A2.push_back( wage ); int result = 
	10015
	; A3.push_back( result );  }
	{ /*Test 1*/string _arrival[] = 
	{"01:05:47","16:48:12"}
	; vs arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); string _departure[] = 
	{"09:27:30","21:17:59"}
	; vs departure(_departure, _departure + (sizeof(_departure) / sizeof(_departure[0]))); A1.push_back( departure ); int wage = 
	2000
	; A2.push_back( wage ); int result = 
	33920
	; A3.push_back( result );  }
	{ /*Test 2*/string _arrival[] = 
	{"00:00:00"}
	; vs arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); string _departure[] = 
	{"23:59:59"}
	; vs departure(_departure, _departure + (sizeof(_departure) / sizeof(_departure[0]))); A1.push_back( departure ); int wage = 
	10000
	; A2.push_back( wage ); int result = 
	299995
	; A3.push_back( result );  }
	{ /*Test 3*/string _arrival[] = 
	{"10:00:00"}
	; vs arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); string _departure[] = 
	{"18:00:00"}
	; vs departure(_departure, _departure + (sizeof(_departure) / sizeof(_departure[0]))); A1.push_back( departure ); int wage = 
	10000
	; A2.push_back( wage ); int result = 
	80000
	; A3.push_back( result );  }
	{ /*Test 4*/string _arrival[] = 
	{"22:19:46"}
	; vs arrival(_arrival, _arrival + (sizeof(_arrival) / sizeof(_arrival[0]))); A0.push_back( arrival ); string _departure[] = 
	{"23:12:46"}
	; vs departure(_departure, _departure + (sizeof(_departure) / sizeof(_departure[0]))); A1.push_back( departure ); int wage = 
	5320
	; A2.push_back( wage ); int result = 
	7049
	; A3.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], howMuch( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Salary ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
