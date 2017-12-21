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
typedef vector<lint> vl;
struct EngineersPrimes
{
public:
	vl primes;
	int count;
	void isPrime( lint x )
	{
		lint s = sqrt(double(x)) + 1;
		for( int i = 0; i < count && primes[i] < s; i++ )
			if ( !(x % primes[i]) ) return;
		primes[count++] = x;
	}
	lint smallestNonPrime( int N )
	{
		primes = vl( N + 1 ); count = 1;
		primes[0] = 2;
		int x = 3;
		while( count < N + 1 )
		{
			isPrime( x );
			x += 2;
		}
		return primes[N] * primes[N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 49LL; verify_case(0, Arg1, smallestNonPrime(Arg0)); }
	void test_case_1() { int Arg0 = 1; long long Arg1 = 9LL; verify_case(1, Arg1, smallestNonPrime(Arg0)); }
	void test_case_2() { int Arg0 = 265; long long Arg1 = 2886601LL; verify_case(2, Arg1, smallestNonPrime(Arg0)); }
	void test_case_3() { int Arg0 = 1835; long long Arg1 = 247716121LL; verify_case(3, Arg1, smallestNonPrime(Arg0)); }
	void test_case_4() { int Arg0 = 10000; long long Arg1 = 10971096049LL; verify_case(4, Arg1, smallestNonPrime(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	EngineersPrimes ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
