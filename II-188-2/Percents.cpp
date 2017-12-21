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
#include <utility>
using namespace std;
#ifdef __GNUC__
typedef long long lint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template <typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
int toInt( string a )
{
	int result;
	istringstream S( a );
	S >> result;
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
struct Percents
{
public:
	int minSamples( string percent )
	{
		int n = toInt( replace_all(replace_all( percent, "%", "" ), ".", "" ) );
		if ( n == 0 ) return 1;
		for( lint i = 1; i <= 10000; i++ )
		{
			for( lint j = i; j <= 10000; j++ )
				if ( (20000 * i / j + 1) / 2 == n ) return j;
		}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "25.00%"; int Arg1 = 4; verify_case(0, Arg1, minSamples(Arg0)); }
	void test_case_1() { string Arg0 = "66.67%"; int Arg1 = 3; verify_case(1, Arg1, minSamples(Arg0)); }
	void test_case_2() { string Arg0 = "66.66%"; int Arg1 = 2858; verify_case(2, Arg1, minSamples(Arg0)); }
	void test_case_3() { string Arg0 = "71.43%"; int Arg1 = 7; verify_case(3, Arg1, minSamples(Arg0)); }
	void test_case_4() { string Arg0 = "00.00%"; int Arg1 = 1; verify_case(4, Arg1, minSamples(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Percents ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
