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
struct ComplexIntegers
{
	bool isPrime( int x )
	{
		if ( x == 1 ) return false;
		if ( x == 2 ) return true;
		if ( x % 2 == 0 ) return false;
		for( int i = 3; i * i <= x; i += 2 )
			if ( x % i == 0 ) return false;
		return true;
	}
	vector <string> classify( vector <int> realPart, vector <int> imaginaryPart )
	{
		vector <string> result(realPart.size());
		fora(i, result)
		{
			int z = realPart[i] * realPart[i] + imaginaryPart[i] * imaginaryPart[i];
			if ( z == 0 )
			{
				result[i] = "zero";
				continue;
			}
			if ( z == 1 )
			{
				result[i] = "unit";
				continue;
			}
			if ( !realPart[i] || !imaginaryPart[i] )
			{
				int p = abs(realPart[i] + imaginaryPart[i]);
				if ( p % 4 == 3 && isPrime(p) )
				{
					result[i] = "prime";
					continue;
				}
				result[i] = "composite";
				continue;
			}
			result[i] = isPrime(z) ? "prime" : "composite";
		}
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 0,     1,       0,     1,       -1,      2,           0,       0,          -3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,     0,      -1,     1,        1,      0,          -3,       5,          -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "zero",  "unit",  "unit",  "prime",  "prime",  "composite",  "prime",  "composite",  "prime" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, classify(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "composite",  "prime",  "composite",  "prime",  "prime",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "composite",  "prime",  "composite" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, classify(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,0,0,0,0,0,-19,23,29,31,37,-41}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,2,-3,5,-7,11,-13,17,0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "composite",  "composite",  "prime",  "composite",  "prime",  "prime",  "composite",  "composite",  "zero",  "prime",  "prime",  "composite",  "prime",  "composite",  "composite" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, classify(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {99,-39,0,0,97,1003,9998,1119}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,35,-129,-2,-232,9997,1120}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "prime",  "prime" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, classify(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,  0,0,1,-1,   1,1,-1,-1,   2,-2,0,0,  1,1,2,2,-1,-1,-2,-2, 
     3,-3,0,0,   1,1,3,3,-1,-1,-3,-3,    2,2,-2,-2,  0,0,4,-4,
                 1,1,4,4,-1,-1,-4,-4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,  1,-1,0,0,   1,-1,1,-1,   0,0,2,-2,  2,-2,1,-1,2,-2,1,-1,  
     0,0,-3,3,   3,-3,1,-1,3,-3,1,-1,     2,-2,2,-2,  4,-4,0,0,
                 4,-4,1,-1,4,-4,1,-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "zero",  "unit",  "unit",  "unit",  "unit",  "prime",  "prime",  "prime",  "prime",  "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, classify(Arg0, Arg1)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ComplexIntegers ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
