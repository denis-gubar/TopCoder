//Trash was removed in 484 msec
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
typedef vector<lint> vl;
typedef vector<vector<lint> > vvl;
typedef vector<string> vs;
#define all(v) (v).begin(), (v).end()
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
lint factorial( lint x )
{
	static const int N = 21;
	static bool isCached = false;
	static vl cache = vl(N + 1);
	if ( !isCached )
	{
		cache[0] = 1;
		for( int i = 1; i <= N; i++ )
			cache[i] = cache[i - 1] * i;
	}
	isCached = true;
	return x >= 0 && x <= N ? cache[x] : 0;
}
lint C( lint n, lint k )
{
	static const int N = 150;
	static bool isCached = false;
	static vvl cache = vvl(N + 1, vl(N + 1, 0));
	if ( !isCached )
	{
		for( int i = 0; i <= N; i++ )
			cache[i][0] = cache[i][i] = 1;
		for( int i = 1; i <= N; i++ )
			for( int j = 1; j < i; j++ )
				cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
	}
	isCached = true;
	return n >= k && k >= 0 && n <= N ? cache[n][k] : 0;
}
lint choose( lint n, lint k, bool isSorted, bool isUnique )
{
	lint result = 1;
	if ( !isSorted && !isUnique )
		for( int i = 0; i < k; i++ )
			result *= n;
	if ( !isSorted && isUnique )
		result = C(n, k) * factorial(k);
	if ( isSorted && !isUnique )
		result = C(n + k - 1, k);
	if ( isSorted && isUnique )
		result = C(n, k);
	return result;
}
struct Lottery
{
	struct norm: unary_function<string, string>
	{
		string operator() ( const string& a ) const
		{
			return a.substr( 0, a.find(':') );
		}
	};
	struct comp: binary_function<string, string, bool>
	{
		lint calc( const string& a ) const
		{
			vs A = Split( a.substr( a.find(':') + 1 ) );
			return choose( FromString<lint>( A[0] ), FromString<lint>( A[1] ), A[2][0] == 'T', A[3][0] == 'T' );
		}
		bool operator() ( const string& a, const string& b ) const
		{
			lint A = calc( a ), B = calc( b );
			if ( A != B ) return A < B;
			return norm()( a ) < norm()( b );
		}
	};
	vs sortByOdds( vs rules )
	{
		sort( all(rules), comp() );
		transform( all(rules), rules.begin(), norm() );
		return rules;
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
	void run_test( int Case = - 1 ) { vector<vs> A0; vector<vs> A1;
	{ /*Test 0*/string _Arg0[] = 
	{"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 1*/string _Arg0[] = 
	{"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
	; vs Arg0(_Arg0, _Arg0 + (sizeof(_Arg0) / sizeof(_Arg0[0]))); A0.push_back( Arg0 ); string _Arg1[] = 
	{ "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }
	; vs Arg1(_Arg1, _Arg1 + (sizeof(_Arg1) / sizeof(_Arg1[0]))); A1.push_back( Arg1 );  }
	{ /*Test 2*/vs Arg0; A0.push_back( Arg0 ); vs Arg1; A1.push_back( Arg1 );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], sortByOdds( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Lottery ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
