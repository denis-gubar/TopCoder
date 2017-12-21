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
#define all(v) (v).begin(), (v).end()
struct SignatureDecorator
{
	string applyDecoration( string name, vs commands, vs decorations )
	{
		string result = name;
		fora(i, commands)
		{
			string s = decorations[i];
			if ( commands[i] == "append" )
				result += s;
			else if ( commands[i] == "prepend" )
				result = s + result;
			else if ( commands[i] == "surround" )
			{
				result = s + result;
				reverse( all(s) );
				result += s;
			}
		}
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
	void run_test( int Case = -1 ) { vector<string> A0; vector<vs> A1; vector<vs> A2; vector<string> A3;
	{ /*Test 0*/string Arg0 = 
	"Bob"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"surround", "append", "prepend"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{"-=", "(", ")"}
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string Arg3 = 
	")-=Bob=-("
	; A3.push_back( Arg3 );  }
	{ /*Test 1*/string Arg0 = 
	"Super_Man_01"
	; A0.push_back( Arg0 ); vs Arg1; A1.push_back( Arg1 ); vs Arg2; A2.push_back( Arg2 ); string Arg3 = 
	"Super_Man_01"
	; A3.push_back( Arg3 );  }
	{ /*Test 2*/string Arg0 = 
	"4BcD3FgHIjklMN0pqrS7uVWxYZ_"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"append", "prepend", "surround"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{"`{[(", ")]}'", ",.;<>?:|-=_+!@#$%^&*~"}
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string Arg3 = 
	",.;<>?:|-=_+!@#$%^&*~)]}'4BcD3FgHIjklMN0pqrS7uVWxYZ_`{[(~*&^%$#@!+_=-|:?><;.,"
	; A3.push_back( Arg3 );  }
	{ /*Test 3*/string Arg0 = 
	"RacEcaR"
	; A0.push_back( Arg0 ); string _Arg1[] = 
	{"surround"}
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 ); string _Arg2[] = 
	{"([{/"}
	; vs Arg2(_Arg2, _Arg2 + (sizeof(_Arg2) / sizeof(_Arg2[0]))); A2.push_back( Arg2 ); string Arg3 = 
	"([{/RacEcaR/{[("
	; A3.push_back( Arg3 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A3[i], applyDecoration( A0[i], A1[i], A2[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SignatureDecorator ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
