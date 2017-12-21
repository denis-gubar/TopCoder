#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
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
int gcd( int a, int b )
{
	while( a && b )
		if ( a > b ) a %= b;
		else b %= a;
	return a + b;
}
lint gcd( lint a, lint b )
{
	while( a && b )
		if ( a > b ) a %= b;
		else b %= a;
	return a + b;
}
struct ContinuedFractions
{ 
public:
	vector <int> squareRoot( int n )
	{
		vi result;
		int sn = int(sqrt(double(n)));
		int a = sn;
		result.push_back( a );
		set<pair<int, int> > H;
		int b = 1;
		while( true )
		{
			if ( H.find( make_pair(a, b) ) != H.end() ) break;
			H.insert( make_pair(a, b) );
			b = (n - a * a) / b;
			result.push_back( (sn + a) / b );
			a = -a + (sn + a) / b * b;
		}
		return result;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = { 1,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, squareRoot(Arg0)); }
	void test_case_1() { int Arg0 = 41; int Arr1[] = { 6,  2,  2,  12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, squareRoot(Arg0)); }
	void test_case_2() { int Arg0 = 63; int Arr1[] = { 7,  1,  14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, squareRoot(Arg0)); }
	void test_case_3() { int Arg0 = 158; int Arr1[] = { 12,  1,  1,  3,  12,  3,  1,  1,  24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, squareRoot(Arg0)); }
	void test_case_4() { int Arg0 = 512; int Arr1[] = { 22,  1,  1,  1,  2,  6,  11,  6,  2,  1,  1,  1,  44 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, squareRoot(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	ContinuedFractions ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
