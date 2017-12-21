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
#ifdef __GNUC__
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template<typename T>
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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
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
int ones( int x )
{
	int result = 0;
	while( x )
	{
		x &= x - 1;
		result++;
	}
	return result;
}
struct Solver
{
public:
	int count;
	vvi M;
	bool calc( int start, int state, int i )
	{
		state ^= 1 << i;
		if ( !state && i == start ) return true;
		fora(j, M)
			if ( M[i][j] && (state & (1 << j)) && calc( start, state, j ) )
				return true;
		return false;
	}
	int largest( vs s )
	{
		int result = count = 0;
		map<string, int> H;
		fora(i, s)
		{
			vs x = Split( s[i] );
			if ( H.find( x[0] ) == H.end() )
				H[x[0]] = count++;
			if ( H.find( x[2] ) == H.end() )
				H[x[2]] = count++;
		}
		M = vvi(count, vi(count, 0));
		fora(i, s)
		{
			vs x = Split( s[i] );
			M[H[x[0]]][H[x[2]]] = 1;
		}
		for( int i = 1; i < 1 << count; i++ )
		{
			if ( ones(i) <= result ) continue;
			int k = i, start = 0;
			while( !(k & 1) )
			{
				k >>= 1; start++;
			}
			if ( calc( start, i ^ (1 << start), start ) )
				result = ones(i);
		}
		return result;
	}
// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	string _x[] = {"A LOVES B",
 "B LOVES C",
 "C LOVES A",
 "B LOVES D",
 "D LOVES E",
 "E LOVES C",
 "E LOVES F",
 "F LOVES G",
 "G LOVES F"};
	vs x;
	copy( _x, _x + sizeof(_x) / sizeof(string), inserter(x, x.begin()) );
	Solver ___test; 
	cout << ___test.largest( x ) << endl; 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
