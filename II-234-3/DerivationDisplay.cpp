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
typedef vector<string> vs;
#define all(v) (v).begin(), (v).end()
string replace_all( string s, string oldValue, string newValue )
{
	string result; int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
struct DerivationDisplay
{
	vs getDerivation( string input )
	{
		vs result;
		int n = input.size();
		int a = count_if( all(input), bind2nd( equal_to<char>(), 'a' ) );
		int b = count_if( all(input), bind2nd( equal_to<char>(), 'b' ) );
		result.push_back( "S" );
		if ( input[n - 1] == 'a' && b )
		{
			result.push_back( "bUa" );
			for( int i = 1; i < n - 2; ++i )
				result.push_back( replace_all( result.back(), "U", string(1, input[i]) + "U") );
			result.push_back( replace_all( result.back(), "U", string(1, input[n - 2]) ) );
		}
		else
		{
			result.push_back( "T" );
			while( a && b )
			{
				result.push_back( replace_all( result.back(), "T", "aTb" ) );
				--a; --b;
			}
			if ( a )
			{
				result.push_back( replace_all( result.back(), "T", "A" ) );
				while( a > 1 )
				{
					result.push_back( replace_all( result.back(), "A", "aA" ) );
					--a;
				}
				result.push_back( replace_all( result.back(), "A", "a" ) );
			}
			else
			{
				result.push_back( replace_all( result.back(), "T", "B" ) );
				while( b > 1 )
				{
					result.push_back( replace_all( result.back(), "B", "bB" ) );
					--b;
				}
				result.push_back( replace_all( result.back(), "B", "b" ) );
			}
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<vs> A1;
	{ /*Test 0*/string input = 
	"aaabb"
	; A0.push_back( input ); string _result[] = 
	{"S", "T", "aTb", "aaTbb", "aaAbb", "aaabb" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string input = 
	"bbba"
	; A0.push_back( input ); string _result[] = 
	{"S", "bUa", "bbUa", "bbba" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string input = 
	"baabba"
	; A0.push_back( input ); string _result[] = 
	{"S", "bUa", "baUa", "baaUa", "baabUa", "baabba" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/string input = 
	"a"
	; A0.push_back( input ); string _result[] = 
	{"S", "T", "A", "a" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 4*/string input = 
	"b"
	; A0.push_back( input ); string _result[] = 
	{"S", "T", "B", "b" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 5*/string input = 
	"aabbbbbbbb"
	; A0.push_back( input ); string _result[] = 
	{"S", "T", "aTb", "aaTbb", "aaBbb", "aabBbb", "aabbBbb", "aabbbBbb", "aabbbbBbb", "aabbbbbBbb", "aabbbbbbbb" }
	; vs result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], getDerivation( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	DerivationDisplay ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
