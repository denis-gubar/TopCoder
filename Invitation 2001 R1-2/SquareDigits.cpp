#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
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
// END CUT HERE 
#endif
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
#define fora(i,v) for(unsigned int i = 0; i < (v).size(); i++)
struct SquareDigits
{
public:
	int S( int x )
	{
		int result = 0;
		while( x > 0 )
		{
			result += (x % 10) * (x % 10);
			x /= 10;
		}
		return result;
	}
	int smallestResult( int param0 )
	{
		set<int> H;
		for( int i = 0; ; i++ )
		{
			int x = S(i);
			while( H.find( x ) == H.end() )
			{
				H.insert( x );
				if ( x == param0 ) return i;
				x = S(x);
			}
		}
	}
// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	SquareDigits ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
