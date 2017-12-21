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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct LetterRange
{
public:
	vector <string> ranges( string s )
	{
		vector <string> result;
		vi x( 256, 0 );
		fora(i, s)
			x[s[i]]++;
		char prev = 0;
		for( char c = 'a'; c <= 'z' + 1; c++ )
		{
			if ( x[c] && !prev ) prev = c;
			if ( !x[c] && x[c - 1] )
			{
				result.push_back( prev + string(":") + char(c - 1) );
				prev = 0;
			}
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
	LetterRange ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
