#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
template<typename T> string ToString( T x )
{
    ostringstream S;
	S << x;
	return S.str();
}
struct UnLinker
{
	string clean( string text )
	{
		string result;
		int n = text.size(), count = 0;
		fora(i, text)
		{
			int j = i;
			if ( i + 4 <= n && text.substr(i, 4) == "www." ) j = i + 4;
			else if ( i + 7 <= n && text.substr(i, 7) == "http://" ) j = i + 7;
			if ( j > i )
			{
				for( int k = j; k < n; k++ )
				{
					if ( text[k] == ' ' || text[k] == ',' || text[k] == '/' || text[k] == ':' ) break;
					if ( k > j && k + 4 <= n && text.substr(k, 4) == ".com" ) i = k + 3;
					if ( k > j && k + 4 <= n && text.substr(k, 4) == ".org" ) i = k + 3;
					if ( k > j && k + 4 <= n && text.substr(k, 4) == ".edu" ) i = k + 3;
					if ( k > j && k + 5 <= n && text.substr(k, 5) == ".info" ) i = k + 4;
					if ( k > j && k + 3 <= n && text.substr(k, 3) == ".tv" ) i = k + 2;
				}
				if ( i > j )
				{
					result += "OMIT" + ToString(++count);
					continue;
				}
			}
			result += text[i];
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "espihttp://www.tv.org.superwww.cali.comaladocious"; string Arg1 = "espiOMIT1aladocious"; verify_case(0, Arg1, clean(Arg0)); }
	void test_case_1() { string Arg0 = "check www.foo.com 4 www.foo.com www.scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2 OMIT3"; verify_case(1, Arg1, clean(Arg0)); }
	void test_case_2() { string Arg0 = "check www.foo.com 4 www.foo.comwww.scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2"; verify_case(2, Arg1, clean(Arg0)); }
	void test_case_3() { string Arg0 = "check www.foo.com 4 www.foo.comhttp://scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2OMIT3"; verify_case(3, Arg1, clean(Arg0)); }
	void test_case_4() { string Arg0 = "http://411.com goodz 4 www.733t.com, 2http://..com"; string Arg1 = "OMIT1 goodz 4 OMIT2, 2OMIT3"; verify_case(4, Arg1, clean(Arg0)); }
	void test_case_5() { string Arg0 = "http.//say.org,www.jeeves.x.info,www.comhttp://.tv"; string Arg1 = "http.//say.org,OMIT1,www.comhttp://.tv"; verify_case(5, Arg1, clean(Arg0)); }
	void test_case_6() { string Arg0 = "http://www.www.com/www"; string Arg1 = "OMIT1/www"; verify_case(6, Arg1, clean(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	UnLinker ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
