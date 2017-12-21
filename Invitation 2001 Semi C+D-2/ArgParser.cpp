#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
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
typedef long long lint;
typedef unsigned long long ulint;
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
struct ArgParser
{
public:
	vector <string> parse( string s )
	{
		if ( s.size() < 2 || s[0] != '{' || s[s.size() - 1] != '}' || s[s.size() - 2] == '\\' ) return vs(1, "INVALID");
		if ( s.size() == 2 ) return vs(1, "");
		s = s.substr( 1, s.size() - 2 );
		s = replace_all(replace_all(replace_all(replace_all(s, "\\,", "."), "\\{", "["), "\\}", "]"), ", ", "!");
		string t = "{},";
		if ( find_first_of( all(s), all(t) ) != s.end() ) return vs(1, "INVALID");
		s = replace_all(replace_all(replace_all(s, ".", ","), "[", "{"), "]", "}");		
		return Split(s, "!");
	}
// *** WARNING *** No test cases defined for this problem
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ArgParser ___test;
	vs x = ___test.parse( "{, , , a, }" );
	print( x );
	cout << x.size() << endl;
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
