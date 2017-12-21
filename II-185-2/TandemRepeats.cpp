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
struct TandemRepeats
{
public:
	int maxLength( string dna, int k )
	{
		for( int i = dna.size() / 2; i > 0; i-- )
			for( int j = 0; j + 2 * i <= dna.size(); j++ )
			{
				int count = 0;
				for( int z = 0; z < i; z++ )
					if ( dna[j + z] != dna[j + i + z] )
						count++;
				if ( count <= k ) return i;
			}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "GATCATCA"; int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GATCATGA"; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "GATCATGA"; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AGAGAAAGAA"; int Arg1 = 3; int Arg2 = 5; verify_case(3, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ATTAGCATTGCACACCTTGAGGACTTAGACAAACCTAGTACACAGGTGTA"; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, maxLength(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TandemRepeats ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
