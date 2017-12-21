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

class Cyberline
{ 
public:
	string lastCyberword( string cyberline )
	{
		string s, result;
		fora(i, cyberline)
		{
			if ( isalnum(cyberline[i]) || cyberline[i] == '@' )
				s += cyberline[i];
			else if ( cyberline[i] != '-' )
			{
				if ( s != "" ) result = s;
				s = "";
			}
		}
		if ( s != "" ) result = s;
		return result;
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Zowie: This is a line of##cyber-poetry## !"; string Arg1 = "cyberpoetry"; verify_case(0, Arg1, lastCyberword(Arg0)); }
	void test_case_1() { string Arg0 = "2-b|!2-b -- ?"; string Arg1 = "2b"; verify_case(1, Arg1, lastCyberword(Arg0)); }
	void test_case_2() { string Arg0 = "if then{}; elseif schmelshif();"; string Arg1 = "schmelshif"; verify_case(2, Arg1, lastCyberword(Arg0)); }
	void test_case_3() { string Arg0 = "~y?"; string Arg1 = "y"; verify_case(3, Arg1, lastCyberword(Arg0)); }
	void test_case_4() { string Arg0 = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"; string Arg1 = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"; verify_case(4, Arg1, lastCyberword(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
	Cyberline ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
