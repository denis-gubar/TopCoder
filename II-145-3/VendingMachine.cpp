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
typedef vector<vi> vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
#define all(v) (v).begin(), (v).end()
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
template<typename Predicate> vs parse( string s, Predicate predicate, bool skipEmpty = true )
{
	vs result; bool isWord = false; int j = 0;
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
template <typename T> vector<T> Split( string s, string delimeter = " " )
{
	return Parse<T>( s, split_helper( delimeter ) );
}
vs split( const string& s, const string& delimeter = " ", bool skipEmpty = true )
{
	return parse( s, split_helper( delimeter ), skipEmpty );
}
struct VendingMachine
{
	int motorUse( vs prices, vs purchases )
	{
		int result = 0; set<string> S;
		fora(i, purchases)
			if ( !S.insert( split( purchases[i], ":" )[0] ).second )
				return -1;
		vvi P;
		fora(i, prices)
			P.push_back( Split<int>( prices[i] ) );
		int n = P[0].size(); vi A(n, 0);
		fora2(i, j, P)
			A[j] += P[i][j];
		int time = -5, curCol = 0;
		fora(i, purchases)
		{
			vi z = Split<int>( purchases[i], ",:" );
			if ( z[2] - time >= 5 )
			{
				int m = distance( A.begin(), max_element( all(A) ) );
				result += min( abs(curCol - m), n - abs(curCol - m) );
				curCol = m;
			}
			A[z[1]] -= P[z[0]][z[1]];
			result += min( abs(curCol - z[1]), n - abs(curCol - z[1]) );
			curCol = z[1];
			time = z[2];
		}
		int m = distance( A.begin(), max_element( all(A) ) );
		result += min( abs(curCol - m), n - abs(curCol - m) );
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vs> A1; vector<int> A2;
	{ /*Test 0*/string _prices[] = 
	{"100 100 100"}
	; vs prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); string _purchases[] = 
	{"0,0:0", "0,2:5", "0,1:10"}
	; vs purchases(_purchases, _purchases + (sizeof(_purchases) / sizeof(_purchases[0]))); A1.push_back( purchases ); int result = 
	4
	; A2.push_back( result );  }
	{ /*Test 1*/string _prices[] = 
	{"100 200 300 400 500 600"}
	; vs prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); string _purchases[] = 
	{"0,2:0", "0,3:5", "0,1:10", "0,4:15"}
	; vs purchases(_purchases, _purchases + (sizeof(_purchases) / sizeof(_purchases[0]))); A1.push_back( purchases ); int result = 
	17
	; A2.push_back( result );  }
	{ /*Test 2*/string _prices[] = 
	{"100 200 300 400 500 600"}
	; vs prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); string _purchases[] = 
	{"0,2:0", "0,3:4", "0,1:8", "0,4:12"}
	; vs purchases(_purchases, _purchases + (sizeof(_purchases) / sizeof(_purchases[0]))); A1.push_back( purchases ); int result = 
	11
	; A2.push_back( result );  }
	{ /*Test 3*/string _prices[] = 
	{"100 100 100"}
	; vs prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); string _purchases[] = 
	{"0,0:10", "0,0:11"}
	; vs purchases(_purchases, _purchases + (sizeof(_purchases) / sizeof(_purchases[0]))); A1.push_back( purchases ); int result = 
	-1
	; A2.push_back( result );  }
	{ /*Test 4*/string _prices[] = 
	{"100 200 300",
 "600 500 400"}
	; vs prices(_prices, _prices + (sizeof(_prices) / sizeof(_prices[0]))); A0.push_back( prices ); string _purchases[] = 
	{"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"}
	; vs purchases(_purchases, _purchases + (sizeof(_purchases) / sizeof(_purchases[0]))); A1.push_back( purchases ); int result = 
	6
	; A2.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A2[i], motorUse( A0[i], A1[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	VendingMachine ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
