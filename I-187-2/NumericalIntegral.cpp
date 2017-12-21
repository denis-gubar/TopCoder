#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <math.h>
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

class NumericalIntegral
{ 
public:
	string integrate( double x1, double x2 )
	{ 
		double result = 0;
		double s = 0.0000001;
		for( double x = x1; x < x2; x += s )
			result += (exp( -x*x ) + exp( -(x+s)*(x+s) )) / 2 * s;
		char t[100];
		sprintf( t, "%0.5f", result );
		return t;
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = -0.5; double Arg1 = 0.5; string Arg2 = "0.92256"; verify_case(0, Arg2, integrate(Arg0, Arg1)); }
	void test_case_1() { double Arg0 = 0.0; double Arg1 = 0.1; string Arg2 = "0.09967"; verify_case(1, Arg2, integrate(Arg0, Arg1)); }
	void test_case_2() { double Arg0 = -9.0001; double Arg1 = -9.0; string Arg2 = "0.00000"; verify_case(2, Arg2, integrate(Arg0, Arg1)); }
	void test_case_3() { double Arg0 = 2.71828183; double Arg1 = 3.14159265; string Arg2 = "0.00010"; verify_case(3, Arg2, integrate(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
	NumericalIntegral ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
