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
typedef vector<string> vs;
#define all(v) (v).begin(), (v).end()
struct comp: binary_function<string, string, bool>
{
	bool operator() ( string a, string b ) const
	{
		transform( all(a), a.begin(), ::tolower );
		transform( all(b), b.begin(), ::tolower );
		a.erase( remove_if( all(a), bind2nd( equal_to<char>(), ' ' ) ), a.end() );
		b.erase( remove_if( all(b), bind2nd( equal_to<char>(), ' ' ) ), b.end() );
		sort( all(a) ); sort( all(b) );
		return a == b;
	}
};
struct Aaagmnrs
{
	vector <string> anagrams( vector <string> phrases )
	{
		vector <string> result;
		for( vs::iterator it = phrases.begin(); it != phrases.end(); ++it )
			if ( find_if( phrases.begin(), it, bind2nd( comp(), *it ) ) == it )
				result.push_back( *it );
		return result;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "Aaagmnrs", "TopCoder", "anagrams", "Drop Cote" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Aaagmnrs",  "TopCoder" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, anagrams(Arg0)); }
	void test_case_1() { string Arr0[] = { "SnapDragon vs tomek", "savants groped monk", "Adam vents prongs ok" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "SnapDragon vs tomek" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, anagrams(Arg0)); }
	void test_case_2() { string Arr0[] = { "Radar ghost jilts Kim", "patched hers first",
  "DEPTH FIRST SEARCH", "DIJKSTRAS ALGORITHM" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Radar ghost jilts Kim",  "patched hers first" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, anagrams(Arg0)); }
// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	DWORD start, finish;
	start = timeGetTime();
	Aaagmnrs ___test; 
	___test.run_test(-1); 
	finish = timeGetTime();
	cout << endl << "Elapsed " << finish - start << " msec" << endl;
} 
// END CUT HERE 
