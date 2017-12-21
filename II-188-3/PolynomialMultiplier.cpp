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
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
vs split( string s, string delimeters = " ", bool skipEmpty = true )
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
struct PolynomialMultiplier
{
	void parse( string s, vi& A )
	{
		if ( s.size() == 1 )
		{
			if ( s == "x" ) ++A[1];
			else A[0] += s[0] - '0';
			return;
		}
		int x = 1, y = 1;
		if ( s.find( '*' ) != string::npos )
		{
			vs z = split( s, "*" );
			x = z[0][0] - '0';
		}
		if ( s.find( '^' ) != string::npos )
		{
			vs z = split( s, "^" );
			y = z[1][0] - '0';
		}
		A[y] += x;
	}
	string product( string f1, string f2 )
	{
		string result;
		vi A(10, 0), B(10, 0), X(20, 0);
		vs z = split( f1, " + " );
		fora(i, z)
			parse( z[i], A );
		z = split( f2, " + " );
		fora(i, z)
			parse( z[i], B );
		fora(i, A)
			fora(j, B)
				X[i + j] += A[i] * B[j];
		forad(i, X)
			if ( X[i] )
				result += (result.empty() ? "" : " + " ) +
					(X[i] > 1 || !i ? ToString( X[i] ) : "" ) +
					(X[i] > 1 && i ? "*" : "" ) +
					(i ? "x" : "" ) +
					(i > 1 ? "^" + ToString( i ) : "" );
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
	"1 + x"
	; A0.push_back( Arg0 ); string Arg1 = 
	"1 + x"
	; A1.push_back( Arg1 ); string Arg2 = 
	"x^2 + 2*x + 1"
	; A2.push_back( Arg2 );  }
	{ /*Test 1*/string Arg0 = 
	"4*x^4 + 1"
	; A0.push_back( Arg0 ); string Arg1 = 
	"3*x^5 + 7*x"
	; A1.push_back( Arg1 ); string Arg2 = 
	"12*x^9 + 31*x^5 + 7*x"
	; A2.push_back( Arg2 );  }
	{ /*Test 2*/string Arg0 = 
	"1 + x + 1 + x"
	; A0.push_back( Arg0 ); string Arg1 = 
	"5 + 5"
	; A1.push_back( Arg1 ); string Arg2 = 
	"20*x + 20"
	; A2.push_back( Arg2 );  }
	{ /*Test 3*/string Arg0 = 
	"8*x^5"
	; A0.push_back( Arg0 ); string Arg1 = 
	"9*x^7"
	; A1.push_back( Arg1 ); string Arg2 = 
	"72*x^12"
	; A2.push_back( Arg2 );  }
	{ /*Test 4*/string Arg0 = 
	"5*x^3 + x^4 + 8 + 2*x^6"
	; A0.push_back( Arg0 ); string Arg1 = 
	"3*x^5 + 4*x + 7*x^9"
	; A1.push_back( Arg1 ); string Arg2 = 
	"14*x^15 + 7*x^13 + 35*x^12 + 6*x^11 + 59*x^9 + 15*x^8 + 8*x^7 + 28*x^5 + 20*x^4 + 32*x"
	; A2.push_back( Arg2 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], product( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	PolynomialMultiplier ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
