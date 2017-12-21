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

class DNASingleMatcher
{ 
public:
	 int longestMatch( string sequence1, string sequence2 )
	{
		for( int k = min(sequence1.size(), sequence2.size()); k > 0; k-- )
			for( int i = 0; i + k <= sequence1.size(); i++ )
				if ( sequence2.find( sequence1.substr( i, k ) ) != -1 )
					return k;
		return 0;
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAACCCGGGGGGGGGGGGG"; string Arg1 = "AAAACCCGGGGGGGGGGGGGGGGTTTTTTTTTGGGGGGGGGGGG"; int Arg2 = 20; verify_case(0, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "CAT"; string Arg1 = "AT"; int Arg2 = 2; verify_case(1, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "TCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTC"; string Arg1 = "GAGAGGAGAAAGAGAGAGAAGAGAGGAGGAAAGAGAGAGAAAAGAGGGAA"; int Arg2 = 0; verify_case(2, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC"; string Arg1 = "GTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGT"; int Arg2 = 48; verify_case(3, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "TC"; string Arg1 = "CATCAT"; int Arg2 = 2; verify_case(4, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "CGCATTAGATTCAGAG"; string Arg1 = "CGCATGAGTAGATTC"; int Arg2 = 7; verify_case(5, Arg2, longestMatch(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
	DNASingleMatcher ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
