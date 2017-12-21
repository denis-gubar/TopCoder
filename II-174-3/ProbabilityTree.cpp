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
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
int toInt( string a )
{
	int result;
	istringstream S( a );
	S >> result;
	return result;
}
vs Split( string s, string c = " " )
{
	vs result;
	string t = "";
	fora(i, s)
		if ( c.find( s[i] ) != -1 )
		{
			result.push_back( t );
			t = "";
		}
		else
			t += s[i];
	result.push_back( t );
	return result;
}
vi SplitInt( string s, string c = " " )
{
	vs temp = Split( s, c );
	vi result( temp.size() );
	transform( temp.begin(), temp.end(), result.begin(), toInt );
	return result;
}
struct ProbabilityTree
{
public:
	vector <int> getOdds( vector <string> tree, int lowerBound, int upperBound )
	{
		vi result;
		vb flag(tree.size(), false);
		vd probs(tree.size(), 0);
		probs[0] = toInt(tree[0]) * 0.01;
		flag[0] = true;		
		for( int left = tree.size() - 1; left > 0; left-- )
		{
			int i;
			for( i = 0; flag[i] || !flag[SplitInt(tree[i])[0]]; i++ );
			vi x = SplitInt(tree[i]);
			double p = probs[x[0]], p1 = x[1] * 0.01, p2 = x[2] * 0.01;
			probs[i] = p * p1 + (1 - p) * p2;
			flag[i] = true;
		}
		fora(i, probs)
			if ( lowerBound < probs[i] * 100 && probs[i] * 100 < upperBound )
				result.push_back( i );
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"40","0 70 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 50; int Arr3[] = { 0,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"20","2 50 50","0 50 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; int Arg2 = 51; int Arr3[] = { 1,  2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"10","0 99 41","1 40 3","2 91 43"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 81; int Arg2 = 88; vector <int> Arg3; verify_case(2, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"79","0 64 52","1 70 87","0 38 99","1 24 8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 81; int Arr3[] = { 0,  1,  2,  3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"51",
 "29 58 3",
 "6 56 86",
 "18 97 1",
 "44 99 25",
 "33 69 90",
 "27 67 49",
 "32 15 19",
 "33 1 21",
 "45 12 33",
 "29 24 40",
 "45 86 74",
 "40 30 65",
 "0 18 27",
 "1 90 65",
 "0 47 62",
 "40 81 72",
 "42 25 56",
 "45 16 81",
 "8 94 92",
 "29 41 92",
 "24 4 29",
 "32 56 91",
 "20 16 77",
 "1 35 79",
 "45 77 61",
 "6 50 19",
 "20 69 43",
 "4 6 16",
 "15 55 26",
 "42 73 90",
 "40 8 49",
 "33 16 33",
 "15 95 47",
 "9 66 40",
 "25 80 39",
 "35 72 70",
 "27 10 36",
 "40 36 10",
 "32 2 48",
 "33 44 23",
 "22 51 45",
 "25 8 43",
 "18 32 96",
 "45 41 74",
 "0 51 6",
 "18 48 15"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 82; int Arr3[] = { 0,  1,  2,  3,  4,  5,  6,  7,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  20,  21,  23,  24,  25,  26,  27,  28,  29,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getOdds(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	ProbabilityTree ___test;
	___test.run_test(-1);
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
}
// END CUT HERE
