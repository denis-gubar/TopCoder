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
// BEGIN CUT HERE 
#include <Windows.h>
#pragma comment( lib, "Winmm" )
// END CUT HERE 
typedef long long lint;
typedef vector<int> vi;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
struct QueenInterference
{
	int _a;
	int a()
	{
		if ( _a < 0 ) return _a = 1;
		return _a = ( (lint) 16807 * _a ) % 2147483647;
	}
	int rand( int up )
	{
		return a() % up;
	}
	int calc( int x1, int y1, int x2, int y2 )
	{
		return x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2);
	}
	int numSteps( int n )
	{
		int result = 0;
		_a = -1;
		vi M(n);
		fora(i, M)
			M[i] = rand(n);
		while( true )
		{
			vi T;
			fora(i, M)
			{
				bool flag = false;
				fora(j, M)
					flag |= i != j && calc( i, M[i], j, M[j] );
				if ( flag )
					T.push_back( i );
			}
			if ( T.empty() ) break;
			int K = T[rand(T.size())];
			vi C(n, 0);
			fora(j, M)
				fora(k, C)
					C[k] += calc( K, k, j, M[j] );
			int m = *min_element( all(C) );
			vi P;
			fora(k, C)
				if ( C[k] == m )
					P.push_back( k );
			if ( P.size() == 1 ) M[K] = P[0];
			else M[K] = P[rand(P.size())];
			result++;
		}
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; verify_case(0, Arg1, numSteps(Arg0)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 6; verify_case(1, Arg1, numSteps(Arg0)); }
	void test_case_2() { int Arg0 = 19; int Arg1 = 475; verify_case(2, Arg1, numSteps(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	QueenInterference ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
