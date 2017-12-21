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
template<typename T> void print( T collection, char* separator = "\n" )
{
	if ( !collection.empty() )
	{
		copy( collection.begin(), collection.end() - 1, ostream_iterator<T::value_type>( cout, separator ) );
		cout << collection.back();
	}
	cout << endl;
}
// END CUT HERE
typedef long long lint;
typedef vector<string> vs;
struct ParameterSubstitution
{
	enum State {first, second};
	string processParams( string code, vs params )
	{
		string result;
		code += ' ';
		int n = params.size();
		State S = first;
		int i = 0, p;
		while( i < code.size() )
		{
			switch( S )
			{
				case first:
					if ( code[i] != '$' )
						result += code[i];
					else
					{
						S = second; p = 0;
					}
					++i;
					break;
				case second:
					if ( isdigit( code[i] ) && p * 10 + code[i] - '0' <= n && p * 10 + code[i] - '0' > 0 )
					{
						p = p * 10 + code[i] - '0';
						++i;
					}
					else
					{
						if ( p > 0 )
							result += params[p - 1];
						else
							result += '$';
						S = first;
					}
					break;
			}
		}
		return result.substr( 0, result.size() - 1 );
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<vs> A1; vector<string> A2;
	{ /*Test 0*/string Arg0 = 
	"if ($1 == $2) $3;"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"12", "12", "doWhatIWant()"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string Arg2 = 
	"if (12 == 12) doWhatIWant();"
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/string Arg0 = 
	"$3+$1*$2-$7=$10"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"myvar", "490jri", "e09jd9", "dlkjfoiej"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string Arg2 = 
	"e09jd9+myvar*490jri-$7=myvar0"
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/string Arg0 = 
	"12342123$13231232$2123211242$a$dlkj$"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"$2", "$1"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string Arg2 = 
	"12342123$23231232$1123211242$a$dlkj$"
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/string Arg0 = 
	"while($_=~/([0-9a-fA-F]{2})/){print hex($1).'n';}"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"\"7F\""}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string Arg2 = 
	"while($_=~/([0-9a-fA-F]{2})/){print hex(\"7F\").'n';}"
	; A2.push_back( Arg2 );  }
	{ /*Test 4*/string Arg0 = 
	"{[(+.*-,/\\:;<=>?@)]}_`~|$$1"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"1{[(+.*-,/\\:;<=>?@)]}_`~|"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string Arg2 = 
	"{[(+.*-,/\\:;<=>?@)]}_`~|$1{[(+.*-,/\\:;<=>?@)]}_`~|"
	; A2.push_back( Arg2 );  }
	{ /*Test 5*/string Arg0 = 
	"$01"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"abc"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string Arg2 = 
	"$01"
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], processParams( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ParameterSubstitution ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
