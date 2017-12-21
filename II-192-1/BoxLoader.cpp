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
struct BoxLoader
{
public:
	int mostItems( int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ )
	{
		int A[] = {boxX, boxY, boxZ};
		int B[] = {itemX, itemY, itemZ};
		vi C; C.push_back( 0 ); C.push_back( 1 ); C.push_back( 2 );
		int result = (A[C[0]] / B[0]) * (A[C[1]] / B[1]) * (A[C[2]] / B[2]);
		while( next_permutation( all(C) ) )
			result = max(result, (A[C[0]] / B[0]) * (A[C[1]] / B[1]) * (A[C[2]] / B[2]) );
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 98; int Arg2 = 81; int Arg3 = 3; int Arg4 = 5; int Arg5 = 7; int Arg6 = 7560; verify_case(0, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 9; int Arg4 = 9; int Arg5 = 11; int Arg6 = 0; verify_case(1, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 201; int Arg1 = 101; int Arg2 = 301; int Arg3 = 100; int Arg4 = 30; int Arg5 = 20; int Arg6 = 100; verify_case(2, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 913; int Arg1 = 687; int Arg2 = 783; int Arg3 = 109; int Arg4 = 93; int Arg5 = 53; int Arg6 = 833; verify_case(3, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 4; int Arg3 = 3; int Arg4 = 2; int Arg5 = 1; int Arg6 = 20; verify_case(4, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	BoxLoader ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
