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
#include <utility>
using namespace std;
#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template <typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
vs Split( string s, string c = " " )
{
	vs result;
	string t = "";
	fora(i, s)
		if ( c.find( s[i] ) != -1 )
		{
			result.push_back( t );
			t = "";
		}
		else
			t += s[i];
	if ( t != "" || s.size() >= c.size() && s.substr(s.size() - c.size()) == c )
		result.push_back( t );
	return result;
}
struct Checker
{
public:
	bool CheckData( vs s )
	{
		if ( s.size() < 2 || s.size() > 20 ) return false;
		vs a, b;
		fora(i, s)
		{
			if ( s[i].size() > 40 ) return false;
			vs x = Split( s[i] );
			if ( x.size() != 3 || x[1] != "LOVES" || x[0] == x[2] || !x[0].size() || !x[2].size() )
				return false;
			fora(j, x[0])
				if ( x[0][j] != '-' && !(x[0][j] >= 'A' && x[0][j] <= 'Z') ) return false;
			fora(j, x[2])
				if ( x[2][j] != '-' && !(x[2][j] >= 'A' && x[2][j] <= 'Z') ) return false;
			a.push_back( x[0] );
			b.push_back( x[2] );
		}
		fora(i, b)
			if ( find( all(a), b[i] ) == a.end() ) return false;
		return true;
	}
	// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Checker ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
