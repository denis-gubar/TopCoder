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
string replace_all( string s, string oldValue, string newValue )
{
	string result;
	int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
pair<string, int> parse( string a )
{
	pair<string, int> result = make_pair( "", 0 );
	fora(i, a)
		if ( isdigit( a[i] ) )
			result.second = result.second * 10 + a[i] - '0';
		else
			result.first += a[i];
	return result;
}
bool comp( string a, string b )
{
	pair<string, int> x = parse( a ), y = parse( b );
	return x.second < y.second || (x.second == y.second && x.first < y.first);
}
struct Prerequisites
{
public:
	vector <string> orderClasses( vector <string> classes )
	{ 
		vs result, temp( classes.size() );
		set<pair<string, string> > H;
		fora(i, classes)
			temp[i] = Split( replace_all( classes[i], ":", "" ) )[0];
		fora(i, classes)
		{
			vs x = Split( replace_all( classes[i], ":", "" ) );
			for( int j = 1; j < x.size(); j++ )
				if ( find( temp.begin(), temp.end(), x[j] ) == temp.end() )
					return vs(0);
				else
					H.insert( make_pair( x[0], x[j] ));
		}
		set<string> s;
		while( temp.size() )
		{
			fora(i, temp)
			{
				bool flag = false;
				fora(j, temp)
					flag |= H.find( make_pair( temp[i], temp[j] ) ) != H.end();
				if ( !flag )
					s.insert( temp[i] );
			}
			if ( s.empty() )
				return vs(0);
			set<string>::iterator k = min_element( s.begin(), s.end(), comp );
			result.push_back( *k );
			temp.erase( find( temp.begin(), temp.end(), *k ) );
			s.erase( k );
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
	Prerequisites ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
