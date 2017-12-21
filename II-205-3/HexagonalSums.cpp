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
typedef vector<int> vi;
struct HexagonalSums
{
	int minLength( int N )
	{
    	int result;
		vi A;
		int k = 0;
		for( int i = 1; k < N; i++ )
		{
			k = k + 4 * i - 3;	
			A.push_back( k );
		}
		if ( k == N ) return 1;
		if ( N <= 26 )
		for( int i1 = 0; i1 < A.size(); i1++ )
			for( int i2 = i1; i2 < A.size(); i2++ )
				if ( A[i1] + A[i2] < N )
					for( int i3 = i2; i3 < A.size(); i3++ )
						if ( A[i1] + A[i2] + A[i3] < N )
							for( int i4 = i3; i4 < A.size(); i4++ )
								if ( A[i1] + A[i2] + A[i3] + A[i4] < N )
									for( int i5 = i4; i5 < A.size(); i5++ )
										if ( A[i1] + A[i2] + A[i3] + A[i4] + A[i5] < N )
											for( int i6 = i5; i6 < A.size(); i6++ )
												if ( A[i1] + A[i2] + A[i3] + A[i4] + A[i5] + A[i6] == N ) result = 6;
		if ( N <= 130 )
		for( int i1 = 0; i1 < A.size(); i1++ )
			for( int i2 = i1; i2 < A.size(); i2++ )
				if ( A[i1] + A[i2] < N )
					for( int i3 = i2; i3 < A.size(); i3++ )
						if ( A[i1] + A[i2] + A[i3] < N )
							for( int i4 = i3; i4 < A.size(); i4++ )
								if ( A[i1] + A[i2] + A[i3] + A[i4] < N )
									for( int i5 = i4; i5 < A.size(); i5++ )
										if ( A[i1] + A[i2] + A[i3] + A[i4] + A[i5] == N ) result = 5;
		if ( N <= 146858 )
		for( int i1 = 0; i1 < A.size(); i1++ )
			for( int i2 = i1; i2 < A.size(); i2++ )
				if ( A[i1] + A[i2] < N )
					for( int i3 = i2; i3 < A.size(); i3++ )
						if ( A[i1] + A[i2] + A[i3] < N )
							for( int i4 = i3; i4 < A.size(); i4++ )
								if ( A[i1] + A[i2] + A[i3] + A[i4] == N ) result = 4;
		for( int i1 = 0; i1 < A.size(); i1++ )
			for( int i2 = i1; i2 < A.size(); i2++ )
				if ( A[i1] + A[i2] < N )
					for( int i3 = i2; i3 < A.size(); i3++ )
						if ( A[i1] + A[i2] + A[i3] == N ) result = 3;
		for( int i1 = 0; i1 < A.size(); i1++ )
			for( int i2 = i1; i2 < A.size(); i2++ )
				if ( A[i1] + A[i2] == N ) result = 2;
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; int Arg1 = 6; verify_case(0, Arg1, minLength(Arg0)); }
	void test_case_1() { int Arg0 = 130; int Arg1 = 5; verify_case(1, Arg1, minLength(Arg0)); }
	void test_case_2() { int Arg0 = 146858; int Arg1 = 4; verify_case(2, Arg1, minLength(Arg0)); }
	void test_case_3() { int Arg0 = 999999; int Arg1 = 3; verify_case(3, Arg1, minLength(Arg0)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 2; verify_case(4, Arg1, minLength(Arg0)); }
	void test_case_5() { int Arg0 = 145530; int Arg1 = 1; verify_case(5, Arg1, minLength(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	HexagonalSums ___test; 
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
