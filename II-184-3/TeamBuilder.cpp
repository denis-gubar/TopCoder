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
typedef vector<bool> vb;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
struct TeamBuilder
{
public:
	vector <int> specialLocations( vector <string> paths )
	{
		vector <int> result(2, 0);
		fora(i, paths)
		{
			queue<int> q;
			vb flag(paths.size(), false);
			q.push( i );
			flag[i] = true;
			int count = paths.size() - 1;
			while( !q.empty() )
			{
				int k = q.front(); q.pop();
				fora(j, paths)
					if ( !flag[j] && paths[k][j] == '1' )
					{
						q.push( j );
						flag[j] = true;
						count--;
					}
			}
			if ( count == 0 ) result[0]++;
		}
		fora(i, paths)
		{
			queue<int> q;
			vb flag(paths.size(), false);
			q.push( i );
			flag[i] = true;
			int count = paths.size() - 1;
			while( !q.empty() )
			{
				int k = q.front(); q.pop();
				fora(j, paths)
					if ( !flag[j] && paths[j][k] == '1' )
					{
						q.push( j );
						flag[j] = true;
						count--;
					}
			}
			if ( count == 0 ) result[1]++;
		}
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"010","000","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, specialLocations(Arg0)); }
	void test_case_1() { string Arr0[] = {"0010","1000","1100","1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, specialLocations(Arg0)); }
	void test_case_2() { string Arr0[] = {"01000","00100","00010","00001","10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, specialLocations(Arg0)); }
	void test_case_3() { string Arr0[] = {"0110000","1000100","0000001","0010000","0110000","1000010","0001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, specialLocations(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	TeamBuilder ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
