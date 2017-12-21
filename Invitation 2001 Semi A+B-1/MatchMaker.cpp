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
bool comp( pair<string, int> a, pair<string, int> b )
{
	return a.second > b.second;
}
struct MatchMaker
{
public:
	vector <string> getBestMatches(vs members, string currentUser, int sf)
	{
		vvs s;
		vector<pair<string, int> > order;
		vs result, x;
		fora(i, members)
		{
			s.push_back( Split( members[i] ) );
			if ( s[i][0] == currentUser ) x = s[i];
		}
		fora(i, members)
		{
			if ( s[i][0] != currentUser && s[i][1] == x[2] && s[i][2] == x[1] )
			{
				int count = 0;
				for( int j = 3; j < s[i].size(); j++ )
					if ( s[i][j] == x[j] ) count++;
				if ( count >= sf )
					order.push_back( make_pair( s[i][0], count ) );
			}
		}
		stable_sort( order.begin(), order.end(), comp );
		fora(i, order)
			result.push_back( order[i].first );
		return result;
	}
// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	MatchMaker ___test; 
	vs x;
	x.push_back("B F M A");
	x.push_back("A M F A");
	x.push_back("D F M A");
	x.push_back("C F M A");
	vs y = ___test.getBestMatches( x, "A", 1 );
	fora(i, y)
		cout << y[i] << endl;	
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
