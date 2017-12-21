//Written at Mon Mar 14 16:32:21 EET 2005
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
typedef long long lint;
typedef unsigned long long ulint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lint> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<string, string> pss;
typedef vector<pss> vpss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<int, string> pis;
typedef vector<pis> vpis;
typedef pair<string, int> psi;
typedef vector<psi> vpsi;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef pair<double, string> pds;
typedef vector<pds> vpds;
typedef pair<string, double> psd;
typedef vector<psd> vpsd;
typedef pair<int, double> pid;
typedef vector<pid> vpid;
typedef pair<double, int> pdi;
typedef vector<pdi> vpdi;
typedef pair<lint, lint> pll;
typedef vector<pll> vpll;
typedef pair<lint, string> pls;
typedef vector<pls> vpls;
typedef pair<string, lint> psl;
typedef vector<psl> vpsl;
typedef pair<int, lint> pil;
typedef vector<pil> vpil;
typedef pair<lint, int> pli;
typedef vector<pli> vpli;
typedef pair<double, lint> pdl;
typedef vector<pdl> vpdl;
typedef pair<lint, double> pld;
typedef vector<pld> vpld;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
#define ToVector(x, _x) x( _x, _x + sizeof(_x)/sizeof(_x[0]) )
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
template<typename T> T FromString( string s )
{
	istringstream S( s ); T result; S >> result; return result;
}
string replace_all( string s, string oldValue, string newValue )
{
	string result; int j = 0;
	for( int i = s.find( oldValue ); i > -1; i = s.find( oldValue, i + oldValue.size() ) )
	{
		result += s.substr( j, i - j ) + newValue;
		j = i + oldValue.size();
	}
	result.append( s.substr( j ) );
	return result;
}
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
template<typename T> T gcd( T a, T b )
{
	while( a && b ) if ( a > b ) a %= b; else b %= a; return a + b;
}
template<typename T> T lcm( T a, T b )
{
	return a / gcd( a, b ) * b;
}
struct FormatAmt
{
	string amount( int dollars, int cents )
	{
		string result;
		return result;
	}
};


// Powered by FileEdit
// Powered by DEathkNIghtSTester 1.2 08-Feb-2004
// Powered by CodeProcessor
