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
struct RPG
{
	vi dieRolls( vs dice )
	{
		vi result(3, 0);
		fora(i, dice)
		{
			vi z = Split<int>( dice[i], "d" );
			result[0] += z[0];
			result[1] += z[0] * z[1];
			result[2] += z[0] + z[0] * z[1];
		}
		result[2] /= 2;
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
	void run_test( int Case = -1 ) { vector<vs> A0; vector<vi> A1;
	{ /*Test 0*/string _dice[] = 
	{"3d6"}
	; vs dice(_dice, _dice + (sizeof(_dice) / sizeof(_dice[0]))); A0.push_back( dice ); int _result[] = 
	{ 3,  18,  10 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 1*/string _dice[] = 
	{"3d4","1d6"}
	; vs dice(_dice, _dice + (sizeof(_dice) / sizeof(_dice[0]))); A0.push_back( dice ); int _result[] = 
	{ 4,  18,  11 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 2*/string _dice[] = 
	{"6d5","10d10","10d20"}
	; vs dice(_dice, _dice + (sizeof(_dice) / sizeof(_dice[0]))); A0.push_back( dice ); int _result[] = 
	{ 26,  330,  178 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	{ /*Test 3*/string _dice[] = 
	{"1d2","2d2","4d2","6d2","8d2"}
	; vs dice(_dice, _dice + (sizeof(_dice) / sizeof(_dice[0]))); A0.push_back( dice ); int _result[] = 
	{ 21,  42,  31 }
	; vi result(_result, _result + (sizeof(_result) / sizeof(_result[0]))); A1.push_back( result );  }
	for( int i = 0; i < A0.size(); i++ ) if ( Case == -1 || i == Case ) { DWORD start, finish; start = timeGetTime(); verify_case( i, A1[i], dieRolls( A0[i]) ); finish = timeGetTime(); cout << "Elapsed " << finish - start << " msec" << endl; } }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	RPG ___test; 
	___test.run_test(); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE
