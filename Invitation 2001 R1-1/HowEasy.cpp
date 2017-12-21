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
	if ( t != "" )
		result.push_back( t );
	return result;
}
struct HowEasy
{
public:
	int pointVal( string param0 )
	{
		int count = 0;
		int result = 0;
		vs s = Split( param0 );
		fora(i, s)
		{
			if ( s[i][s[i].size() - 1] == '.' ) s[i] = s[i].substr( 0, s[i].size() - 1 );
			bool flag = s[i].size() > 0;
			for( int j = 0; flag && j < s[i].size(); j++ )
				flag = (s[i][j] >= 'A' && s[i][j] <= 'Z') || (s[i][j] >= 'a' && s[i][j] <= 'z');
			if ( !flag ) continue;
			result += s[i].size();
			count++;
		}
		if ( count == 0 || result / count < 4 ) return 250;
		if ( result / count < 6 ) return 500;
		return 1000;
	}
// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	HowEasy ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
