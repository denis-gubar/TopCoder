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
#ifdef __GNUC__
#else
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
template<typename T>
void print( T collection, char* separator = "\n" )
{
	copy( collection.begin(), collection.end(), ostream_iterator<T::value_type>( cout, separator ) );
	cout << endl;
}
// END CUT HERE 
#endif
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
struct DiskScheduler
{
public:
	int optimize( int start, vector <int> sectors )
	{
		int result = 10000;
		sectors.push_back( start );
		sort( all(sectors) );
		vi M;
		copy( all(sectors), back_inserter( M ) );
		copy( all(sectors), back_inserter( M ) );
		copy( all(sectors), back_inserter( M ) );
		int x = distance( M.begin(), find( M.begin() + sectors.size(), M.end(), start ) );
		for( int i = x; i > x - sectors.size(); i-- )
		{
			int current = 0, last = start;
			for( int j = x; j >= i; j-- )
			{
				int a = (100 + M[j] - last) % 100;
				current += min( a, 100 - a );
				last = M[j];
			}
			for( int j = x + 1; j < i + sectors.size(); j++ )
			{
				int a = (100 + M[j] - last) % 100;
				current += min( a, 100 - a );
				last = M[j];
			}
			result = min( result, current );
			current = 0, last = start;
			for( int j = x; j < i + sectors.size(); j++ )
			{
				int a = (100 + M[j] - last) % 100;
				current += min( a, 100 - a );
				last = M[j];
			}
			for( int j = x - 1; j >= i; j-- )
			{
				int a = (100 + M[j] - last) % 100;
				current += min( a, 100 - a );
				last = M[j];
			}
			result = min( result, current );
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {6,8,65,71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; verify_case(0, Arg2, optimize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {55,65,71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; verify_case(1, Arg2, optimize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1,21,99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(2, Arg2, optimize(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99; int Arr1[] = {55,56,61,70,76,78,80,83,84,90,1,4,6,26,27,33,38,46,47,49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 87; verify_case(3, Arg2, optimize(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	DiskScheduler ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
