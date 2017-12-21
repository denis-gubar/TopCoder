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

class ParallelSpeedup
{ 
public:
	int numProcessors( int k, int overhead )
	{
		int result = 1;
		int min = k;
		for( int i = 2; i < 1000; i++ )
		{
			if ( min > (k - 1) / i + 1 + overhead * i * (i - 1) / 2 )
			{
				min = (k - 1) / i + 1 + overhead * i * (i - 1) / 2;
				result = i;
			}
		}
		return result;
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 50; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 10; int Arg2 = 1; verify_case(2, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3333; int Arg1 = 2; int Arg2 = 12; verify_case(3, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 4; int Arg2 = 63; verify_case(4, Arg2, numProcessors(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
	ParallelSpeedup ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
